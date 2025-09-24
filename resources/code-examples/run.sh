#!/bin/bash

# Compile and Run Script for OS Code Examples
# Usage: ./run.sh <category> <example>
# Example: ./run.sh threads basic_thread

set -e

GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

if [ $# -lt 2 ]; then
    echo -e "${RED}Usage: $0 <category> <example>${NC}"
    echo ""
    echo "Categories:"
    echo "  processes    - Process management examples"
    echo "  threads      - Threading examples"
    echo "  sync         - Synchronization examples"
    echo "  memory       - Memory management examples"
    echo "  syscalls     - System calls examples"
    echo "  filesystems  - File system examples"
    echo "  scheduling   - Scheduling algorithms"
    echo "  ipc          - IPC examples"
    echo ""
    echo "Example: $0 threads basic_thread"
    exit 1
fi

CATEGORY=$1
EXAMPLE=$2

# Map category names to directory names
case $CATEGORY in
    processes)
        DIR="01-process-management"
        ;;
    threads)
        DIR="02-threads"
        FLAGS="-pthread"
        ;;
    sync)
        DIR="03-synchronization"
        FLAGS="-pthread"
        ;;
    memory)
        DIR="04-memory-management"
        ;;
    syscalls)
        DIR="05-system-calls"
        ;;
    filesystems)
        DIR="06-file-systems"
        ;;
    scheduling)
        DIR="07-scheduling"
        ;;
    ipc)
        DIR="08-ipc"
        ;;
    *)
        echo -e "${RED}Unknown category: $CATEGORY${NC}"
        exit 1
        ;;
esac

SOURCE="$DIR/${EXAMPLE}.c"
OUTPUT="$DIR/${EXAMPLE}"

if [ ! -f "$SOURCE" ]; then
    echo -e "${RED}Error: Source file not found: $SOURCE${NC}"
    exit 1
fi

echo -e "${BLUE}Compiling $SOURCE...${NC}"
gcc -Wall -Wextra -g $FLAGS -o "$OUTPUT" "$SOURCE"

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Compilation successful!${NC}"
    echo -e "${BLUE}Running $OUTPUT...${NC}"
    echo "----------------------------------------"
    "$OUTPUT"
    echo "----------------------------------------"
    echo -e "${GREEN}✓ Execution completed!${NC}"
else
    echo -e "${RED}✗ Compilation failed!${NC}"
    exit 1
fi
