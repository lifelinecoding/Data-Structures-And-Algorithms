# Doubly linked lists

A doubly linked list node connects to both its predecessor and successor. This can simplify backward traversal and updates when a node is already known, at the cost of an extra link.

## Suggested learning sequence

1. [`Traversal.c`](./Traversal.c) — inspect the list traversal example and how links are followed.
2. [Insertion](./Insertion/README.md) — learn to update both neighboring links when adding a node.
3. [Deletion](./Deletion/README.md) — detach a node while reconnecting its predecessor and successor.

## Key ideas

- Keep the head and tail boundary links consistent.
- For each insertion or deletion, reason about both forward and backward links.
- Empty lists and operations at either end require separate boundary handling.
