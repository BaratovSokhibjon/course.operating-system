# Storage Devices

## Overview

Storage devices are hardware components that store and retrieve digital data. They form the foundation of file systems and provide persistent storage for operating systems and applications.

## Storage Device Hierarchy

### Primary Storage (Memory)
- **RAM**: Random Access Memory
- **Cache**: CPU cache memory
- **Registers**: Fastest storage
- **Characteristics**: Volatile, fast, expensive

### Secondary Storage (Persistent)
- **Hard Disk Drives (HDD)**: Magnetic storage
- **Solid State Drives (SSD)**: Flash memory
- **Optical Drives**: CD/DVD/Blu-ray
- **Magnetic Tape**: Sequential access storage

### Tertiary Storage (Archival)
- **Robotic Tape Libraries**: Automated tape systems
- **Cloud Storage**: Distributed storage systems
- **Optical Jukeboxes**: Automated optical storage

## Magnetic Disk Drives

### Physical Structure
- **Platters**: Circular disks coated with magnetic material
- **Spindle**: Rotates platters at constant speed
- **Read/Write Heads**: Magnetic heads on actuator arms
- **Actuator Arm**: Positions heads over tracks

### Disk Geometry
- **Tracks**: Concentric circles on platter surface
- **Sectors**: Segments of tracks (typically 512 bytes)
- **Cylinders**: Set of tracks at same radius across all platters
- **Blocks**: Logical units of storage (multiple sectors)

### Performance Characteristics
- **Access Time**: Time to access data
  - **Seek Time**: Move heads to correct track
  - **Rotational Latency**: Wait for sector to rotate under head
  - **Transfer Time**: Actual data transfer
- **Rotation Speed**: 5400, 7200, 10000, 15000 RPM
- **Data Transfer Rate**: MB/s sustained and burst rates

### Disk Scheduling Algorithms

#### FCFS (First-Come, First-Served)
- Simple implementation
- May cause poor performance
- No starvation

#### SSTF (Shortest Seek Time First)
- Selects request with minimum seek time
- Better performance than FCFS
- May cause starvation

#### SCAN (Elevator Algorithm)
- Moves head in one direction, then reverses
- No starvation
- More uniform waiting times

#### C-SCAN (Circular SCAN)
- One-way scan with return to beginning
- More uniform wait times
- Better for symmetric loads

#### LOOK and C-LOOK
- Optimized versions of SCAN and C-SCAN
- Doesn't go to last track
- Reduces total head movement

## Solid State Drives (SSD)

### Technology
- **NAND Flash Memory**: Non-volatile storage
- **No Moving Parts**: Faster access, no seek time
- **Memory Cells**: Floating-gate transistors
- **Wear Leveling**: Distributes writes evenly

### SSD Types
- **SATA SSD**: Standard interface, compatible with HDDs
- **NVMe SSD**: PCIe interface, much faster
- **M.2 SSD**: Form factor for compact systems
- **U.2 SSD**: Enterprise form factor

### Performance Characteristics
- **Read Speed**: 500 MB/s to 7 GB/s
- **Write Speed**: 300 MB/s to 5 GB/s
- **IOPS**: 100K to 1M+ operations per second
- **Latency**: Microseconds vs milliseconds for HDD

### SSD Challenges
- **Write Endurance**: Limited write cycles per cell
- **Write Amplification**: Internal data movement
- **Garbage Collection**: Background cleanup process
- **TRIM Command**: Inform OS of unused blocks

## Optical Storage

### CD (Compact Disc)
- **Capacity**: 700 MB
- **Technology**: Laser-etched pits
- **Types**: CD-ROM, CD-R, CD-RW
- **Speed**: 1x = 150 KB/s

### DVD (Digital Versatile Disc)
- **Capacity**: 4.7 GB (single layer), 8.5 GB (dual layer)
- **Technology**: Smaller pits, tighter tracks
- **Types**: DVD-ROM, DVD-R, DVD-RW, DVD+R, DVD+RW
- **Speed**: 1x = 1.32 MB/s

### Blu-ray Disc
- **Capacity**: 25 GB (single layer), 50 GB (dual layer)
- **Technology**: Blue laser (405 nm wavelength)
- **Types**: BD-ROM, BD-R, BD-RE
- **Speed**: 1x = 4.5 MB/s

## Magnetic Tape

### Characteristics
- **Sequential Access**: Must wind tape to find data
- **High Capacity**: Up to several TB per cartridge
- **Low Cost**: Cheapest per GB storage
- **Long-term Storage**: Excellent for archival

### Tape Formats
- **LTO (Linear Tape-Open)**: Most common enterprise format
- **DAT (Digital Audio Tape)**: Older format
- **DLT (Digital Linear Tape)**: Enterprise format
- **AIT (Advanced Intelligent Tape)**: Sony format

### Tape Libraries
- **Robotic Systems**: Automated tape handling
- **Multiple Drives**: Parallel access
- **Large Capacity**: Hundreds of TB
- **Barcoding**: Tape identification system

