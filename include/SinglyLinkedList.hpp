#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class SinglyLinkedList
 * @brief A template-based singly linked list implementation.
 *
 * Supports insertion, deletion, search, and reverse operations.
 * Each node contains data and a pointer to the next node.
 *
 * @tparam T The data type stored in the list.
 */
template <typename T>
class SinglyLinkedList {
private:
    /**
     * @struct Node
     * @brief Represents a single node in the linked list.
     */
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    int size;
    
public:
    /**
     * @brief Default constructor initializes an empty list.
     */
    SinglyLinkedList() : head(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~SinglyLinkedList() {
        clear();
    }
    
    /**
     * @brief Inserts a value at the beginning of the list.
     * @param value The value to insert.
     * Time Complexity: O(1)
     */
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    /**
     * @brief Inserts a value at the end of the list.
     * @param value The value to insert.
     * Time Complexity: O(n)
     */
    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    
    /**
     * @brief Inserts a value at a specific position.
     * @param index The position to insert at.
     * @param value The value to insert.
     * Time Complexity: O(n)
     */
    void insertAtIndex(int index, const T& value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        
        if (index == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
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
        head = head->next;
        delete temp;
        size--;
    }
    
    /**
     * @brief Deletes the last node from the list.
     * Time Complexity: O(n)
     */
    void deleteFromEnd() {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        
        if (!head->next) {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    }
    
    /**
     * @brief Deletes a node at a specific position.
     * @param index The position to delete from.
     * Time Complexity: O(n)
     */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        
        if (index == 0) {
            deleteFromBeginning();
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
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
     * @brief Reverses the linked list in-place.
     * Time Complexity: O(n)
     */
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    /**
     * @brief Displays all elements in the list.
     * Time Complexity: O(n)
     */
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
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
        size = 0;
    }
    
    /**
     * @brief Checks if the list is empty.
     */
    bool isEmpty() const {
        return size == 0;
    }
};

#endif // SINGLYLINKEDLIST_HPP
