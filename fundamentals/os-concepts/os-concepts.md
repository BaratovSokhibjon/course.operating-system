# Operating System Concepts — Notes

## What is an Operating System?

An operating system (OS) is system software that manages hardware and provides services to applications. It provides abstractions like processes, files, and devices to simplify application development.

## Core Abstractions

- **Process**: An executing program with its own address space, resources, and state.
- **Thread**: A lightweight unit of execution within a process that shares address space with other threads of the same process.
- **File**: Named storage abstraction providing persistent data access.
- **Device**: Representation of hardware resources (block, character, network devices).

## Key Services

- Process and thread management (creation, scheduling, termination)
- Memory management and protection
- File systems and storage management
- Device I/O and driver interfaces
- Networking and communication
- Security and access control

## Concurrency and Synchronization

- Race conditions, critical sections
- Locks, semaphores, condition variables, monitors
- Deadlock conditions and prevention techniques

## Protection and Security

- User vs kernel mode separation
- Access control models (ACLs, capabilities)
- Authentication and auditing

## Design Goals

- Efficiency: make good use of CPU, memory, and I/O
- Fairness: share resources among users/processes
- Simplicity and modularity for maintainability
- Robustness and fault tolerance

## Common Architectures

- Layered architecture: clear separation of responsibilities
- Modular/plug-in components: loadable kernel modules or services

## Further Reading

- Silberschatz, Galvin, Gagne — Operating System Concepts
- Tanenbaum — Modern Operating Systems
