# Synchronization — Primitives

- **Problem:** Concurrent access to shared resources leads to race conditions and inconsistent state.
- **Critical Section:** Code region that must not be executed by more than one thread/process at a time.
- **Mutual Exclusion Techniques:**
  - Locks / Mutexes: basic exclusion primitive.
  - Peterson's algorithm: two-process mutual exclusion (theoretical example).
  - Atomic operations: test-and-set, compare-and-swap (hardware support).
- **Semaphores:** Counting and binary semaphores for signaling and mutual exclusion.
- **Monitors & Condition Variables:** Higher-level constructs for safe shared-state access and waiting.
- **Deadlock:** Coffman conditions (mutual exclusion, hold-and-wait, no preemption, circular wait). Prevention, avoidance (Banker), detection and recovery strategies.
- **Best Practices:** Minimize lock scope, prefer fine-grained locks when safe, avoid holding locks during I/O.

Study tip: Implement small producer/consumer examples with semaphores and with condition variables.
