# Graphs

A graph models vertices connected by edges. This folder contains shared graph structures, adjacency-matrix and adjacency-list implementations, traversal routines, and a Prim minimum spanning tree implementation.

## Suggested learning sequence

1. Read [`definition.h`](./definition.h) for the shared `Matrix_Graph`, `List_Graph`, and adjacency-list node structures.
2. Compare the [adjacency-matrix representation](./Adjacency%20Matrix%20Representation/README.md) with the [adjacency-list representation](./Adjacency%20List%20Representation/README.md).
3. Review [`Minimum_Spanning_Tree.h`](./Minimum_Spanning_Tree.h) for Prim's algorithm on an adjacency-list graph.

## Current contents

- Both graph representations support directed or undirected weighted edges, edge lookup and removal, neighbor/degree operations, and graph display.
- Breadth-first search and depth-first search are implemented for both representations.
- Prim's minimum spanning tree routine is provided for adjacency-list graphs.
- Each representation folder includes a C driver demonstrating its current example.

## Key ideas

- An adjacency matrix uses space proportional to the square of the number of vertices and provides direct edge lookup. Its current implementation uses `0` for no edge, so it cannot represent zero-weight edges.
- An adjacency list stores one linked list per vertex and is more space-efficient for sparse graphs, though edge lookup requires searching a vertex's list.
- Prim's routine is intended for a connected, weighted graph; see its implementation for current assumptions and limitations.
