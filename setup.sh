#!/bin/bash

# Setup script for CPP Exercise Collection
# This script prepares the environment and tests the runner scripts

echo "========================================="
echo "CPP Exercise Collection Setup"
echo "========================================="
echo ""

# Check if we're in the right directory
if [ ! -f "cpp" ] || [ ! -f "cpp.py" ]; then
    echo "❌ Error: Please run this script from the CPP directory"
    echo "   Make sure you have both 'cpp' and 'cpp.py' files"
    exit 1
fi

echo "✅ Found runner scripts"

# Make scripts executable
echo "🔧 Making scripts executable..."
chmod +x cpp
chmod +x cpp.py

echo "✅ Scripts are now executable"

# Check for required tools
echo ""
echo "🔍 Checking system requirements..."

# Check for C++ compiler
if command -v c++ >/dev/null 2>&1; then
    echo "✅ C++ compiler found: $(c++ --version | head -1)"
else
    echo "❌ C++ compiler not found. Please install g++ or clang++"
    exit 1
fi

# Check for make
if command -v make >/dev/null 2>&1; then
    echo "✅ Make found: $(make --version | head -1)"
else
    echo "❌ Make not found. Please install make"
    exit 1
fi

# Check for Python (optional)
if command -v python3 >/dev/null 2>&1; then
    echo "✅ Python3 found: $(python3 --version)"
else
    echo "⚠️  Python3 not found. The Python runner won't work, but bash runner will."
fi

echo ""
echo "🧪 Testing runner scripts..."

# Test bash script
echo "Testing bash runner..."
if ./cpp 00 00 "test" >/dev/null 2>&1; then
    echo "✅ Bash runner works correctly"
else
    echo "❌ Bash runner test failed"
fi

# Test Python script (if Python is available)
if command -v python3 >/dev/null 2>&1; then
    echo "Testing Python runner..."
    if python3 cpp.py 00 00 "test" >/dev/null 2>&1; then
        echo "✅ Python runner works correctly"
    else
        echo "❌ Python runner test failed"
    fi
fi

echo ""
echo "========================================="
echo "Setup Complete! 🎉"
echo "========================================="
echo ""
echo "You can now run exercises using:"
echo "  ./cpp <module> <exercise> [args...]"
echo "  python3 cpp.py <module> <exercise> [args...]"
echo ""
echo "Examples:"
echo "  ./cpp 00 01                    # Run phonebook"
echo "  ./cpp 01 04 input.txt output   # Run sed with files"
echo "  ./cpp 04 03                    # Run materia system"
echo ""
echo "For help and available exercises:"
echo "  ./cpp"
echo ""
echo "Happy coding! 🚀"
