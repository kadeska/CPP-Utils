# run-anywhere.sh
#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 /path/to/project-root [program arguments...]"
    exit 1
fi

PROJECT_ROOT="$1"
shift

EXECUTABLE="$PROJECT_ROOT/build/Utils"

if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: $EXECUTABLE not found in $PROJECT_ROOT. Please build the project first."
    exit 1
fi

"$EXECUTABLE" "$@"
