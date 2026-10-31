# Adjacency-list representation

An adjacency list stores, for each vertex, the vertices connected to it. This can be more space-efficient than a matrix for sparse graphs.

## Folder status

There are currently no source files in this folder. Use the [Graph guide](../README.md) and the [adjacency-matrix example](../Adjacency%20Matrix%20Representation/README.md) to study the existing graph material.

## Suggested implementation sequence

1. Choose a representation for each vertex's neighbor collection.
2. Add and remove directed or undirected edges while keeping the representation consistent.
3. Implement neighbor lookup, then compare storage and lookup trade-offs with the matrix representation.
4. Add graph traversal only after the basic representation operations are clear.
