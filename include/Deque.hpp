#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class Deque
 * @brief A template-based double-ended queue (Deque) implementation.
 *
 * Allows insertion and deletion from both front and rear ends.
 * Uses a doubly-linked list for efficient operations at both ends.
 *
 * @tparam T The data type stored in the deque.
 */
template <typename T>
class Deque {
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
     * @brief Default constructor initializes an empty deque.
     */
    Deque() : head(nullptr), tail(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~Deque() {
        clear();
    }
    
    /**
     * @brief Inserts an element at the front.
     * @param value The value to insert.
     * Time Complexity: O(1)
     */
    void pushFront(const T& value) {
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
     * @brief Inserts an element at the rear.
     * @param value The value to insert.
     * Time Complexity: O(1)
     */
    void pushRear(const T& value) {
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
     * @brief Removes and returns the front element.
     * @return The front element.
     * Time Complexity: O(1)
     */
    T popFront() {
        if (!head) {
            throw std::underflow_error("Deque is empty");
        }
        
        Node* temp = head;
        T data = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        size--;
        return data;
    }
    
    /**
     * @brief Removes and returns the rear element.
     * @return The rear element.
     * Time Complexity: O(1)
     */
    T popRear() {
        if (!tail) {
            throw std::underflow_error("Deque is empty");
        }
        
        Node* temp = tail;
        T data = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        size--;
        return data;
    }
    
    /**
     * @brief Returns the front element without removing it.
     * Time Complexity: O(1)
     */
    T peekFront() const {
        if (!head) {
            throw std::underflow_error("Deque is empty");
        }
        return head->data;
    }
    
    /**
     * @brief Returns the rear element without removing it.
     * Time Complexity: O(1)
     */
    T peekRear() const {
        if (!tail) {
            throw std::underflow_error("Deque is empty");
        }
        return tail->data;
    }
    
    /**
     * @brief Checks if the deque is empty.
     * Time Complexity: O(1)
     */
    bool isEmpty() const {
        return size == 0;
    }
    
    /**
     * @brief Returns the number of elements in the deque.
     * Time Complexity: O(1)
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Displays all elements in the deque.
     * Time Complexity: O(n)
     */
    void display() const {
        Node* current = head;
        std::cout << "Deque: ";
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    
    /**
     * @brief Clears all elements from the deque.
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
};

#endif // DEQUE_HPP
