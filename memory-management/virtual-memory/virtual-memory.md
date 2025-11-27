# Virtual Memory — Notes

## Overview

Virtual memory is an abstraction that gives processes the illusion of a large, contiguous address space independent of physical memory size. It enables isolation, efficient use of RAM, and simple programming models.

## Mechanisms

- Paging and segmentation are common mechanisms to implement virtual memory.
- Swap space (on disk) stores pages that are not currently resident in physical memory.

## Swapping and Demand Paging

- **Swapping**: Moving entire processes or large portions between RAM and disk.
- **Demand Paging**: Loading individual pages on demand; more fine-grained and commonly used.

## Working Set and Thrashing

- **Working set**: The set of pages a process actively uses during a period.
- **Thrashing**: When the system spends most of its time swapping pages in/out rather than executing useful work, usually due to insufficient physical memory.

## Page Replacement Policies

- Discussed in paging notes: LRU, FIFO, Optimal, CLOCK (approximation of LRU).

## Performance Metrics

- Page fault rate, TLB hit/miss rate, effective memory access time.

## Optimizations

- Prefetching: Loading pages likely to be used soon.
- Copy-on-write: Delay copying pages until write occurs, enabling efficient process cloning (e.g., fork).

## Practical Considerations

- Swap device sizing and placement affects performance.
- Large pages (huge pages) can reduce TLB pressure for memory-intensive workloads.

## Further Reading

- Silberschatz — Operating System Concepts (virtual memory chapters)
