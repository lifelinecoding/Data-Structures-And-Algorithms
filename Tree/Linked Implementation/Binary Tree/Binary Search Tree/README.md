# Binary search trees

A binary search tree (BST) maintains an ordering relationship between each node and its subtrees. This folder contains the driver and operation declarations.

## Suggested learning sequence

1. [`BST_Operations.h`](./BST_Operations.h) — inspect the available BST operation declarations.
2. [`BinarySearchTree.c`](./BinarySearchTree.c) — follow how the example uses the BST operations.
3. Trace search and insertion using values that go left and right.
4. If deletion is covered, examine leaf, one-child, and two-child cases separately.

## Key ideas

- Search follows one branch at each comparison when the BST invariant holds.
- Operation cost depends on tree height; an unbalanced BST can become linear in the number of nodes.
- Check the actual implementation for which operations are complete and how duplicate values are handled.
