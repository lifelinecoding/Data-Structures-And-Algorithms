# AVL trees

An AVL tree is a self-balancing binary search tree. It maintains a height-balance condition and uses rotations after updates when needed.

## Suggested learning sequence

1. [`AVL_Operations.h`](./AVL_Operations.h) — inspect the operation and rotation helpers.
2. [`AVL_Tree.c`](./AVL_Tree.c) — follow the AVL example and how it uses those helpers.
3. Draw the tree before and after a rotation; compare the single-rotation and double-rotation cases.
4. Trace how insertion or deletion changes subtree heights and balance.

## Key ideas

- AVL trees combine the BST ordering invariant with a height-balance invariant.
- Rotations change local structure while preserving the in-order sequence.
- Verify update behavior by checking both node ordering and balance after each operation.
