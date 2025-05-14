#!/bin/bash

# Set variables
BUILD_DIR="./build"
CROSS_BUILD_DIR="./build_cross_compile"
BIN_DIR="./build/bin"
CROSS_BIN_DIR="./build_cross_compile/bin"
TOOLCHAIN_FILE="./toolchain-s32g3.cmake"  

# Ask user whether to perform cross-compilation
#read -p "Do you want to perform cross-compilation? (yes/no): " CROSS_COMPILE

if [ "$1" = "yes" ]; then
    echo "Cross-compilation selected. Using cross-compilation build directory."

    # Step 1: Delete the existing cross-compilation build directory if it exists
    if [ -d "$CROSS_BUILD_DIR" ]; then
        echo "Removing existing cross-compilation build directory..."
        rm -rf "$CROSS_BUILD_DIR"
    fi

    # Step 2: Create new cross-compilation build directory
    echo "Creating new cross-compilation build directory..."
    mkdir -p "$CROSS_BUILD_DIR"

    # Step 3: Navigate to cross-compilation build directory
    cd "$CROSS_BUILD_DIR" || { echo "Failed to enter cross-compilation build directory"; exit 1; }

    # Step 4: Run CMake configuration with the toolchain file
    echo "Running CMake with toolchain file..."
    cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" ..

    # Step 5: Build the project
    echo "Running make for cross-compilation..."
    make

    echo "Cross-compilation build completed successfully!"
else
    echo "Standard compilation selected. Using normal build directory."

    # Step 1: Delete the existing build directory if it exists
    if [ -d "$BUILD_DIR" ]; then
        echo "Removing existing build directory..."
        rm -rf "$BUILD_DIR"
    fi

    # Step 2: Create new build directory
    echo "Creating new build directory..."
    mkdir -p "$BUILD_DIR"

    # Step 3: Navigate to build directory
    cd "$BUILD_DIR" || { echo "Failed to enter build directory"; exit 1; }

    # Step 4: Run CMake configuration
    echo "Running CMake..."
    cmake ..

    # Step 5: Build the project
    echo "Running make..."
    make

    echo "Standard build completed successfully!"
fi
