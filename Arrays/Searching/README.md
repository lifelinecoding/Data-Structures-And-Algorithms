# Searching arrays

Search algorithms locate values in an array. The important distinction in this folder is whether the algorithm requires sorted input.

## Suggested learning sequence

1. [`LinearSearch.c`](./LinearSearch.c) — scan until a matching value is found or the array ends.
2. [`LinearSearchMultipleElements.c`](./LinearSearchMultipleElements.c) — continue scanning to report multiple matches.
3. [`BinarySearchIterative.c`](./BinarySearchIterative.c) — repeatedly narrow a sorted search range using a loop.
4. [`BinarySearchRecursive.c`](./BinarySearchRecursive.c) — express the same narrowing process recursively.

## Key ideas

- Linear search works on unsorted data and takes up to linear time.
- Binary search requires sorted data and takes logarithmic time, but depends on correct range boundaries.
- Compare the iterative and recursive versions using the same sorted input, including a missing target and boundary values.
