# Linked-list queue

[`Implementation.c`](./Implementation.c) demonstrates a queue built from linked nodes rather than a fixed-size array.

## Suggested learning sequence

1. Identify the node structure and the pointers representing the front and rear.
2. Trace enqueue at the rear and dequeue at the front.
3. Test the transition from empty to one element and back to empty.

## Key ideas

- Maintaining both front and rear pointers allows constant-time insertion and removal when implemented correctly.
- The last dequeue must reset both boundary pointers.
- Each allocated node must be released when removed.
