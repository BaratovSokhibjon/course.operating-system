# Scheduling — Algorithms

- **Goal:** Maximize CPU utilization, throughput, fairness, and minimize turnaround/response times.
- **Workload Types:** CPU-bound vs I/O-bound — affects algorithm choice.
- **Metrics:** Throughput, Turnaround time, Waiting time, Response time, Fairness.
- **Algorithms:**
  - FCFS (First-Come, First-Served): simple, can suffer convoy effect.
  - SJF / Shortest-Job-First: optimal average waiting time (needs job length knowledge).
  - SRTF (Preemptive SJF): preemptive variant for better responsiveness.
  - Round Robin: time quantum; good for interactive systems (quantum tuning important).
  - Priority Scheduling: static/dynamic priorities; risk of starvation (use aging).
  - Multilevel Feedback Queue: adapts to behavior (mix of priorities and RR).
- **Examples:** Calculate waiting/turnaround times using scheduling tables (practice problems).

Study tip: Practice scheduling charts for small job sets and vary quantum/priority to see effects.
