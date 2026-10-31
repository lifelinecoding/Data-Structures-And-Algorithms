# Circular linked lists

In a circular list, the last node links back to the first node rather than ending with a null link. The folder contains singly and doubly linked variants.

## Suggested learning sequence

1. [`SinglyCircular.c`](./SinglyCircular.c) — study the circular next-link structure.
2. [`DoublyCircular.c`](./DoublyCircular.c) — compare it with a structure that also links backward.
3. Trace a complete traversal and identify the stopping condition that prevents an infinite loop.

## Key ideas

- Circular links can support repeated traversal from a starting point.
- Updating the first or last node requires preserving the loop.
- A traversal must detect that it has returned to its starting point; checking only for null is not sufficient.
