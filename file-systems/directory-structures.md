# Directory Structures

## Overview

Directory structures are the hierarchical organization of files and directories in a file system. They provide a logical way to organize, locate, and manage data storage.

## Types of Directory Structures

### 1. Single-Level Directory
- **Description**: All files are stored in a single directory
- **Advantages**: Simple implementation
- **Disadvantages**: 
  - File naming conflicts
  - Poor organization for large systems
  - Difficult to manage multiple users

### 2. Two-Level Directory
- **Description**: Separate directory for each user
- **Structure**: Master directory containing user directories
- **Advantages**: 
  - Solves naming conflicts between users
  - Better user isolation
- **Disadvantages**: Still limited organization within user directories

### 3. Tree-Structured (Hierarchical) Directory
- **Description**: Multi-level directory structure
- **Structure**: Root directory with subdirectories and files
- **Advantages**:
  - Logical organization
  - Efficient file location
  - Supports complex file relationships
- **Implementation**: Used in most modern OS (Unix, Windows, macOS)

### 4. Acyclic Graph Directory
- **Description**: Tree structure with shared subdirectories/files
- **Features**:
  - Multiple parents for directories
  - Hard links and symbolic links
  - Shared access to common files
- **Advantages**: 
  - File sharing without duplication
  - Flexible organization
- **Challenges**: 
  - Complex reference counting
  - Potential for cycles (must be prevented)

### 5. General Graph Directory
- **Description**: Allows cycles in directory structure
- **Features**: Complete flexibility in directory connections
- **Challenges**: 
  - Infinite loops during traversal
  - Complex garbage collection
  - Rarely implemented in practice

## Directory Implementation

### Linear List
- **Structure**: Array of file entries with names and pointers
- **Operations**: Linear search for file lookup
- **Advantages**: Simple to implement
- **Disadvantages**: Slow search performance (O(n))

### Hash Table
- **Structure**: Hash function maps file names to entries
- **Operations**: Direct access via hash
- **Advantages**: Fast lookup (O(1) average case)
- **Disadvantages**: 
  - Fixed size
  - Collision handling complexity
  - Poor performance when full

### B-Tree
- **Structure**: Balanced tree structure for directories
- **Advantages**: 
  - Efficient for large directories
  - Good performance for sorted access
  - Supports range queries
- **Use Case**: Often used for on-disk directory structures

## Path Names

### Absolute Path
- **Definition**: Path from root directory to file
- **Example**: `/home/user/documents/file.txt` (Unix)
- **Example**: `C:\Users\User\Documents\file.txt` (Windows)

### Relative Path
- **Definition**: Path from current working directory
- **Example**: `documents/file.txt`
- **Special Directories**:
  - `.` (current directory)
  - `..` (parent directory)

### Mount Points
- **Concept**: Attaching a file system to directory structure
- **Process**: 
  1. Create empty directory (mount point)
  2. Attach file system to mount point
  3. Files appear under mount point
- **Example**: Mounting USB drive at `/media/usb`

## Directory Operations

### Create Directory
```bash
mkdir /path/to/directory
```

### Delete Directory
```bash
rmdir /path/to/directory  # Empty directory only
rm -r /path/to/directory  # Recursive delete
```

### Change Directory
```bash
cd /path/to/directory
```

### List Contents
```bash
ls /path/to/directory
```

## File System Navigation

### Current Working Directory
- The directory where the process is currently located
- Used as base for relative paths
- Maintained per process

### Directory Traversal Algorithms
- **Depth-First Search**: Explore as far as possible along each branch
- **Breadth-First Search**: Explore all neighbors at current depth

## Access Control

### Permissions
- **Read**: View directory contents
- **Write**: Create/delete files in directory
- **Execute**: Access directory (cd into it)

### Ownership
- **User**: Owner of the directory
- **Group**: Group ownership
- **Others**: Everyone else

## Performance Considerations

### Cache Directory Entries
- Store frequently accessed directory information in memory
- Reduces disk I/O for common operations

### Directory Optimization
- Keep directories small for better performance
- Use appropriate directory structure depth
- Consider file access patterns

## Common Directory Structures by OS

### Unix/Linux
```
/
├── bin/        # Essential binaries
├── etc/        # Configuration files
├── home/       # User directories
├── lib/        # System libraries
├── tmp/        # Temporary files
├── usr/        # User programs
└── var/        # Variable data
```

### Windows
```
C:\
├── Program Files/    # Applications
├── Windows/          # System files
├── Users/            # User directories
├── ProgramData/      # Application data
└── Temp/             # Temporary files
```

## Best Practices

1. **Logical Organization**: Group related files together
2. **Consistent Naming**: Use clear, descriptive names
3. **Appropriate Depth**: Avoid overly deep hierarchies
4. **Regular Cleanup**: Remove unused files and directories
5. **Backup Strategy**: Implement regular backups of important directories