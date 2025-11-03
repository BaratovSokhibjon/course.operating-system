# File Management

## Overview

File management encompasses the creation, organization, access, and maintenance of files within a file system. It involves managing file attributes, operations, and ensuring data integrity and security.

## File Concepts

### File Definition
A file is a named collection of related information that is recorded on secondary storage. Files can represent:
- Programs (source code, executables)
- Data (documents, databases, images)
- System information (logs, configuration)

### File Attributes

#### Basic Attributes
- **Name**: Human-readable identifier
- **Identifier**: Unique system identifier (typically numeric)
- **Type**: File type (text, binary, executable, etc.)
- **Location**: Path to file on storage device
- **Size**: Current file size in bytes
- **Protection**: Access control information

#### Time Attributes
- **Creation Time**: When file was created
- **Last Modified Time**: When file was last changed
- **Last Accessed Time**: When file was last read
- **Archive Bit**: Indicates if file needs backup

#### Owner Attributes
- **Owner**: User who created the file
- **Group**: Group ownership for shared access
- **Permissions**: Read/write/execute rights

## File Operations

### Create File
```c
// System call example
int fd = creat("filename.txt", 0644);
```
- Allocates space for file
- Creates directory entry
- Sets initial attributes

### Delete File
```c
int result = unlink("filename.txt");
```
- Removes directory entry
- Deallocates file space
- Updates metadata

### Open File
```c
int fd = open("filename.txt", O_RDONLY);
```
- Searches directory structure
- Copies file control block to memory
- Returns file descriptor

### Close File
```c
int result = close(fd);
```
- Releases file descriptor
- Updates file metadata
- Flushes buffers if needed

### Read File
```c
ssize_t bytes_read = read(fd, buffer, count);
```
- Transfers data from file to memory
- Updates file pointer
- Handles end-of-file conditions

### Write File
```c
ssize_t bytes_written = write(fd, buffer, count);
```
- Transfers data from memory to file
- Updates file pointer
- May allocate additional space

### Seek File
```c
off_t position = lseek(fd, offset, whence);
```
- Repositions file pointer
- Supports random access
- Can determine file size

## File Types

### Text Files
- Human-readable content
- Line-oriented structure
- Character encoding (ASCII, UTF-8)
- Examples: `.txt`, `.csv`, `.json`

### Binary Files
- Machine-readable content
- No inherent structure
- Platform-specific format
- Examples: `.exe`, `.jpg`, `.mp3`

### Executable Files
- Machine code instructions
- Header with metadata
- May contain multiple sections
- Examples: `.exe`, `.elf`, `.mach-o`

### Special Files
- **Device Files**: Interface to hardware devices
- **Symbolic Links**: Pointers to other files
- **Pipes**: Inter-process communication
- **Sockets**: Network communication

## File Access Methods

### Sequential Access
- Data accessed in order
- Simple implementation
- Common for text files
- Example: `read()` advances file pointer

### Direct Access
- Access any block directly
- Requires block addressing
- Common for databases
- Example: `lseek()` + `read()`

### Indexed Access
- Uses index to locate data
- Supports complex queries
- Common in database systems
- Example: B-tree indexes

## File Organization

### Pile Organization
- No specific structure
- Data appended in arrival order
- Simple but inefficient for searching
- Used for log files

### Sequential File
- Records ordered by key
- Efficient for sequential processing
- Poor for random access
- Example: sorted text files

### Indexed Sequential File
- Sequential file with index
- Supports both sequential and direct access
- Index maps keys to record locations
- Example: database tables

### Hashed Organization
- Hash function determines location
- Fast direct access
- May have collisions
- Example: hash tables on disk

## File Control Block (FCB)

### Structure
- Contains all file metadata
- Stored in system tables
- Loaded into memory when file opened
- Includes:
  - File identification
  - File permissions
  - Location information
  - Usage statistics

### In-Memory Structures
- **Open File Table**: System-wide open files
- **Per-Process Table**: Process-specific file descriptors
- **File Pointer**: Current read/write position
- **Disk Block Pointers**: Mapping to physical storage

## File System Implementation

### Allocation Methods

#### Contiguous Allocation
- **Description**: File occupies consecutive blocks
- **Advantages**: Fast sequential and direct access
- **Disadvantages**: External fragmentation, file size limitation

#### Linked Allocation
- **Description**: Each block points to next block
- **Advantages**: No external fragmentation, dynamic file size
- **Disadvantages**: Slow random access, reliability issues

#### Indexed Allocation
- **Description**: Index block contains pointers to data blocks
- **Advantages**: Supports direct access, no fragmentation
- **Disadvantages**: Index block overhead, size limitation

#### Combined Allocation
- **Description**: Mix of allocation methods
- **Example**: Unix UFS uses direct, indirect, double indirect blocks
- **Advantages**: Optimized for different file sizes

## Free Space Management

### Bit Vector
- Bitmap representing free/used blocks
- Fast operations
- Memory overhead proportional to disk size

### Free List
- Linked list of free blocks
- Simple implementation
- Can be slow for large disks

### Counting
- Groups of consecutive free blocks
- Reduces list size
- Efficient for contiguous free space

## File Protection and Security

### Access Control Lists (ACL)
- Lists users and their permissions
- Fine-grained control
- Complex to manage

### Capabilities
- Tokens granting specific access
- Decentralized control
- Revocation challenges

### Encryption
- Protects data confidentiality
- Key management complexity
- Performance overhead

## File System Consistency

### Consistency Checking
- Verify file system structure
- Check for lost clusters
- Repair inconsistencies
- Example: `fsck`, `chkdsk`

### Journaling
- Log changes before applying
- Enables crash recovery
- Common in modern file systems
- Example: ext4, NTFS

### Copy-on-Write
- Create copies before modification
- Enables snapshots
- Improves reliability
- Example: ZFS, Btrfs

## Performance Optimization

### Buffering
- Cache frequently accessed data
- Reduce disk I/O
- Write-back vs write-through policies

### Caching
- Store file metadata in memory
- Directory entry caching
- Block caching strategies

### Prefetching
- Anticipate future accesses
- Load data before needed
- Sequential access optimization

## File System Utilities

### Backup Utilities
- Full backups
- Incremental backups
- Differential backups
- Archive formats (tar, zip)

### Compression Utilities
- Reduce storage requirements
- Trade CPU time for space
- Lossless vs lossless compression
- Examples: gzip, zip, compress

### Defragmentation
- Reorganize file fragments
- Improve access performance
- Required for some file systems
- Automatic vs manual defragmentation

## File System Standards

### POSIX File System
- Standard API for file operations
- Consistent behavior across Unix systems
- Defines file permissions and attributes

### Windows File System
- Win32 API for file operations
- Different path separators
- Case-insensitive by default

### Network File Systems
- NFS (Network File System)
- SMB/CIFS (Windows file sharing)
- Distributed file access protocols