## RAID (Redundant Array of Independent Disks)

### RAID Levels

#### RAID 0 (Striping)
- **Description**: Data split across disks
- **Advantages**: Improved performance
- **Disadvantages**: No redundancy, single point of failure
- **Capacity**: Sum of all disks

#### RAID 1 (Mirroring)
- **Description**: Exact copy on two disks
- **Advantages**: Complete redundancy
- **Disadvantages**: 50% capacity efficiency
- **Capacity**: Half of total disk space

#### RAID 5 (Striping with Parity)
- **Description**: Distributed parity across disks
- **Advantages**: Good performance, single disk fault tolerance
- **Disadvantages**: Write performance penalty
- **Capacity**: (N-1) disks

#### RAID 6 (Striping with Double Parity)
- **Description**: Two sets of distributed parity
- **Advantages**: Dual disk fault tolerance
- **Disadvantages**: Higher write overhead
- **Capacity**: (N-2) disks

#### RAID 10 (Stripe of Mirrors)
- **Description**: Mirrored pairs striped together
- **Advantages**: Excellent performance and redundancy
- **Disadvantages**: 50% capacity efficiency
- **Capacity**: Half of total disk space

## Storage Device Interfaces

### Parallel Interfaces
- **IDE/PATA**: Older parallel interface
- **SCSI**: High-performance parallel interface
- **Limited Cable Length**: Short distance limitations

### Serial Interfaces
- **SATA**: Serial ATA, current standard for HDDs/SSDs
- **SAS**: Serial Attached SCSI, enterprise interface
- **NVMe**: PCIe-based interface for SSDs
- **USB**: External storage interface

### Network Storage
- **iSCSI**: SCSI over IP networks
- **Fibre Channel**: High-speed network storage
- **InfiniBand**: High-performance computing storage

## Storage Virtualization

### Logical Volume Management (LVM)
- **Abstract Physical Storage**: Logical volumes independent of physical layout
- **Dynamic Resizing**: Can resize volumes online
- **Snapshot Support**: Point-in-time copies
- **Migration**: Move data between physical devices

### Storage Area Networks (SAN)
- **Block-level Storage**: Raw disk blocks over network
- **Centralized Management**: Single point of administration
- **High Availability**: Redundant paths and devices
- **Performance**: High-speed dedicated networks

### Network Attached Storage (NAS)
- **File-level Storage**: File system access over network
- **Protocol Support**: NFS, SMB/CIFS, FTP
- **Easy Integration**: Works with existing network infrastructure
- **Lower Cost**: Less expensive than SAN

## Storage Performance Optimization

### Caching Strategies
- **Write-back Cache**: Acknowledge write before disk write
- **Write-through Cache**: Write to cache and disk simultaneously
- **Read-ahead Cache**: Prefetch sequential data
- **Adaptive Caching**: Dynamic cache size adjustment

### Queue Management
- **I/O Scheduling**: Optimize request ordering
- **Command Queuing**: Multiple outstanding requests
- **NCQ (Native Command Queuing)**: HDD optimization
- **NVMe Queues**: Multiple I/O queues for SSDs

### Data Placement
- **Hot Data Placement**: Frequently accessed data on fast storage
- **Tiered Storage**: Automatic data migration between tiers
- **Data Deduplication**: Eliminate duplicate data blocks
- **Compression**: Reduce storage requirements

## Storage Management

### Monitoring and Metrics
- **Capacity Utilization**: Track disk space usage
- **Performance Metrics**: IOPS, latency, throughput
- **Health Monitoring**: SMART data for HDDs/SSDs
- **Error Rates**: Track and analyze storage errors

### Backup and Recovery
- **Backup Strategies**: Full, incremental, differential
- **Replication**: Real-time data copying
- **Snapshots**: Point-in-time data copies
- **Disaster Recovery**: Off-site backup and recovery plans

### Lifecycle Management
- **Data Classification**: Categorize data by importance
- **Retention Policies**: How long to keep data
- **Archival**: Move old data to cheaper storage
- **Secure Deletion**: Ensure data cannot be recovered

## Emerging Storage Technologies

### 3D NAND
- **Vertical Stacking**: Multiple layers of memory cells
- **Higher Density**: More capacity per chip
- **Lower Cost**: Reduced manufacturing cost per GB

### Storage Class Memory (SCM)
- **Persistent Memory**: DRAM-like speed with persistence
- **Intel Optane**: 3D XPoint technology
- **Applications**: Database acceleration, caching

### DNA Storage
- **Molecular Storage**: Data encoded in DNA sequences
- **Extreme Density**: Petabytes per gram
- **Long-term Stability**: Thousands of years
- **Current Status**: Experimental, expensive

### Quantum Storage
- **Quantum States**: Store data in quantum states
- **Theoretical**: Still in research phase
- **Potential**: Revolutionary storage capabilities