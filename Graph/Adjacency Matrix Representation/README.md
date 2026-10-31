# Adjacency-matrix representation

This folder contains a small C graph API backed by a two-dimensional integer matrix. Read the shared structure first, then inspect the API header before the driver program.

## Suggested learning sequence

1. [`../definition.h`](../definition.h) — `Matrix_Graph` stores a vertex count, a directedness flag, and the matrix.
2. [`Adjacency_Matrix_Graph.h`](./Adjacency_Matrix_Graph.h) — implements `createGraph`, `freeGraph`, `addEdge`, `removeEdge`, `isEdgeExist`, `weight`, and `neighbors`.
3. [`AdjacencyMatrixGraph.c`](./AdjacencyMatrixGraph.c) — driver entry point; it currently creates no graph or demonstration output.

## Representation and behavior

- Vertices are indexed from `0` through `vertices - 1`.
- A nonzero matrix value represents an edge and stores its weight. A zero value represents no edge.
- For an undirected graph, adding or removing an edge updates both matrix directions.
- `neighbors` counts the nonzero entries in one row.
- Matrix storage is quadratic in the number of vertices, even when few edges exist.

## Limitations to keep in mind

- Because zero represents no edge, zero-weight edges cannot be represented.
- The API checks null graphs and vertex bounds in most operations; invalid bounds are reported to standard output.
- The allocation code does not check whether each allocation succeeds. Treat this as a teaching example rather than a production-ready graph library.
