# Kernel Architecture — Notes

## Overview

The kernel is the core component of an operating system that runs in privileged mode and manages hardware resources, process scheduling, memory, and I/O. It acts as an abstraction layer between applications and physical hardware.

## Kernel Types

- **Monolithic Kernel**: All services (device drivers, file systems, network stack) run in kernel space. Examples: traditional UNIX, Linux.
- **Microkernel**: Minimal core (IPC, basic scheduling, low-level drivers) in kernel space; most services run in user space. Examples: Minix, QNX.
- **Hybrid Kernel**: Mix of monolithic and microkernel ideas (e.g., Windows NT).

## Responsibilities

- CPU scheduling and context switching
- Memory management (allocation, virtual memory, paging)
- Device and driver management
- File system management
- Inter-process communication (IPC) and synchronization
- Security, access control, and protection

## Modes and Privilege Levels

- Kernel (supervisor) mode: full privileged access to hardware and CPU instructions.
- User mode: restricted access; applications run here and request kernel services via system calls.

## Boot Sequence (high level)

1. Bootloader executes and initializes minimal hardware.
2. Kernel image is loaded into memory.
3. Kernel initializes core subsystems (memory, interrupt handling, scheduler).
4. Init/systemd (or equivalent) starts user-space services.

## Example Kernel Components

- Scheduler: selects next runnable task and performs context switches.
- Memory manager: handles virtual address spaces and page tables.
- Device drivers: provide abstract interfaces to hardware.
- VFS (Virtual File System): unifies access to different file system formats.

## Design Trade-offs

- Performance vs. reliability: Monolithic kernels can be faster but a faulty driver may crash the system; microkernels improve isolation at potential performance cost.
- Complexity vs. simplicity: More modular designs improve maintainability but increase IPC overhead.

## Further Reading

- Tanenbaum, A.S. — Modern Operating Systems (chapters on kernels)
- Bovet & Cesati — Understanding the Linux Kernel
