# Data Structures - C++17

A comprehensive library of 15 fundamental and advanced data structures implemented in C++17 using templates and manual memory management.

## Repository Structure

data-structures/
├── include/
│   ├── SinglyLinkedList.hpp
│   ├── DoublyLinkedList.hpp
│   ├── CircularLinkedList.hpp
│   ├── Stack.hpp
│   ├── Queue.hpp
│   ├── Deque.hpp
│   ├── BinarySearchTree.hpp
│   ├── AVLTree.hpp
│   ├── MinHeap.hpp
│   ├── MaxHeap.hpp
│   ├── Trie.hpp
│   ├── HashTable.hpp
│   ├── Graph.hpp
│   ├── DisjointSet.hpp
│   └── SegmentTree.hpp
├── src/
│   └── main.cpp
└── README.md

## Implemented Structures

### Linear Data Structures
* Singly, Doubly, and Circular Linked Lists
* Stack & Queue (LIFO/FIFO)
* Deque (Double-ended Queue)

### Hierarchical Data Structures
* Binary Search Tree (Unbalanced)
* AVL Tree (Self-balancing)
* Min & Max Heaps (Priority Queues)
* Trie (Prefix Tree)

### Advanced Data Structures
* Hash Table (Chaining collision handling)
* Graph (Adjacency List with BFS/DFS)
* Disjoint Set (Union-Find with Path Compression)
* Segment Tree (Range Queries)

## Time Complexity Summary

| Data Structure | Insertion | Deletion | Search |
|---|---|---|---|
| Linked Lists | O(1)* | O(n) | O(n) |
| Stack / Queue / Deque | O(1) | O(1) | O(n) |
| BST (Average) | O(log n) | O(log n) | O(log n) |
| AVL Tree | O(log n) | O(log n) | O(log n) |
| Min/Max Heap | O(log n) | O(log n) | O(1)** |
| Hash Table (Avg) | O(1) | O(1) | O(1) |
| Disjoint Set | O(α(n)) | - | O(α(n)) |
| Segment Tree | O(log n) | O(log n) | O(log n) |

*At ends; **Peek operation; α(n) is the inverse Ackermann function.

## Compilation

Requires a C++17 compatible compiler (g++, clang, or MSVC).

```bash
g++ -std=c++17 -I./include src/main.cpp -o ds_tests && ./ds_tests
