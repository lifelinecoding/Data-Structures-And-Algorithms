# Array deletion

These programs demonstrate removing an element from an array. The central choice is whether the remaining elements must keep their original order.

## Suggested learning sequence

1. [`DeletionWithOrder.c`](./DeletionWithOrder.c) — remove an element and shift later elements left to preserve order.
2. [`DeletionWithoutOrder.c`](./DeletionWithoutOrder.c) — compare the unordered approach, where the final element can fill the removed position.
3. Trace the logical length separately from the array's allocated capacity after deletion.

## Key ideas

- Ordered deletion can move many elements and take linear time.
- Unordered deletion can be constant time after the position is known, but changes element order.
- Validate the requested position and update the logical element count.
