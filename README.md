# Data Structures and Algorithms

Welcome to the official repository for our **Data Structures and Algorithms** course! This repository contains all the code, live lecture demonstrations, problem solutions, and resource materials covered during our interactive classroom sessions.

Designed specifically for students, this hands-on collection serves as a practical reference to help you master fundamental computer science concepts, prepare for technical interviews, and build efficient software.

This repository is a collection of small, hands-on examples for learning fundamental data structures and algorithms. The checked-in exercises are primarily written in C and are organized by topic. Most source files are standalone programs with their own `main` function, so they are intended to be explored and compiled individually rather than built as one application.

## Purpose & Goals

- **Classroom Companion:** Clean, documented implementations of algorithms and data structures written during live coding sessions.

- **Conceptual Depth:** Step-by-step implementations starting from foundational principles to advanced optimization techniques.

- **Interview Readiness:** Solutions focused on core problem-solving patterns common in technical assessments and coding rounds.

## Repository contents

| Topic | What you will find |
| --- | --- |
| [Prerequisites](./Prerequisites/) | C structures, Nested structures, Arrays of structures, Dynamic memory allocation, and a Call-stack visualization. |
| [Arrays](./Arrays/) | 1D, 2D, and 3D Traversal; Ordered and unordered insertion/deletion; reversal; Linear and binary search; Matrix addition, Multiplication, Transpose, and Sparse-matrix examples. |
| [Linked List](./Linked%20List/) | Singly and doubly linked lists, Circular variants, Traversal, Insertion, Deletion, Searching, Reversal. |
| [Stack](./Stack/) | Array and linked-list-based stack implementations, Infix, Postfix, and Prefix expression conversions. |
| [Queue](./Queue/) | Simple and circular array queues, Linked-list-based queue. |
| [Tree](./Tree/) | Array-based tree storage and traversal, Linked tree, Binary tree, Separate header .h files for Preorder, Inorder Postorder traversal helpers and definition, Implementation and Insertion/Deletion and other operations in Binary Search Tree, AVL tree, Separate header file for AVL tree operations and rotations (LL, LR, RL and RR rotations), Insertion/Deletion in AVL tree.|
| [Graph](./Graph/) |Adjacency Matrix Representation, Adjacency List Representation, Weighted & Unweighted graph, Graph traversal (Breadth First Search, Depth First Search), Spanning Tree, Minimum Spanning Tree, Prims Algorithm, Krushkal Algorithm.|
| [Hashing](./Hashing/) |Under Progress.......|
| [Sorting](./Sorting/) | Bubble Sort, Counting Sort, Heap Sort, Insertion Sort, Merge Sort, Quick Sort, Radix Sort, and Selection Sort. |
| [Problems](./Problems/) | Character frequency, Element counting, Odd-occurrence detection, Parentheses matching, Linked-list palindrome exercise. |

The directory layout follows these topic folders; individual files demonstrate a particular operation or algorithm. There are currently no graph or hashing examples, nor implementations of binary search trees or AVL trees, in the checked-in source.

## Languages & Tools

- **Primary Language:** C (Main goal is to teach students to make everything from scratch)

- **Build & Run:** Standard IDEs (VS Code, IntelliJ IDEA, Eclipse) or command-line compilers.

## Getting started

1. Clone the repository:

   ```sh
   git clone https://github.com/lifelinecoding/Data-Structures-And-Algorithms.git
   cd Data-Structures-And-Algorithms
   ```

2. Choose a `.c` file in the topic folder you want to study.

3. Compile that source file on its own. For example, with GCC on Windows:

   ```powershell
   gcc "Arrays/Searching/LinearSearch.c" -o linear-search.exe
   .\linear-search.exe
   ```

   MinGW-w64 or another GCC distribution can be used. Some examples include the Windows-specific `windows.h` header, so a native Windows GCC toolchain is the most compatible choice. Use a C compiler and command appropriate for your platform for files that do not depend on Windows headers.

## How to use the examples

- Read and run one source file at a time; there is no repository-wide build system.
- Trace the code with small inputs, then try implementing the operation yourself before referring to the example.
- Compare variants, such as ordered versus unordered array operations or array-based versus linked implementations.
- Treat the programs as learning examples, not as a unified production-ready library. Review each program's input assumptions and behavior before reusing it.

## Contributing

Found an issue or have an improvement? Open an issue or submit a pull request with a clear description of the change. Contributions that add focused examples, improve explanations, or correct algorithm behavior are welcome.

## For Students

If you find this repository helpful for your learning, don't forget to give it a star!
