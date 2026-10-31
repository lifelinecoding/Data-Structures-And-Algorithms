# Linked tree implementation

[`Implementation.c`](./Implementation.c) introduces linked tree storage. The binary-tree subfolder contains the shared definition, traversal declarations, and ordered or self-balancing variants.

## Suggested learning sequence

1. Read `Implementation.c` to understand the linked-node example.
2. Continue to [Binary Tree](./Binary%20Tree/README.md) for the shared node type and traversal helpers.
3. Study [Binary Search Tree](./Binary%20Tree/Binary%20Search%20Tree/README.md), then [AVL Tree](./Binary%20Tree/AVL%20Tree/README.md).

## Key ideas

- Linked nodes use pointers to represent child relationships.
- Recursive traversal and update functions rely on a clear base case for missing children.
- Dynamically allocated nodes require explicit cleanup.
