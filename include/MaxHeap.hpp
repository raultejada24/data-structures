#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

/**
 * @class MaxHeap
 * @brief A template-based max heap (priority queue) implementation.
 *
 * Array-based binary heap where the parent is larger than its children.
 * The maximum element is always at the root (index 0).
 *
 * @tparam T The data type stored in the heap. Must support comparison operators.
 */
template <typename T>
class MaxHeap {
private:
    T* heap;
    int capacity;
    int size;
    
    /**
     * @brief Returns the index of the parent node.
     */
    int getParent(int index) const {
        return (index - 1) / 2;
    }
    
    /**
     * @brief Returns the index of the left child.
     */
    int getLeftChild(int index) const {
        return 2 * index + 1;
    }
    
    /**
     * @brief Returns the index of the right child.
     */
    int getRightChild(int index) const {
        return 2 * index + 2;
    }
    
    /**
     * @brief Moves a node up the heap to maintain max-heap property.
     * Time Complexity: O(log n)
     */
    void heapifyUp(int index) {
        while (index > 0 && heap[getParent(index)] < heap[index]) {
            std::swap(heap[index], heap[getParent(index)]);
            index = getParent(index);
        }
    }
    
    /**
     * @brief Moves a node down the heap to maintain max-heap property.
     * Time Complexity: O(log n)
     */
    void heapifyDown(int index) {
        int largest = index;
        int left = getLeftChild(index);
        int right = getRightChild(index);
        
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
    /**
     * @brief Doubles the capacity when needed.
     */
    void resizeHeap() {
        capacity *= 2;
        T* newHeap = new T[capacity];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }
    
public:
    /**
     * @brief Constructor with initial capacity.
     * @param initialCapacity The initial capacity of the heap.
     */
    MaxHeap(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        heap = new T[capacity];
    }
    
    /**
     * @brief Destructor deallocates the heap array.
     */
    ~MaxHeap() {
        delete[] heap;
    }
    
    /**
     * @brief Inserts a value into the heap.
     * @param value The value to insert.
     * Time Complexity: O(log n)
     */
    void insert(const T& value) {
        if (size == capacity) {
            resizeHeap();
        }
        
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    
    /**
     * @brief Removes and returns the maximum element.
     * @return The maximum element.
     * Time Complexity: O(log n)
     */
    T extractMax() {
        if (size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        
        T maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        
        if (size > 0) {
            heapifyDown(0);
        }
        
        return maxValue;
    }
    
    /**
     * @brief Returns the maximum element without removing it.
     * @return The maximum element.
     * Time Complexity: O(1)
     */
    T getMax() const {
        if (size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        return heap[0];
    }
    
    /**
     * @brief Checks if the heap is empty.
     * Time Complexity: O(1)
     */
    bool isEmpty() const {
        return size == 0;
    }
    
    /**
     * @brief Returns the number of elements in the heap.
     * Time Complexity: O(1)
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Displays all elements in the heap.
     * Time Complexity: O(n)
     */
    void display() const {
        std::cout << "MaxHeap: ";
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Clears all elements from the heap.
     * Time Complexity: O(1)
     */
    void clear() {
        size = 0;
    }
};

#endif // MAXHEAP_HPP
