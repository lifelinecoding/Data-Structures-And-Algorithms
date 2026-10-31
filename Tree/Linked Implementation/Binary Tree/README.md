# Linked binary trees

A binary tree node has at most two child links. This folder contains a shared definition and a traversal helper folder, alongside binary-search and AVL variants.

## Suggested learning sequence

1. [`definition.h`](./definition.h) — inspect the shared binary-tree type.
2. [Traversal](./Traversal/README.md) — review the traversal helper declarations.
3. [Binary Search Tree](./Binary%20Search%20Tree/README.md) — add an ordering rule to the binary-tree structure.
4. [AVL Tree](./AVL%20Tree/README.md) — add a height-balance rule and rotations.

## Key ideas

- A binary tree's structure alone does not impose an ordering on values.
- Traversals such as preorder, inorder, and postorder differ in when they visit the current node relative to its children.
- Binary search trees and AVL trees share the binary-node foundation but maintain additional invariants.
