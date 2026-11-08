# Adjacency-list representation

This folder contains a C graph API backed by a linked list of neighbors for each vertex, plus a driver demonstrating graph construction and Prim's minimum spanning tree routine.

## Suggested learning sequence

1. [`../definition.h`](../definition.h) — defines `List_Graph` and the linked-list `Node` used for each adjacency list.
2. [`Adjacency_List_Graph.h`](./Adjacency_List_Graph.h) — implements graph creation and cleanup, edge operations, weight and neighbor queries, degree operations, list display, and breadth-first and depth-first searches.
3. [`../Minimum_Spanning_Tree.h`](../Minimum_Spanning_Tree.h) — implements Prim's algorithm for a `List_Graph`.
4. [`AdjacencyListGraph.c`](./AdjacencyListGraph.c) — builds an undirected weighted graph and runs Prim's algorithm.

## Representation and behavior

- Each vertex stores a linked list of its outgoing neighbors and edge weights.
- Adding or removing an edge in an undirected graph updates both endpoint lists.
- The representation can use less space than a matrix for sparse graphs, but edge lookup searches a vertex's list.
- Breadth-first search and depth-first search routines are available in the graph header.

## Limitations to keep in mind

- Prim's implementation is intended for connected weighted graphs; it does not safely handle a disconnected graph.
- Some graph and traversal allocation results are not checked. Treat this as a teaching example rather than a production-ready graph library.
