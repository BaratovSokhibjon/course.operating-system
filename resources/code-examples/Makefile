# Makefile for Operating Systems Code Examples
# Usage:
#   make all          - Compile all examples
#   make clean        - Remove all compiled binaries
#   make <category>   - Compile examples in a specific category
#   make test         - Run all examples (be careful with deadlock!)

CC = gcc
CFLAGS = -Wall -Wextra -g
PTHREAD_FLAGS = -pthread

# Directories
PROCESS_DIR = 01-process-management
THREAD_DIR = 02-threads
SYNC_DIR = 03-synchronization
MEMORY_DIR = 04-memory-management
SYSCALL_DIR = 05-system-calls
FS_DIR = 06-file-systems
SCHED_DIR = 07-scheduling
IPC_DIR = 08-ipc

# Process Management Programs
PROCESS_PROGS = $(PROCESS_DIR)/fork_example \
                $(PROCESS_DIR)/exec_example \
                $(PROCESS_DIR)/zombie_process \
                $(PROCESS_DIR)/orphan_process

# Thread Programs
THREAD_PROGS = $(THREAD_DIR)/basic_thread \
               $(THREAD_DIR)/race_condition \
               $(THREAD_DIR)/thread_return

# Synchronization Programs
SYNC_PROGS = $(SYNC_DIR)/mutex_example \
             $(SYNC_DIR)/producer_consumer \
             $(SYNC_DIR)/deadlock \
             $(SYNC_DIR)/reader_writer

# Memory Management Programs
MEMORY_PROGS = $(MEMORY_DIR)/dynamic_allocation \
               $(MEMORY_DIR)/memory_leak \
               $(MEMORY_DIR)/pointers

# System Calls Programs
SYSCALL_PROGS = $(SYSCALL_DIR)/common_syscalls \
                $(SYSCALL_DIR)/signals \
                $(SYSCALL_DIR)/alarm

# File System Programs
FS_PROGS = $(FS_DIR)/file_operations \
           $(FS_DIR)/directory_operations \
           $(FS_DIR)/file_permissions

# Scheduling Programs
SCHED_PROGS = $(SCHED_DIR)/cpu_scheduling

# IPC Programs
IPC_PROGS = $(IPC_DIR)/pipe_example \
            $(IPC_DIR)/named_pipe \
            $(IPC_DIR)/shared_memory \
            $(IPC_DIR)/message_queue

# All programs
ALL_PROGS = $(PROCESS_PROGS) $(THREAD_PROGS) $(SYNC_PROGS) $(MEMORY_PROGS) \
            $(SYSCALL_PROGS) $(FS_PROGS) $(SCHED_PROGS) $(IPC_PROGS)

.PHONY: all clean processes threads sync memory syscalls filesystems scheduling ipc help

all: $(ALL_PROGS)
	@echo "✓ All examples compiled successfully!"

# Process Management
processes: $(PROCESS_PROGS)
	@echo "✓ Process management examples compiled!"

$(PROCESS_DIR)/%: $(PROCESS_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# Threads
threads: $(THREAD_PROGS)
	@echo "✓ Thread examples compiled!"

$(THREAD_DIR)/%: $(THREAD_DIR)/%.c
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<

# Synchronization
sync: $(SYNC_PROGS)
	@echo "✓ Synchronization examples compiled!"

$(SYNC_DIR)/%: $(SYNC_DIR)/%.c
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<

# Memory Management
memory: $(MEMORY_PROGS)
	@echo "✓ Memory management examples compiled!"

$(MEMORY_DIR)/%: $(MEMORY_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# System Calls
syscalls: $(SYSCALL_PROGS)
	@echo "✓ System call examples compiled!"

$(SYSCALL_DIR)/%: $(SYSCALL_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# File Systems
filesystems: $(FS_PROGS)
	@echo "✓ File system examples compiled!"

$(FS_DIR)/%: $(FS_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# Scheduling
scheduling: $(SCHED_PROGS)
	@echo "✓ Scheduling examples compiled!"

$(SCHED_DIR)/%: $(SCHED_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# IPC
ipc: $(IPC_PROGS)
	@echo "✓ IPC examples compiled!"

$(IPC_DIR)/%: $(IPC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean
clean:
	@echo "Cleaning up..."
	@rm -f $(ALL_PROGS)
	@rm -f *~ */*~
	@rm -f *.o */*.o
	@echo "✓ Cleanup complete!"

# Help
help:
	@echo "Operating Systems Code Examples - Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  make all          - Compile all examples"
	@echo "  make processes    - Compile process management examples"
	@echo "  make threads      - Compile thread examples"
	@echo "  make sync         - Compile synchronization examples"
	@echo "  make memory       - Compile memory management examples"
	@echo "  make syscalls     - Compile system call examples"
	@echo "  make filesystems  - Compile file system examples"
	@echo "  make scheduling   - Compile scheduling examples"
	@echo "  make ipc          - Compile IPC examples"
	@echo "  make clean        - Remove all compiled binaries"
	@echo "  make help         - Show this help message"
