# Doubly linked-list insertion

These examples add nodes at common positions in a doubly linked list. Each insertion must preserve links in both directions.

## Suggested learning sequence

1. [`InsertAtStart.c`](./InsertAtStart.c) — update the head and its neighboring links.
2. [`InsertionAtEnd.c`](./InsertionAtEnd.c) — update the tail-side links.
3. [`InsertAtPosition.c`](./InsertAtPosition.c) — generalize the operation to a selected position.
4. Trace insertion into an empty list as well as before, between, and after existing nodes.

## Key ideas

- A new node's previous and next links must agree with the surrounding nodes.
- Update the head or tail when insertion occurs at a boundary.
- Check allocation success and the validity of the requested position in any reuse of the examples.
