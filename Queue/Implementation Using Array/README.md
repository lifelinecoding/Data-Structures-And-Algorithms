# Array-based queues

This folder contains simple and circular queue implementations using arrays.

## Suggested learning sequence

1. [`SimpleQueue.c`](./SimpleQueue.c) — follow the front and rear indices through enqueue and dequeue operations.
2. [`CircularQueue.c`](./CircularQueue.c) — study how indices wrap around to reuse freed array positions.
3. Trace empty, full, enqueue, and dequeue transitions for each implementation.

## Key ideas

- Array queues have a capacity that must be checked before insertion.
- Circular indexing wraps using the array capacity; carefully distinguish full from empty states.
- A simple queue may not reuse earlier slots without shifting; the circular form avoids that waste.
