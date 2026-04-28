#include <iostream>
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "CircularLinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"
#include "MinHeap.hpp"
#include "MaxHeap.hpp"
#include "Trie.hpp"
#include "HashTable.hpp"
#include "Graph.hpp"
#include "DisjointSet.hpp"
#include "SegmentTree.hpp"

int main() {
    std::cout << "========== Data Structures Test Suite ==========" << std::endl << std::endl;
    
    // 1. Singly Linked List Test
    std::cout << "1. Singly Linked List:" << std::endl;
    {
        SinglyLinkedList<int> list;
        list.insertAtBeginning(10);
        list.insertAtBeginning(20);
        list.insertAtBeginning(30);
        list.display();
        list.deleteFromBeginning();
        list.display();
        std::cout << "Element found: " << (list.search(10) ? "Yes" : "No") << std::endl << std::endl;
    }
    
    // 2. Doubly Linked List Test
    std::cout << "2. Doubly Linked List:" << std::endl;
    {
        DoublyLinkedList<int> list;
        list.insertAtBeginning(5);
        list.insertAtEnd(15);
        list.insertAtBeginning(1);
        list.display();
        list.deleteFromEnd();
        list.display();
        std::cout << std::endl;
    }
    
    // 3. Circular Linked List Test
    std::cout << "3. Circular Linked List:" << std::endl;
    {
        CircularLinkedList<int> list;
        list.insertAtBeginning(100);
        list.insertAtBeginning(200);
        list.insertAtBeginning(300);
        list.display();
        std::cout << "Size: " << list.getSize() << std::endl << std::endl;
    }
    
    // 4. Stack Test
    std::cout << "4. Stack (LIFO):" << std::endl;
    {
        Stack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "Top element: " << stack.peek() << std::endl;
        std::cout << "Is Empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
        stack.pop();
        std::cout << "After pop, top: " << stack.peek() << std::endl << std::endl;
    }
    
    // 5. Queue Test
    std::cout << "5. Queue (FIFO):" << std::endl;
    {
        Queue<int> queue;
        queue.enqueue(5);
        queue.enqueue(10);
        queue.enqueue(15);
        std::cout << "Front element: " << queue.peek() << std::endl;
        queue.dequeue();
        std::cout << "After dequeue, front: " << queue.peek() << std::endl << std::endl;
    }
    
    // 6. Deque Test
    std::cout << "6. Deque (Double-Ended Queue):" << std::endl;
    {
        Deque<int> deque;
        deque.pushFront(10);
        deque.pushRear(20);
        deque.pushFront(5);
        std::cout << "Front: " << deque.peekFront() << ", Rear: " << deque.peekRear() << std::endl;
        deque.popFront();
        std::cout << "After popFront, Front: " << deque.peekFront() << std::endl << std::endl;
    }
    
    // 7. Binary Search Tree Test
    std::cout << "7. Binary Search Tree:" << std::endl;
    {
        BinarySearchTree<int> bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        
        std::cout << "Inorder: ";
        bst.inorder();
        std::cout << std::endl;
        
        std::cout << "Preorder: ";
        bst.preorder();
        std::cout << std::endl;
        
        std::cout << "Postorder: ";
        bst.postorder();
        std::cout << std::endl << std::endl;
    }
    
    // 8. AVL Tree Test
    std::cout << "8. AVL Tree (Self-Balancing):" << std::endl;
    {
        AVLTree<int> avl;
        avl.insert(10);
        avl.insert(5);
        avl.insert(15);
        avl.insert(2);
        avl.insert(7);
        
        std::cout << "AVL Tree (Balanced): ";
        avl.inorder();
        std::cout << std::endl << std::endl;
    }
    
    // 9. Min Heap Test
    std::cout << "9. Min Heap:" << std::endl;
    {
        MinHeap<int> minHeap;
        minHeap.insert(30);
        minHeap.insert(20);
        minHeap.insert(10);
        minHeap.insert(40);
        minHeap.insert(5);
        
        std::cout << "Min element (should be 5): " << minHeap.getMin() << std::endl;
        minHeap.extractMin();
        std::cout << "After extractMin: " << minHeap.getMin() << std::endl << std::endl;
    }
    
    // 10. Max Heap Test
    std::cout << "10. Max Heap:" << std::endl;
    {
        MaxHeap<int> maxHeap;
        maxHeap.insert(30);
        maxHeap.insert(20);
        maxHeap.insert(10);
        maxHeap.insert(40);
        maxHeap.insert(50);
        
        std::cout << "Max element (should be 50): " << maxHeap.getMax() << std::endl;
        maxHeap.extractMax();
        std::cout << "After extractMax: " << maxHeap.getMax() << std::endl << std::endl;
    }
    
    // 11. Trie Test
    std::cout << "11. Trie (Prefix Tree):" << std::endl;
    {
        Trie trie;
        trie.insert("hello");
        trie.insert("world");
        trie.insert("help");
        
        std::cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << std::endl;
        std::cout << "Search 'he': " << (trie.search("he") ? "Found" : "Not Found") << std::endl;
        std::cout << "StartsWith 'hel': " << (trie.startsWith("hel") ? "Yes" : "No") << std::endl << std::endl;
    }
    
    // 12. Hash Table Test
    std::cout << "12. Hash Table (with Chaining):" << std::endl;
    {
        HashTable<std::string, int> hashTable;
        hashTable.insert("Alice", 25);
        hashTable.insert("Bob", 30);
        hashTable.insert("Charlie", 35);
        
        std::cout << "Search 'Alice': " << (hashTable.search("Alice") ? "Found" : "Not Found");
        if (hashTable.search("Alice")) {
            std::cout << " (Age: " << hashTable.get("Alice") << ")";
        }
        std::cout << std::endl;
        
        hashTable.remove("Bob");
        std::cout << "After removing 'Bob': " << (hashTable.search("Bob") ? "Found" : "Not Found") << std::endl << std::endl;
    }
    
    // 13. Graph Test
    std::cout << "13. Graph (Adjacency List):" << std::endl;
    {
        Graph<int> graph;
        int v0 = graph.addVertex();
        int v1 = graph.addVertex();
        int v2 = graph.addVertex();
        int v3 = graph.addVertex();
        
        graph.addEdge(v0, v1, 1);
        graph.addEdge(v0, v2, 1);
        graph.addEdge(v1, v2, 1);
        graph.addEdge(v2, v3, 1);
        
        graph.display();
        graph.bfs(v0);
        graph.dfs(v0);
        std::cout << std::endl;
    }
    
    // 14. Disjoint Set Test
    std::cout << "14. Disjoint Set (Union-Find):" << std::endl;
    {
        DisjointSet ds(6);
        ds.unite(0, 1);
        ds.unite(1, 2);
        ds.unite(3, 4);
        
        std::cout << "Are 0 and 2 in same set? " << (ds.isSameSet(0, 2) ? "Yes" : "No") << std::endl;
        std::cout << "Are 0 and 3 in same set? " << (ds.isSameSet(0, 3) ? "Yes" : "No") << std::endl;
        std::cout << "Number of disjoint sets: " << ds.countSets() << std::endl << std::endl;
    }
    
    // 15. Segment Tree Test
    std::cout << "15. Segment Tree (Range Queries):" << std::endl;
    {
        std::vector<int> arr = {1, 3, 5, 7, 9, 11};
        SegmentTree<int> segTree(arr);
        
        segTree.display();
        std::cout << "Sum from index 0 to 3: " << segTree.query(0, 3) << std::endl;
        std::cout << "Sum from index 2 to 5: " << segTree.query(2, 5) << std::endl;
        
        segTree.update(2, 5);  // Add 5 to index 2
        std::cout << "After updating index 2 (+5), Sum from 0 to 3: " << segTree.query(0, 3) << std::endl << std::endl;
    }
    
    std::cout << "========== All Tests Completed Successfully ==========" << std::endl;
    
    return 0;
}
