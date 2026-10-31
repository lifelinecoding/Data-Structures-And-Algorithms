# Linked lists

Linked lists connect separately allocated nodes rather than storing values in one contiguous array. This topic is divided into singly linked, doubly linked, and circular forms.

## Suggested learning sequence

1. [Singly Linked List](./Singly%20Linked%20List/README.md) — begin with one link per node, then study traversal, search, reversal, insertion, and deletion.
2. [Doubly Linked List](./Doubly%20Linked%20List/README.md) — add a previous link and study its effect on traversal and updates.
3. [Circular Linked List](./Circular%20Linked%20List/README.md) — connect the final node back to the first and learn how traversal termination changes.

## Key ideas

- A node stores data and one or more links to other nodes.
- Insertion and deletion can avoid shifting an array, but require correctly updating links.
- Traversal must stop at the right condition; circular lists do not terminate at a null next pointer.
- Dynamic allocation means each node must eventually be released.
