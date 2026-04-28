#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class DoublyLinkedList
 * @brief A template-based doubly linked list implementation.
 *
 * Supports bi-directional traversal with pointers to both next and previous nodes.
 *
 * @tparam T The data type stored in the list.
 */
template <typename T>
class DoublyLinkedList {
private:
    /**
     * @struct Node
     * @brief Represents a node with pointers to both next and previous nodes.
     */
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;
    
public:
    /**
     * @brief Default constructor initializes an empty list.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~DoublyLinkedList() {
        clear();
    }
    
    /**
     * @brief Inserts a value at the beginning of the list.
     * @param value The value to insert.
     * Time Complexity: O(1)
     */
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    /**
     * @brief Inserts a value at the end of the list.
     * @param value The value to insert.
     * Time Complexity: O(1)
     */
    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    /**
     * @brief Deletes the first node from the list.
     * Time Complexity: O(1)
     */
    void deleteFromBeginning() {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        
        Node* temp = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }
    
    /**
     * @brief Deletes the last node from the list.
     * Time Complexity: O(1)
     */
    void deleteFromEnd() {
        if (!tail) {
            throw std::underflow_error("List is empty");
        }
        
        Node* temp = tail;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }
    
    /**
     * @brief Displays all elements in forward direction.
     * Time Complexity: O(n)
     */
    void displayForward() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    
    /**
     * @brief Displays all elements in backward direction.
     * Time Complexity: O(n)
     */
    void displayBackward() const {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
    
    /**
     * @brief Searches for a value in the list.
     * @param value The value to search for.
     * @return The index of the value, or -1 if not found.
     * Time Complexity: O(n)
     */
    int search(const T& value) const {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    
    /**
     * @brief Returns the number of elements in the list.
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Clears all elements from the list.
     * Time Complexity: O(n)
     */
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    /**
     * @brief Checks if the list is empty.
     */
    bool isEmpty() const {
        return size == 0;
    }
};

#endif // DOUBLYLINKEDLIST_HPP
