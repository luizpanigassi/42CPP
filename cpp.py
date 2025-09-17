#!/usr/bin/env python3
"""
CPP Exercise Runner (Python Version)
Usage: python3 cpp.py <module_number> <exercise_number> [args...]
Example: python3 cpp.py 00 01
Example: python3 cpp.py 04 03 some_arguments
"""

import os
import sys
import subprocess
import glob
from pathlib import Path

# ANSI color codes
class Colors:
    RED = '\033[0;31m'
    GREEN = '\033[0;32m'
    YELLOW = '\033[1;33m'
    BLUE = '\033[0;34m'
    PURPLE = '\033[0;35m'
    CYAN = '\033[0;36m'
    NC = '\033[0m'  # No Color

def print_colored(color, prefix, message):
    """Print a colored message with a prefix."""
    print(f"{color}[{prefix}]{Colors.NC} {message}")

def print_info(message):
    print_colored(Colors.BLUE, "INFO", message)

def print_success(message):
    print_colored(Colors.GREEN, "SUCCESS", message)

def print_warning(message):
    print_colored(Colors.YELLOW, "WARNING", message)

def print_error(message):
    print_colored(Colors.RED, "ERROR", message)

def show_usage():
    """Display usage information and available exercises."""
    print("CPP Exercise Runner (Python Version)")
    print()
    print(f"Usage: {sys.argv[0]} <module_number> <exercise_number> [args...]")
    print()
    print("Examples:")
    print(f"  {sys.argv[0]} 00 01                # Run cpp00/ex01")
    print(f"  {sys.argv[0]} 04 03                # Run cpp04/ex03")
    print(f"  {sys.argv[0]} 01 04 file.txt out   # Run cpp01/ex04 with arguments")
    print()
    print("Available modules and exercises:")

    # Find all cpp modules
    cpp_dirs = sorted(glob.glob("cpp*/"))
    for cpp_dir in cpp_dirs:
        if os.path.isdir(cpp_dir):
            module_name = os.path.basename(cpp_dir.rstrip('/'))
            ex_dirs = sorted(glob.glob(f"{cpp_dir}/ex*/"))
            exercises = []
            for ex_dir in ex_dirs:
                if os.path.isdir(ex_dir):
                    ex_name = os.path.basename(ex_dir.rstrip('/')).replace('ex', '')
                    exercises.append(ex_name)
            if exercises:
                print(f"  {module_name}: {' '.join(exercises)}")

def format_number(num_str):
    """Format number with leading zero if needed."""
    try:
        num = int(num_str)
        return f"{num:02d}"
    except ValueError:
        return num_str

def get_executable_name(makefile_path):
    """Extract executable name from Makefile."""
    try:
        with open(makefile_path, 'r') as f:
            for line in f:
                line = line.strip()
                if line.startswith('NAME') and '=' in line:
                    name = line.split('=', 1)[1].strip()
                    return name
    except Exception as e:
        print_error(f"Error reading Makefile: {e}")
    return None

def run_command(command, cwd=None, show_output=True):
    """Run a shell command and return success status."""
    try:
        if show_output:
            result = subprocess.run(command, shell=True, cwd=cwd, check=True)
        else:
            result = subprocess.run(command, shell=True, cwd=cwd, check=True,
                                  stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return True
    except subprocess.CalledProcessError:
        return False

def main():
    # Check arguments
    if len(sys.argv) < 3:
        print_error("Not enough arguments provided")
        print()
        show_usage()
        sys.exit(1)

    # Parse arguments
    module_num = format_number(sys.argv[1])
    exercise_num = format_number(sys.argv[2])
    additional_args = sys.argv[3:] if len(sys.argv) > 3 else []

    # Build paths
    module_dir = f"cpp{module_num}"
    exercise_dir = f"{module_dir}/ex{exercise_num}"

    # Validate directories
    if not os.path.isdir(module_dir):
        print_error(f"Module directory '{module_dir}' does not exist")
        print()
        show_usage()
        sys.exit(1)

    if not os.path.isdir(exercise_dir):
        print_error(f"Exercise directory '{exercise_dir}' does not exist")
        print()
        show_usage()
        sys.exit(1)

    # Check for Makefile
    makefile_path = os.path.join(exercise_dir, "Makefile")
    if not os.path.isfile(makefile_path):
        print_error(f"Makefile not found in '{exercise_dir}'")
        sys.exit(1)

    print_info(f"Running {module_dir} exercise {exercise_num}...")

    # Save current directory
    original_dir = os.getcwd()

    try:
        # Change to exercise directory
        os.chdir(exercise_dir)

        # Clean previous builds
        print_info("Cleaning previous builds...")
        run_command("make fclean", show_output=False)

        # Build the exercise
        print_info("Building exercise...")
        if not run_command("make", show_output=False):
            print_error("Build failed")
            run_command("make")  # Show the error
            sys.exit(1)

        print_success("Build successful")

        # Get executable name
        executable = get_executable_name("Makefile")
        if not executable:
            print_error("Could not determine executable name from Makefile")
            sys.exit(1)

        # Check if executable exists
        if not os.path.isfile(executable):
            print_error(f"Executable '{executable}' not found after build")
            sys.exit(1)

        # Run the executable
        cmd_args = " ".join([f'"{arg}"' for arg in additional_args])
        print_info(f"Running './{executable}' with arguments: {cmd_args}")
        print()
        print("========== PROGRAM OUTPUT ==========")

        # Run with arguments
        cmd = [f"./{executable}"] + additional_args
        result = subprocess.run(cmd)
        print("")
        print("====================================")
        print()

        if result.returncode == 0:
            print_success("Program completed successfully")
        else:
            print_warning(f"Program exited with code {result.returncode}")

        # Clean up
        print_info("Cleaning up...")
        run_command("make fclean", show_output=False)

    except Exception as e:
        print_error(f"An error occurred: {e}")
        sys.exit(1)

    finally:
        # Return to original directory
        os.chdir(original_dir)

    print_success("Done!")

if __name__ == "__main__":
    main()
