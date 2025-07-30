#!/bin/bash

# SCFG Build Script - Cross-platform Lua compiler
# Supports Linux and Windows with automatic OS detection

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Detect OS
detect_os() {
    case "$(uname -s)" in
        Linux*)     OS=Linux;;
        Darwin*)    OS=Mac;;
        CYGWIN*)    OS=Windows;;
        MINGW*)     OS=Windows;;
        MSYS*)      OS=Windows;;
        *)          OS="UNKNOWN:$(uname -s)"
    esac
    print_status "Detected OS: $OS"
}

# Check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check for Lua development libraries on Linux
check_lua_linux() {
    print_status "Checking for Lua development libraries..."
    
    # Check for common Lua library locations
    LUA_SEARCH_PATHS=(
        "/usr/include/lua5.4"
        "/usr/include/lua5.3"
        "/usr/include/lua5.2"
        "/usr/include/lua5.1"
        "/usr/local/include/lua5.4"
        "/usr/local/include/lua5.3"
        "/usr/local/include/lua5.2"
        "/usr/local/include/lua5.1"
    )
    
    LUA_LIB_SEARCH_PATHS=(
        "/usr/lib/x86_64-linux-gnu/liblua5.4.so"
        "/usr/lib/x86_64-linux-gnu/liblua5.3.so"
        "/usr/lib/x86_64-linux-gnu/liblua5.2.so"
        "/usr/lib/x86_64-linux-gnu/liblua5.1.so"
        "/usr/local/lib/liblua5.4.so"
        "/usr/local/lib/liblua5.3.so"
        "/usr/local/lib/liblua5.2.so"
        "/usr/local/lib/liblua5.1.so"
    )
    
    # Check if pkg-config is available
    if command_exists pkg-config; then
        for lua_version in lua5.4 lua5.3 lua5.2 lua5.1; do
            if pkg-config --exists "$lua_version" 2>/dev/null; then
                LUA_VERSION=$lua_version
                LUA_CFLAGS=$(pkg-config --cflags "$lua_version")
                LUA_LIBS=$(pkg-config --libs "$lua_version")
                print_status "Found Lua via pkg-config: $lua_version"
                return 0
            fi
        done
    fi
    
    # Manual search for headers and libraries
    for path in "${LUA_SEARCH_PATHS[@]}"; do
        if [ -d "$path" ]; then
            LUA_INCLUDE_DIR=$path
            break
        fi
    done
    
    for lib in "${LUA_LIB_SEARCH_PATHS[@]}"; do
        if [ -f "$lib" ]; then
            LUA_LIB=$lib
            LUA_VERSION=$(echo "$lib" | grep -o 'lua[0-9]\.[0-9]')
            break
        fi
    done
    
    if [ -n "$LUA_INCLUDE_DIR" ] && [ -n "$LUA_LIB" ]; then
        print_status "Found Lua headers: $LUA_INCLUDE_DIR"
        print_status "Found Lua library: $LUA_LIB"
        return 0
    fi
    
    return 1
}

# Build for Linux
build_linux() {
    print_status "Building for Linux..."
    
    # Check for required tools
    if ! command_exists g++; then
        print_error "g++ not found. Please install build-essential package:"
        print_error "  sudo apt-get install build-essential"
        exit 1
    fi
    
    # Check for Lua
    if ! check_lua_linux; then
        print_error "Lua development libraries not found!"
        print_error "Please install Lua development package:"
        print_error "  Ubuntu/Debian: sudo apt-get install liblua5.4-dev"
        print_error "  CentOS/RHEL:   sudo yum install lua-devel"
        print_error "  Arch Linux:    sudo pacman -S lua"
        exit 1
    fi
    
    # Build command - include all source files
    BUILD_CMD="g++ ./src/scfg.cpp ./src/localization/LocalizationManager.cpp -I./src/include -I./src/localization"
    
    # Add Lua flags based on detection method
    if [ -n "$LUA_CFLAGS" ] && [ -n "$LUA_LIBS" ]; then
        # Using pkg-config
        BUILD_CMD="$BUILD_CMD $LUA_CFLAGS $LUA_LIBS"
    elif [ -n "$LUA_INCLUDE_DIR" ] && [ -n "$LUA_LIB" ]; then
        # Using manual paths
        BUILD_CMD="$BUILD_CMD -I$LUA_INCLUDE_DIR -L$(dirname "$LUA_LIB") -l${LUA_VERSION//./}"
    else
        # Fallback to system libraries
        BUILD_CMD="$BUILD_CMD -llua5.4"
    fi
    
    BUILD_CMD="$BUILD_CMD -o scfg -std=c++23"
    
    print_status "Building with: $BUILD_CMD"
    
    if eval "$BUILD_CMD"; then
        print_status "Build successful!"
        print_status "Running test..."
        ./scfg test.scfg
    else
        print_error "Build failed!"
        exit 1
    fi
}

# Build for Windows
build_windows() {
    print_status "Building for Windows..."
    
    # Check for available compilers
    if command_exists g++; then
        # MinGW build
        if g++ ./src/scfg.cpp -I./src/include -L./src/ -llua54 -o scfg.exe -std=c++23 -static; then
            print_status "Build successful!"
            print_status "Running test..."
            ./scfg.exe test.scfg
        else
            print_error "Build failed with MinGW!"
            exit 1
        fi
    elif command_exists cl; then
        # MSVC build
        print_status "MSVC detected, but not fully supported in this script"
        print_status "Please use Visual Studio or adapt the build command"
        exit 1
    else
        print_error "No suitable compiler found for Windows!"
        print_error "Please install MinGW or Visual Studio"
        exit 1
    fi
}

# Main build process
main() {
    print_status "Starting SCFG build process..."
    
    detect_os
    
    case $OS in
        Linux)
            build_linux
            ;;
        Windows)
            build_windows
            ;;
        Mac)
            print_error "macOS support not implemented yet"
            exit 1
            ;;
        *)
            print_error "Unsupported operating system: $OS"
            exit 1
            ;;
    esac
    
    print_status "Build process completed successfully!"
}

# Run main function
main