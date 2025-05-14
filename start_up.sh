#!/bin/bash

# Set default paths for standard build
BUILD_DIR="./build"
BIN_DIR="$BUILD_DIR/bin"
HPC_BINARY="$BIN_DIR/stripped/HPC_CLIENT_APP"
GDCU_BINARY="$BIN_DIR/stripped/GDCU_SERVER"
HPC_LIBS_DIR="$BUILD_DIR/HPC_libs"
GDCU_LIBS_DIR="$BUILD_DIR/GDCU_libs"

# Cross-compilation paths
CROSS_BUILD_DIR="./build_cross_compile"
CROSS_BIN_DIR="$CROSS_BUILD_DIR/bin"
CROSS_HPC_BINARY="$CROSS_BIN_DIR/stripped/HPC_CLIENT_APP"
CROSS_GDCU_BINARY="$CROSS_BIN_DIR/stripped/GDCU_SERVER"
CROSS_HPC_LIBS_DIR="$CROSS_BUILD_DIR/HPC_libs"
CROSS_GDCU_LIBS_DIR="$CROSS_BUILD_DIR/GDCU_libs"

# Ask user whether to handle cross-compilation binaries
read -p "Do you want to handle cross-compiled binaries? (yes/no): " CROSS_COMPILE

if [ "$CROSS_COMPILE" = "yes" ]; then
    echo "Cross-compilation selected. Adjusting paths for cross-compiled binaries."
    HPC_BINARY="$CROSS_HPC_BINARY"
    GDCU_BINARY="$CROSS_GDCU_BINARY"
    HPC_LIBS_DIR="$CROSS_HPC_LIBS_DIR"
    GDCU_LIBS_DIR="$CROSS_GDCU_LIBS_DIR"
fi

# Ensure libraries directories exist
mkdir -p "$HPC_LIBS_DIR"
mkdir -p "$GDCU_LIBS_DIR"

# Step 1: Check shared libraries of HPC_CLIENT_APP using ldd and sync them to libs directory
if [[ -f "$HPC_BINARY" ]]; then
    echo "Running ldd on $HPC_BINARY to find shared libraries..."
    ldd "$HPC_BINARY" | grep "=>" | awk '{print $3}' | xargs -I '{}' rsync -R '{}' "$HPC_LIBS_DIR/"
else
    echo "Error: HPC_CLIENT_APP binary not found at $HPC_BINARY"
    exit 1
fi

# Step 2: Check shared libraries of GDCU_SERVER using ldd and sync them to libs directory
if [[ -f "$GDCU_BINARY" ]]; then
    echo "Running ldd on $GDCU_BINARY to find shared libraries..."
    ldd "$GDCU_BINARY" | grep "=>" | awk '{print $3}' | xargs -I '{}' rsync -R '{}' "$GDCU_LIBS_DIR/"
else
    echo "Error: GDCU_SERVER binary not found at $GDCU_BINARY"
    exit 1
fi

# Optional: Uncomment to start the binaries
# echo "Starting applications..."
# if [[ -f "$HPC_BINARY" ]]; then
#     echo "Starting HPC_SERVER_APP in a new terminal..."
#     xterm -hold -e "$HPC_BINARY" &
# else
#     echo "Error: HPC_SERVER_APP binary not found!"
# fi

# if [[ -f "$GDCU_BINARY" ]]; then
#     echo "Starting GDCU_SERVER in a new terminal..."
#     xterm -hold -e "$GDCU_BINARY" &
# else
#     echo "Error: GDCU_SERVER binary not found!"
# fi

echo "Library synchronization completed successfully!"