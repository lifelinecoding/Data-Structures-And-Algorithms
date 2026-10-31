# Arrays

An array stores elements in contiguous indexed positions. This folder introduces basic traversal and reversal, then links to focused guides for common operations and multidimensional arrays.

## Suggested learning sequence

1. [`Traversal.c`](./Traversal.c) — visit and display elements using indices.
2. [`ReverseArray.c`](./ReverseArray.c) — reverse the order of the stored elements.
3. [Insertion](./Insertion/README.md) and [Deletion](./Deletion/README.md) — compare shifting elements to preserve order with replacing an element from the end when order is irrelevant.
4. [Searching](./Searching/README.md) — find one or multiple values; compare linear search with binary search on sorted data.
5. [2D Arrays](./2D%20Arrays/README.md) and [3D Arrays](./3D%20Arrays/README.md) — extend indexed traversal to rows, columns, and layers.

## Key ideas

- Valid indices range from zero through `length - 1`.
- Traversal and reversal take linear time in the number of elements.
- Insertion or deletion within an array may require shifting later elements.
- Fixed-size arrays require capacity planning; check each example's declared size and input assumptions.
