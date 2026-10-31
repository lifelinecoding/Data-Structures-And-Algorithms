# Binary-tree traversal helpers

This folder contains [`traversal.h`](./traversal.h), a header file for binary-tree traversal helpers.

## Suggested learning sequence

1. Read the shared tree type in [`../definition.h`](../definition.h).
2. Inspect `traversal.h` to see which traversal helpers are declared.
3. Trace preorder, inorder, and postorder on a small tree, then compare when each visits the root.

## Key ideas

- Recursive traversals need a base case for a missing node.
- Inorder traversal visits values in sorted order only when the tree satisfies binary-search-tree ordering.
- This folder contains a header, not a standalone program to run.
