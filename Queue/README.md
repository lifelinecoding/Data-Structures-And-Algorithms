# Queues

A queue processes elements in first-in, first-out order: insertion happens at the rear and removal at the front. This folder compares array and linked-list implementations.

## Suggested learning sequence

1. [Array implementation](./Implementation%20Using%20Array/README.md) — start with a simple queue, then study the circular-array variant.
2. [Linked-list implementation](./Implementation%20Using%20Linked%20List/README.md) — connect queue operations to dynamically allocated nodes.
3. Compare how each implementation tracks its front, rear, empty state, and capacity.

## Key ideas

- Enqueue adds at the rear; dequeue removes from the front.
- A simple array queue can leave unused positions after dequeues; a circular queue reuses array positions.
- An array has a fixed capacity, while a linked implementation grows dynamically subject to available memory.
