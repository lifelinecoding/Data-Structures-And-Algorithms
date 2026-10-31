# Graphs

A graph models vertices connected by edges. The available example begins with an adjacency matrix; the adjacency-list folder is currently empty.

## Suggested learning sequence

1. Read [`definition.h`](./definition.h) to understand the shared matrix-graph structure.
2. Continue to [Adjacency Matrix Representation](./Adjacency%20Matrix%20Representation/README.md) for the graph API and its current limitations.
3. Visit [Adjacency List Representation](./Adjacency%20List%20Representation/README.md) for the status of that representation.

## Key ideas

- A graph can be directed or undirected and may store edge weights.
- An adjacency matrix uses space proportional to the square of the number of vertices; checking a particular edge is direct.
- The current matrix implementation uses `0` to mean “no edge,” so a zero-weight edge cannot be distinguished from an absent edge.
- Breadth-first search, depth-first search, and spanning-tree algorithms are not implemented in the current graph folders.
