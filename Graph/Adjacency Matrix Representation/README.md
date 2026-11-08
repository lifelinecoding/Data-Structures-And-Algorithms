# Adjacency-matrix representation

This folder contains a C graph API backed by a two-dimensional integer matrix and a driver that exercises it.

## Suggested learning sequence

1. [`../definition.h`](../definition.h) — defines `Matrix_Graph` with a vertex count, directedness flag, and matrix.
2. [`Adjacency_Matrix_Graph.h`](./Adjacency_Matrix_Graph.h) — implements graph creation and cleanup, edge operations, weight and neighbor queries, degree operations, matrix display, and breadth-first and depth-first searches.
3. [`AdjacencyMatrixGraph.c`](./AdjacencyMatrixGraph.c) — creates an undirected graph, adds and removes edges, displays query results and the matrix, and runs DFS and BFS.

## Representation and behavior

- Vertices are indexed from `0` through `vertices - 1`.
- A nonzero matrix value represents an edge and stores its weight. A zero value represents no edge.
- For an undirected graph, adding or removing an edge updates both matrix directions.
- `neighbors` counts the nonzero entries in one row; degree functions are also provided.
- Matrix storage is quadratic in the number of vertices, even when few edges exist.

## Limitations to keep in mind

- Because zero represents no edge, zero-weight edges cannot be represented.
- The API checks null graphs and vertex bounds in most operations; invalid bounds are reported to standard output in operations that report them.
- Some allocation results are not checked, and traversal routines are intended as teaching examples rather than production-ready code.
