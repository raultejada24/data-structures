#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class Stack
 * @brief A template-based stack (LIFO - Last In First Out) implementation.
 *
 * Uses a linked list-based approach for dynamic memory management.
 *
 * @tparam T The data type stored in the stack.
 */
template <typename T>
class Stack {
private:
    /**
     * @struct Node
     * @brief Represents a single node in the stack.
     */
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* top;
    int size;
    
public:
    /**
     * @brief Default constructor initializes an empty stack.
     */
    Stack() : top(nullptr), size(0) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~Stack() {
        clear();
    }
    
    /**
     * @brief Pushes an element onto the stack.
     * @param value The value to push.
     * Time Complexity: O(1)
     */
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    /**
     * @brief Removes and returns the top element.
     * @return The top element.
     * Time Complexity: O(1)
     */
    T pop() {
        if (!top) {
            throw std::underflow_error("Stack underflow: cannot pop from empty stack");
        }
        
        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
    
    /**
     * @brief Returns the top element without removing it.
     * @return The top element.
     * Time Complexity: O(1)
     */
    T peek() const {
        if (!top) {
            throw std::underflow_error("Stack is empty");
        }
        return top->data;
    }
    
    /**
     * @brief Checks if the stack is empty.
     * Time Complexity: O(1)
     */
    bool isEmpty() const {
        return size == 0;
    }
    
    /**
     * @brief Returns the number of elements in the stack.
     * Time Complexity: O(1)
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Displays all elements in the stack from top to bottom.
     * Time Complexity: O(n)
     */
    void display() const {
        Node* current = top;
        std::cout << "Stack (top to bottom): ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "(empty)" << std::endl;
    }
    
    /**
     * @brief Clears all elements from the stack.
     * Time Complexity: O(n)
     */
    void clear() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
};

#endif // STACK_HPP
