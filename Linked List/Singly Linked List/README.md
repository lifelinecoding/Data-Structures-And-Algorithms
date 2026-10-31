# Singly linked lists

A singly linked list stores data in nodes, each with a link to the next node. These files introduce traversal, searching, reversal, and the insertion and deletion subtopics.

## Suggested learning sequence

1. [`Traversal.c`](./Traversal.c) — follow links from the head to the end of the list.
2. [`Searching.c`](./Searching.c) — traverse while checking node values.
3. [Insertion](./Insertion/README.md) — add nodes at the start, end, or middle.
4. [Deletion](./Deletion/README.md) — remove nodes by position or data.
5. [`Reverse.c`](./Reverse.c) — reverse links and make the former tail the new head.

## Key ideas

- Each node points only forward; reaching a later node requires traversing from an earlier one.
- Keep track of the head, and consider empty and one-node lists separately.
- Changing a link before saving the next node can lose access to the rest of the list.
