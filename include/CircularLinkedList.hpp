#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class CircularLinkedList
 * @brief A template-based circular linked list implementation.
 *
 * The last node points back to the first node, creating a ring structure.
 * Supports insertion, deletion, and circular traversal.
 *
 * @tparam T The data type stored in the list.
 */
template <typename T>
class CircularLinkedList {
private:
    /**
     * @struct Node
     * @brief Represents a single node in the circular linked list.
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
    CircularLinkedList() : head(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~CircularLinkedList() {
        clear();
    }
    
    /**
     * @brief Inserts a value at the beginning of the list.
     * @param value The value to insert.
     * Time Complexity: O(n) - O(1) if list is not empty
     */
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            head = newNode;
        }
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
            newNode->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    
    /**
     * @brief Deletes the first node from the list.
     * Time Complexity: O(n)
     */
    void deleteFromBeginning() {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        }
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
        
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != head) {
                current = current->next;
            }
            delete current->next;
            current->next = head;
        }
        size--;
    }
    
    /**
     * @brief Searches for a value in the list.
     * @param value The value to search for.
     * @return The index of the value, or -1 if not found.
     * Time Complexity: O(n)
     */
    int search(const T& value) const {
        if (!head) return -1;
        
        Node* current = head;
        int index = 0;
        do {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        } while (current != head);
        
        return -1;
    }
    
    /**
     * @brief Displays all elements in the circular list.
     * @param limit Maximum number of elements to display (to prevent infinite loop).
     * Time Complexity: O(n)
     */
    void display(int limit = -1) const {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        Node* current = head;
        int count = 0;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
            count++;
            if (limit > 0 && count >= limit) break;
        } while (current != head);
        std::cout << "(circular to head)" << std::endl;
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
        if (!head) return;
        
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
        size = 0;
    }
    
    /**
     * @brief Checks if the list is empty.
     */
    bool isEmpty() const {
        return size == 0;
    }
};

#endif // CIRCULARLINKEDLIST_HPP
