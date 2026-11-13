# Hashing

Hashing stores a key at an array position computed by a hash function, giving insertion, lookup, and deletion an expected time complexity of **O(1)** when keys are distributed well. This folder demonstrates integer-key hash tables and several ways to resolve collisions.

## Suggested learning sequence

1. Read [`definition.h`](./definition.h) to see the table, slot-status, and linked-list node structures shared by the examples.
2. Study [`Open_Hashing.h`](./Open_Hashing.h) for **separate chaining**: each table index points to a linked list of keys that hash to that index.
3. Study [`Closed_Hashing.h`](./Closed_Hashing.h) for **open addressing**, where every key is stored directly in the table and collisions are resolved by probing.
4. Run and modify [`Implementation.c`](./Implementation.c). It contains examples for separate chaining, linear probing, quadratic probing, and currently runs the quadratic-probing example.

## Current contents

- The hash functions use the division method (`key % table_size`), with negative results converted to a non-negative index.
- Separate chaining supports table creation, insertion, lookup, deletion, display, and table freeing through `Open_Hash_Table`.
- Closed hashing uses `EMPTY`, `OCCUPIED`, and `DELETED` slot states so that a deleted key does not prematurely end a probe sequence.
- `Closed_Hashing.h` implements linear probing, quadratic probing, and double hashing, each with insert, search, and delete operations.

## Key ideas

- A collision occurs when two keys map to the same initial table index. Separate chaining keeps colliding keys in a linked list; open addressing searches for another slot according to a probe sequence.
- With open addressing, performance declines as the table fills. The examples use a fixed-size table and do not resize it, so choose a size that leaves free slots.
- A deleted open-addressing slot is marked `DELETED` rather than `EMPTY`; searches must continue past it because another colliding key may occur later in the sequence.
- The examples accept duplicate keys and are intended for learning rather than as a production-ready hash-table library.

## Build and run

Compile the driver from the repository root with a Windows-compatible C compiler, since [`Implementation.c`](./Implementation.c) includes `windows.h`:

```powershell
gcc "Hashing/Implementation.c" -o hashing.exe
.\hashing.exe
```

Change the uncommented block in `Implementation.c` to experiment with a different collision-resolution strategy.
