# Processes — Overview

- **Definition:** An executing program instance with its own address space, resources, and execution state.
- **PCB (Process Control Block):** PID, registers, program counter, memory map, open files, priority, state.
- **States:** New, Ready, Running, Waiting (Blocked), Terminated. Transitions depend on scheduling and I/O.
- **Context Switch:** Save/restore CPU state; expensive relative to thread switch.
- **Creation & Termination:** Typical UNIX sequence: `fork()` → `exec()`; termination via `exit()`; parent may `wait()`.
- **Parent/Child:** Inherit environment; PID relationships; zombies and orphan processes.
- **IPC Overview:** Pipes, FIFOs, message queues, sockets, shared memory — choose by latency and complexity.

Study tip: Draw state-transition diagrams and practice tracing `fork()`/`exec()` examples.
