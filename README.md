# CPP Exercise Collection

This repository contains all CPP exercises organized in a single, easy-to-navigate structure with a custom runner script.

## Project Structure

```
CPP/
├── cpp                    # Main runner script
├── cpp.py                 # Python alternative runner
├── README.md             # This file
├── cpp00/                # Module 00 exercises
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp01/                # Module 01 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   ├── ex03/
│   ├── ex04/
│   ├── ex05/
│   └── ex06/
├── cpp02/                # Module 02 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── ex03/
├── cpp03/                # Module 03 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── ex03/
├── cpp04/                # Module 04 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── ex03/
└── cpp05-09/             # Future modules (to be added)
```

## Quick Setup

After cloning this repository:

```bash
# Make scripts executable and test the setup
./setup.sh

# Or manually:
chmod +x cpp cpp.py setup.sh
```

## Usage

### Quick Start

The main runner script allows you to compile and run any exercise with a simple command:

```bash
# Basic syntax
./cpp <module_number> <exercise_number> [arguments...]

# Examples
./cpp 00 01                    # Run cpp00/ex01
./cpp 04 03                    # Run cpp04/ex03
./cpp 1 4 input.txt output     # Run cpp01/ex04 with arguments
```

### Available Commands

```bash
# Show help and list all available exercises
./cpp

# Run specific exercises
./cpp 00 00                    # megaphone
./cpp 00 01                    # phonebook
./cpp 01 00                    # zombies
./cpp 01 04 file.txt result    # sed replacement with arguments
./cpp 04 03                    # materia system
```

## Features

- **Automatic Building**: Each exercise is compiled automatically using its Makefile
- **Clean Builds**: Previous builds are cleaned before compilation
- **Argument Passing**: Pass arguments directly to the exercises that need them
- **Error Handling**: Clear error messages and build failure reporting
- **Colorized Output**: Easy-to-read colored terminal output
- **Automatic Cleanup**: Binaries are cleaned up after execution
- **Smart Formatting**: Accepts both single digits (1) and zero-padded (01) numbers

## Exercise Descriptions

### CPP00 - Introduction to C++
- **ex00**: Megaphone - String manipulation and basic I/O
- **ex01**: Phonebook - Classes, objects, and basic data structures
- **ex02**: Account - Class design and encapsulation

### CPP01 - Memory, References, and Pointers
- **ex00**: BraiiiiiiinnnzzzZ - Memory allocation and object lifecycle
- **ex01**: Moar brainz! - Dynamic arrays and memory management
- **ex02**: HI THIS IS BRAIN - References vs pointers
- **ex03**: Unnecessary violence - Object composition and references
- **ex04**: Sed is for losers - File I/O and string replacement
- **ex05**: Harl 2.0 - Function pointers and switch alternatives
- **ex06**: Harl filter - Filtering and logging levels

### CPP02 - Polymorphism and Operator Overloading
- **ex00**: Fixed point numbers - Basic class design
- **ex01**: Towards a more useful fixed point class - Operator overloading
- **ex02**: Now we're talking - Arithmetic operators and comparisons
- **ex03**: BSP - Binary Space Partitioning with fixed point arithmetic

### CPP03 - Inheritance
- **ex00**: Aaaaand... OPEN! - Basic inheritance with ClapTrap
- **ex01**: Serena, my love! - Derived classes with ScavTrap
- **ex02**: Repetitive work - Multiple inheritance with FragTrap
- **ex03**: Now it's weird! - Diamond problem and virtual inheritance

### CPP04 - Subtype Polymorphism and Abstract Classes
- **ex00**: Polymorphism - Virtual functions and base classes
- **ex01**: I don't want to set the world on fire - Deep copy and brain class
- **ex02**: Abstract class - Pure virtual functions
- **ex03**: Interface & recap - Abstract interfaces and materia system

## Development Notes

### Adding New Modules

When adding new CPP modules (cpp05, cpp06, etc.), simply:

1. Create the new directory structure following the existing pattern
2. Ensure each exercise has a proper Makefile with a `NAME` variable
3. The runner script will automatically detect and list new modules

### Makefile Requirements

Each exercise should have a Makefile with:
- A `NAME` variable defining the executable name
- Standard targets: `all`, `clean`, `fclean`
- Proper C++98 compilation flags

### Example Makefile Template

```makefile
NAME = executable_name
SRC = main.cpp other_files.cpp
HPP = header_files.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

all: $(NAME)

$(NAME): $(SRC) $(HPP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
```

## Contributing

When adding new exercises:

1. Follow the existing directory structure
2. Include proper Makefiles
3. Add exercise descriptions to this README
4. Test with the runner script

## Future Modules

- **cpp05**: Exceptions
- **cpp06**: C++ Casts
- **cpp07**: Templates
- **cpp08**: STL Containers
- **cpp09**: STL Algorithms

---

*This collection represents a comprehensive journey through C++ fundamentals, from basic syntax to advanced object-oriented programming concepts.*
