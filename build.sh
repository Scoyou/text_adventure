#!/bin/sh

# Determine the number of CPU cores for parallel build
if command -v nproc >/dev/null 2>&1; then
    CORES=$(nproc)
elif command -v sysctl >/dev/null 2>&1; then
    CORES=$(sysctl -n hw.ncpu)
else
    CORES=1
fi

echo "Using $CORES cores for building."

# Check if the first argument is "clean"
if [ "$1" = "clean" ]; then
    echo "Cleaning build directory..."
    rm -rf ./build || { echo "Failed to remove build directory"; exit 1; }
fi

# Create the build directory if it doesn't exist
if [ ! -d "./build" ]; then
    echo "Creating build directory..."
    mkdir ./build || { echo "Failed to create build directory"; exit 1; }
fi

# Navigate to the build directory
cd ./build || { echo "Failed to enter build directory"; exit 1; }

# Generate the build system
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Build the project using multiple cores
cmake --build . -- -j"$CORES" || { echo "Build failed"; exit 1; }

echo "Build completed successfully."
