# Linked-list stack

[`Implementation.c`](./Implementation.c) demonstrates a stack whose elements are stored in linked nodes.

## Suggested learning sequence

1. Identify the node type and which pointer represents the top.
2. Trace push and pop at the top of the list.
3. Test popping the final element and verify that the empty state is restored.

## Key ideas

- Operations at the head of a singly linked list can implement stack push and pop without shifting elements.
- Each push allocates a node; each pop should release it.
- Unlike a fixed array stack, the practical capacity depends on available memory.
