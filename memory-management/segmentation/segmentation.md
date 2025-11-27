# Segmentation — Notes

## Overview

Segmentation is a memory management technique that divides a program's memory into variable-sized segments representing logical divisions such as code, stack, heap, and data. Each segment has a base and limit, enabling logical addressing and protection.

## Key Concepts

- **Segment**: A contiguous block of logical memory with semantic meaning (e.g., function code, data array).
- **Segment Table**: Maps a segment number to a base (starting physical address) and a limit (length).
- **Logical Address**: (segment_number, offset) pairs used by programs.

## Address Translation

- CPU provides segment number and offset.
- The hardware checks offset < limit; if valid, physical address = base + offset.

## Advantages

- Matches programmer's view of memory; facilitates sharing and protection at segment granularity.
- Supports variable-sized segments avoiding internal fragmentation seen with fixed-size pages.

## Disadvantages

- External fragmentation: free memory scattered into small holes.
- Segment allocation and compaction (or relocation) may be required.

## Segmentation with Paging

- Many systems combine segmentation and paging: segments are divided into pages to get benefits of both (logical grouping + fixed-size frame management).

## Protection

- Segment table entries include permission bits (read, write, execute) and sometimes sharing flags.

## Further Reading

- Tanenbaum — Modern Operating Systems (segmentation section)
