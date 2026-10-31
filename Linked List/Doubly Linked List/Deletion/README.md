# Doubly linked-list deletion

These examples remove nodes from a doubly linked list either by matching data or by selecting a position.

## Suggested learning sequence

1. [`DeleteOnPosition.c`](./DeleteOnPosition.c) — locate a node by position and reconnect its neighbors.
2. [`DeleteOnData.c`](./DeleteOnData.c) — search for matching data before removing the node.
3. For each case, trace deletion at the head, tail, middle, and from an empty list.

## Key ideas

- Update both the previous node's next link and the next node's previous link.
- Handle boundary nodes, which have one missing neighbor.
- Release the removed node after reconnecting the list.
