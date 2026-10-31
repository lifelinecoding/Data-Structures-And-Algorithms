# Sorting algorithms

Sorting rearranges values into an ordered sequence. The implementations here span elementary comparison sorts, divide-and-conquer methods, and non-comparison sorts.

## Suggested learning sequence

1. [`SelectionSort.c`](./SelectionSort.c) and [`BubbleSort.c`](./BubbleSort.c) — begin with simple comparison-based passes.
2. [`InsertionSort.c`](./InsertionSort.c) — study inserting each value into an already ordered prefix.
3. [`MergeSort.c`](./MergeSort.c) and [`QuickSort.c`](./QuickSort.c) — compare divide-and-conquer strategies.
4. [`HeapSort.c`](./HeapSort.c) — connect sorting to the heap data structure.
5. [`CountSort.c`](./CountSort.c) and [`RadixSort.c`](./RadixSort.c) — examine sorting approaches based on values or digits rather than pairwise comparisons.

## Compare the algorithms

- Trace each algorithm on the same short input, including duplicate values and already sorted data.
- Compare time complexity, additional memory, stability, and assumptions about the input range.
- Non-comparison sorts can be efficient for suitable key domains, but their constraints differ from comparison sorts.
- Check the implementation's input size, value range, and output behavior before using it with other data.
