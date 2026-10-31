# Singly linked-list deletion

These examples remove a node either by its position or by matching its data.

## Suggested learning sequence

1. [`DeleteOnPosition.c`](./DeleteOnPosition.c) — locate a node by walking to the requested position.
2. [`DeleteOnData.c`](./DeleteOnData.c) — search for a value and unlink its node.
3. Trace deletion of the head, a middle node, the last node, and an item from an empty list.

## Key ideas

- A singly linked list needs the predecessor link to bypass the node being removed.
- Deleting the head requires updating the head pointer itself.
- Release the removed node after reconnecting the list.
