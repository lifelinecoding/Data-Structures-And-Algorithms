# Two-dimensional arrays

The examples in this folder treat a two-dimensional array as a table of rows and columns. Learn the traversal pattern before applying it to matrix operations.

## Suggested learning sequence

1. [`Traversal.c`](./Traversal.c) — visit entries with nested row and column loops.
2. [`MatrixAddition.c`](./MatrixAddition.c) — add corresponding entries of compatible matrices.
3. [`MatrixTranspose.c`](./MatrixTranspose.c) — exchange row and column positions.
4. [`MatrixMultiplication.c`](./MatrixMultiplication.c) — compute row-by-column products; the inner loop accumulates products.
5. [`SparseMatrix.c`](./SparseMatrix.c) — explore a matrix-oriented example that focuses on sparse data.

## Key ideas

- An element is identified by two indices: row and column.
- Addition requires matching dimensions. Multiplication requires the first matrix's column count to match the second matrix's row count.
- A transpose swaps dimensions. Trace a small rectangular matrix to see why.
- Follow the dimensions and bounds used in each program; these examples are standalone learning programs.
