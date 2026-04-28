# Data Structures - C++17 Professional Repository

A comprehensive C++17 library implementing 15 fundamental data structures with clean code principles, generics (templates), and manual memory management.

## Repository Structure

```
data-structures/
│
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
│
├── src/
│   └── main.cpp          # Test driver for all 15 data structures
│
└── README.md
```

## Data Structures Implemented

### Linear Data Structures

1. **Singly Linked List** - Unidirectional linked list
   - Operations: insert, delete, search, reverse, display
   - Time Complexity: O(n) for most operations

2. **Doubly Linked List** - Bidirectional linked list
   - Operations: insert at beginning/end, delete from both ends, traverse forward/backward
   - Time Complexity: O(1) at ends, O(n) in middle

3. **Circular Linked List** - Ring-structured linked list
   - Operations: insert, delete, circular traversal
   - Time Complexity: O(n) traversal, O(1) insert at beginning

4. **Stack** - LIFO (Last In First Out) data structure
   - Operations: push, pop, peek, isEmpty
   - Time Complexity: O(1) for all operations
   - Template-based for type flexibility

5. **Queue** - FIFO (First In First Out) data structure
   - Operations: enqueue, dequeue, peek, isEmpty
   - Time Complexity: O(1) for all operations
   - Template-based for type flexibility

6. **Deque** - Double-ended queue
   - Operations: pushFront, pushRear, popFront, popRear, peek at both ends
   - Time Complexity: O(1) at both ends

### Hierarchical Data Structures

7. **Binary Search Tree** - Unbalanced BST
   - Operations: insert, delete, search, traversals (inorder, preorder, postorder)
   - Time Complexity: O(log n) average, O(n) worst case (skewed tree)

8. **AVL Tree** - Self-balancing BST
   - Operations: insert with auto-balancing, delete with rotations, traversals
   - Time Complexity: O(log n) guaranteed for all operations
   - Rotations: left, right, left-right, right-left

9. **Min Heap** - Array-based binary heap
   - Operations: insert, extractMin, peek, heapify
   - Time Complexity: O(log n) for insert/extract, O(1) for peek

10. **Max Heap** - Array-based binary heap
    - Operations: insert, extractMax, peek, heapify
    - Time Complexity: O(log n) for insert/extract, O(1) for peek

11. **Trie** - Prefix tree for string operations
    - Operations: insert, search, startsWith (prefix search)
    - Time Complexity: O(m) where m is string length

### Advanced Data Structures

12. **Hash Table** - Hash table with chaining collision handling
    - Operations: insert, search, remove, collision handling via linked lists
    - Time Complexity: O(1) average, O(n) worst case (poor hash distribution)

13. **Graph** - Adjacency list representation with traversals
    - Operations: addVertex, addEdge, BFS, DFS
    - Time Complexity: O(V + E) for traversals
    - Supports directed weighted graphs

14. **Disjoint Set (Union-Find)** - Set operations with path compression
    - Operations: find with path compression, unite by rank, isSameSet
    - Time Complexity: O(α(n)) nearly O(1) where α is inverse Ackermann function
    - Applications: cycle detection, Kruskal's algorithm

15. **Segment Tree** - Range query tree
    - Operations: build O(n), query range sum O(log n), point update O(log n)
    - Time Complexity: O(log n) for queries and updates
    - Use case: range queries on arrays

## Compilation Instructions

### Requirements
- C++17 compatible compiler (g++, clang, or MSVC)
- Command line access

### Windows (MinGW)

```bash
g++ -std=c++17 -I./include src/main.cpp -o ds_tests
./ds_tests.exe
```

### Linux/macOS

```bash
g++ -std=c++17 -I./include src/main.cpp -o ds_tests
./ds_tests
```

### Online Compiler
If you don't have a local C++ compiler:
- **OnlineGDB**: https://www.onlinegdb.com/ (supports C++17)
- **Compiler Explorer**: https://godbolt.org/ (interactive compilation)
- **Replit**: https://replit.com/languages/cpp (cloud C++ IDE)

## Time Complexity Summary

| Data Structure | Insert | Delete | Search | Space |
|---|---|---|---|---|
| Singly Linked List | O(n) | O(n) | O(n) | O(n) |
| Doubly Linked List | O(1)* | O(1)* | O(n) | O(n) |
| Circular Linked List | O(n) | O(n) | O(n) | O(n) |
| Stack | O(1) | O(1) | O(n) | O(n) |
| Queue | O(1) | O(1) | O(n) | O(n) |
| Deque | O(1) | O(1) | O(n) | O(n) |
| Binary Search Tree | O(log n)** | O(log n)** | O(log n)** | O(n) |
| AVL Tree | O(log n) | O(log n) | O(log n) | O(n) |
| Min/Max Heap | O(log n) | O(log n) | O(n) | O(n) |
| Trie | O(m) | O(m) | O(m) | O(n) |
| Hash Table | O(1)† | O(1)† | O(1)† | O(n) |
| Graph (BFS/DFS) | - | - | O(V+E) | O(V) |
| Disjoint Set | O(α(n)) | - | O(α(n)) | O(n) |
| Segment Tree | - | O(log n) | O(log n) | O(n) |

*At ends only; **Average case, worst O(n); †Average case; m = string length; α(n) ≈ O(1)