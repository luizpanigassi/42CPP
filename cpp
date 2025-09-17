#!/bin/bash

# CPP Exercise Runner
# Usage: ./cpp <module_number> <exercise_number> [args...]
# Example: ./cpp 00 01
# Example: ./cpp 04 03 some_arguments

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to show usage
show_usage() {
    echo "CPP Exercise Runner"
    echo ""
    echo "Usage: $0 <module_number> <exercise_number> [args...]"
    echo ""
    echo "Examples:"
    echo "  $0 00 01                # Run cpp00/ex01"
    echo "  $0 04 03                # Run cpp04/ex03"
    echo "  $0 01 04 file.txt out   # Run cpp01/ex04 with arguments"
    echo ""
    echo "Available modules and exercises:"
    for module_dir in cpp*/; do
        if [ -d "$module_dir" ]; then
            module_name=$(basename "$module_dir")
            echo -n "  $module_name: "
            exercises=()
            for ex_dir in "$module_dir"ex*/; do
                if [ -d "$ex_dir" ]; then
                    ex_name=$(basename "$ex_dir" | sed 's/ex//')
                    exercises+=("$ex_name")
                fi
            done
            echo "${exercises[*]}"
        fi
    done
}

# Check if correct number of arguments
if [ $# -lt 2 ]; then
    print_error "Not enough arguments provided"
    echo ""
    show_usage
    exit 1
fi

# Parse arguments
MODULE_NUM=$1
EXERCISE_NUM=$2
shift 2  # Remove first two arguments, leaving any additional args for the program

# Validate module number format (pad with zero if needed)
if [[ $MODULE_NUM =~ ^[0-9]$ ]]; then
    MODULE_NUM="0$MODULE_NUM"
fi

# Validate exercise number format (pad with zero if needed)
if [[ $EXERCISE_NUM =~ ^[0-9]$ ]]; then
    EXERCISE_NUM="0$EXERCISE_NUM"
fi

# Build paths
MODULE_DIR="cpp$MODULE_NUM"
EXERCISE_DIR="$MODULE_DIR/ex$EXERCISE_NUM"

# Check if module directory exists
if [ ! -d "$MODULE_DIR" ]; then
    print_error "Module directory '$MODULE_DIR' does not exist"
    echo ""
    show_usage
    exit 1
fi

# Check if exercise directory exists
if [ ! -d "$EXERCISE_DIR" ]; then
    print_error "Exercise directory '$EXERCISE_DIR' does not exist"
    echo ""
    show_usage
    exit 1
fi

# Check if Makefile exists
if [ ! -f "$EXERCISE_DIR/Makefile" ]; then
    print_error "Makefile not found in '$EXERCISE_DIR'"
    exit 1
fi

print_info "Running $MODULE_DIR exercise $EXERCISE_NUM..."

# Save current directory
ORIGINAL_DIR=$(pwd)

# Change to exercise directory
cd "$EXERCISE_DIR" || {
    print_error "Failed to change to directory '$EXERCISE_DIR'"
    exit 1
}

# Clean previous builds
print_info "Cleaning previous builds..."
make fclean > /dev/null 2>&1

# Build the exercise
print_info "Building exercise..."
if make > /dev/null 2>&1; then
    print_success "Build successful"
else
    print_error "Build failed"
    make  # Show the error
    cd "$ORIGINAL_DIR"
    exit 1
fi

# Find the executable name from Makefile
EXECUTABLE=$(grep -E "^NAME\s*=" Makefile | head -1 | cut -d'=' -f2 | tr -d ' \t')

if [ -z "$EXECUTABLE" ]; then
    print_error "Could not determine executable name from Makefile"
    cd "$ORIGINAL_DIR"
    exit 1
fi

# Check if executable exists
if [ ! -f "$EXECUTABLE" ]; then
    print_error "Executable '$EXECUTABLE' not found after build"
    cd "$ORIGINAL_DIR"
    exit 1
fi

# Run the executable with any additional arguments
print_info "Running './$EXECUTABLE' with arguments: $*"
echo ""
echo "========== PROGRAM OUTPUT =========="
./"$EXECUTABLE" "$@"
RETURN_CODE=$?
echo ""
echo "===================================="
echo ""

if [ $RETURN_CODE -eq 0 ]; then
    print_success "Program completed successfully"
else
    print_warning "Program exited with code $RETURN_CODE"
fi

# Clean up
print_info "Cleaning up..."
make fclean > /dev/null 2>&1

# Return to original directory
cd "$ORIGINAL_DIR"

print_success "Done!"
