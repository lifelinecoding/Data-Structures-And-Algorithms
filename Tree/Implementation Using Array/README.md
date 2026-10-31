# Array-based tree

[`Implementation.c`](./Implementation.c) demonstrates representing a tree with array positions rather than explicit node pointers.

## Suggested learning sequence

1. Identify how the program maps a parent position to child positions.
2. Trace a small tree in the array and compare its layout with a drawn tree.
3. Continue to the [linked implementation](../Linked%20Implementation/README.md) to compare storage strategies.

## Key ideas

- Index relationships can make parent and child navigation direct for a compact tree.
- Sparse or irregular trees may leave unused array positions.
- Follow the implementation's chosen indexing convention; zero-based and one-based layouts differ.
