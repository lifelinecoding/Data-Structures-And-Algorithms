# Singly linked-list insertion

These programs add a node at the start, end, or a middle position of a singly linked list.

## Suggested learning sequence

1. [`InsertAtStart.c`](./InsertAtStart.c) — link a new node before the current head.
2. [`InsertionAtEnd.c`](./InsertionAtEnd.c) — traverse to and update the final node.
3. [`InsertionAtMiddle.c`](./InsertionAtMiddle.c) — locate a predecessor and splice in the new node.
4. Trace each case with an empty list and a one-node list.

## Key ideas

- Set the new node's next link before replacing the predecessor's link.
- Inserting at the head changes the head pointer; inserting elsewhere requires finding the correct predecessor.
- Check allocation and position validity when adapting these examples.
