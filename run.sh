#!/bin/bash
# Simple run script for your project

# Path to your built executable
EXECUTABLE="./build/Utils"

# Check if the executable exists
if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: $EXECUTABLE not found. Please build the project first."
    exit 1
fi

# Run the executable with any passed arguments
"$EXECUTABLE" "$@"