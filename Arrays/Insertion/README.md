# Array insertion

These programs show how to insert an element into an array, with or without preserving the order of existing values.

## Suggested learning sequence

1. [`InsertionWithOrder.c`](./InsertionWithOrder.c) — shift elements to open the requested position.
2. [`InsertionWithoutOrder.c`](./InsertionWithoutOrder.c) — compare insertion when the order of existing values does not matter.
3. Trace the array's logical length and available capacity before and after the insertion.

## Key ideas

- Ordered insertion may shift many elements and take linear time.
- An unordered insertion can use an available slot without shifting, but may rearrange values.
- Check both capacity and the validity of the insertion position before writing.
