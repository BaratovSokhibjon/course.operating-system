# System Calls — Notes

## Definition

System calls are the interface through which user-space programs request services from the kernel. They provide controlled access to hardware and protected resources.

## Categories of System Calls

- **Process control**: fork, exec, wait, exit
- **File management**: open, read, write, close, stat
- **Device management**: ioctl, mmap
- **Information maintenance**: getpid, uname, time
- **Communication**: pipe, socket, send, recv

## Mechanism

- User program executes a library wrapper (e.g., C standard library) which sets up registers and issues a software trap/interrupt into kernel mode.
- Kernel validates parameters, switches to kernel context, performs the operation, and returns results to user space.

## Error Handling

- System calls return negative values or set `errno` to indicate errors; callers must check return values.

## Performance Considerations

- System calls cross the user/kernel boundary and incur overhead (context switch, parameter validation).
- Minimizing syscall frequency and batching operations (e.g., vectored I/O) helps performance.

## Tracing and Debugging

- Tools like `strace` (Linux) or `truss` (BSD) intercept and log system calls made by a process.

## Examples (Linux)

- `open("/etc/passwd", O_RDONLY)` — request to open a file descriptor
- `read(fd, buf, n)` — read bytes from file descriptor into buffer

## Further Reading

- Linux manpages section 2 (syscalls)
- Stevens — Advanced Programming in the UNIX Environment
