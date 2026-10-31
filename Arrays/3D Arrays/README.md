# Three-dimensional arrays

This folder demonstrates traversal through a three-dimensional array, which can be viewed as layers containing rows and columns.

## Suggested learning sequence

1. [`Traversal.c`](./Traversal.c) — follow its nested loops one level at a time: layer, row, then column.
2. Trace the three indices for a small example and relate each loop bound to the corresponding dimension.

## Key ideas

- Each element requires three indices.
- Traversal visits every element, so its work grows with the product of the three dimensions.
- Check the declared dimensions before using an index; each index must remain within its own bound.
