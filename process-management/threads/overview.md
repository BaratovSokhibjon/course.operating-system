# Threads — Overview

- **Thread vs Process:** Threads share address space and resources within a process; lighter-weight.
- **Types:** User-level threads, kernel-level threads, and hybrid models (e.g., 1:1, M:N).
- **Lifecycle:** New → Runnable → Running → Blocked → Terminated.
- **Creation:** e.g., POSIX `pthread_create()`; join with `pthread_join()`; detach with `pthread_detach()`.
- **Concurrency Issues:** Data races, atomicity, memory visibility (use synchronization primitives).
- **Thread Safety:** Reentrant functions, avoid shared mutable state, use locks/atomics, prefer immutable data.
- **Thread Pools:** Reuse threads to amortize creation cost; useful for servers and parallel tasks.
- **Performance:** Context switch cheaper than process switch, but still non-zero; consider cache effects.

Study tip: Write small multi-threaded programs and debug with tools (e.g., ThreadSanitizer) to find races.
