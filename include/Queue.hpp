#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class Queue
 * @brief A template-based queue (FIFO - First In First Out) implementation.
 *
 * Uses a linked list-based approach for dynamic memory management.
 *
 * @tparam T The data type stored in the queue.
 */
template <typename T>
class Queue {
private:
    /**
     * @struct Node
     * @brief Represents a single node in the queue.
     */
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* front;
    Node* rear;
    int size;
    
public:
    /**
     * @brief Default constructor initializes an empty queue.
     */
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~Queue() {
        clear();
    }
    
    /**
     * @brief Enqueues an element to the rear of the queue.
     * @param value The value to enqueue.
     * Time Complexity: O(1)
     */
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    /**
     * @brief Dequeues and returns the front element.
     * @return The front element.
     * Time Complexity: O(1)
     */
    T dequeue() {
        if (!front) {
            throw std::underflow_error("Queue underflow: cannot dequeue from empty queue");
        }
        
        Node* temp = front;
        T data = temp->data;
        front = front->next;
        
        if (!front) {
            rear = nullptr;
        }
        
        delete temp;
        size--;
        return data;
    }
    
    /**
     * @brief Returns the front element without removing it.
     * @return The front element.
     * Time Complexity: O(1)
     */
    T peek() const {
        if (!front) {
            throw std::underflow_error("Queue is empty");
        }
        return front->data;
    }
    
    /**
     * @brief Checks if the queue is empty.
     * Time Complexity: O(1)
     */
    bool isEmpty() const {
        return size == 0;
    }
    
    /**
     * @brief Returns the number of elements in the queue.
     * Time Complexity: O(1)
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Displays all elements in the queue from front to rear.
     * Time Complexity: O(n)
     */
    void display() const {
        Node* current = front;
        std::cout << "Queue (front to rear): ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "(empty)" << std::endl;
    }
    
    /**
     * @brief Clears all elements from the queue.
     * Time Complexity: O(n)
     */
    void clear() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }
};

#endif // QUEUE_HPP
