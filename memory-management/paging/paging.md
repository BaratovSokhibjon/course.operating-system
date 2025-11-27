# Paging — Notes

## Overview

Paging is a memory management scheme that eliminates the need for contiguous physical memory allocation by dividing virtual memory into fixed-size pages and physical memory into frames.

## Key Concepts

- **Page**: Fixed-size block of virtual memory (commonly 4 KiB).
- **Frame**: Fixed-size block of physical memory, same size as a page.
- **Page Table**: Per-process data structure mapping virtual page numbers to physical frame numbers and holding metadata (present bit, dirty bit, access permissions).
- **TLB (Translation Lookaside Buffer)**: Small, fast cache of recent virtual-to-physical translations to speed up address translation.

## Address Translation

- Virtual address is split into a page number and offset.
- Page number -> consult page table (or TLB) to find frame number.
- Physical address = frame_number * frame_size + offset.

## Multi-level Page Tables

- Used to reduce memory overhead of large flat page tables by breaking the table into multiple smaller tables indexed in stages.

## Demand Paging

- Pages are loaded into memory only when they are needed (page fault triggers load).
- Reduces memory usage but introduces page-fault overhead.

## Page Replacement Algorithms

- **FIFO**: Evict the oldest loaded page.
- **LRU (Least Recently Used)**: Evict the page not used for the longest time (approximate implementations common).
- **Optimal (Belady's)**: Theoretical best — evict page not used for the longest time in the future.

## Performance Considerations

- TLB hit ratio drastically affects effective memory access time.
- Page size trade-offs: small pages reduce internal fragmentation but increase page table size and TLB pressure.

## Further Reading

- Silberschatz — Operating System Concepts (paging chapter)
