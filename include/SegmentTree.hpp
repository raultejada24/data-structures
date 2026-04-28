#ifndef SEGMENTTREE_HPP
#define SEGMENTTREE_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @class SegmentTree
 * @brief A segment tree for efficient range queries and updates.
 *
 * Supports range sum queries and point updates in O(log n) time.
 * Built on top of an array for compact memory representation.
 *
 * @tparam T The data type stored in the tree. Must support addition.
 */
template <typename T>
class SegmentTree {
private:
    std::vector<T> tree;
    std::vector<T> arr;
    int n;
    
    /**
     * @brief Recursively builds the segment tree.
     * @param node Current node index in the tree.
     * @param start Start index of the range.
     * @param end End index of the range.
     * Time Complexity: O(n)
     */
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);
            
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    /**
     * @brief Recursively updates a point in the tree.
     * @param node Current node index in the tree.
     * @param start Start index of the range.
     * @param end End index of the range.
     * @param index Index to update.
     * @param delta The value to add at the index.
     * Time Complexity: O(log n)
     */
    void updatePoint(int node, int start, int end, int index, T delta) {
        if (start == end) {
            arr[index] += delta;
            tree[node] += delta;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            if (index <= mid) {
                updatePoint(leftChild, start, mid, index, delta);
            } else {
                updatePoint(rightChild, mid + 1, end, index, delta);
            }
            
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    /**
     * @brief Recursively queries a range sum.
     * @param node Current node index in the tree.
     * @param start Start index of the range.
     * @param end End index of the range.
     * @param queryStart Start of query range.
     * @param queryEnd End of query range.
     * @return The sum of elements in the query range.
     * Time Complexity: O(log n)
     */
    T queryRange(int node, int start, int end, int queryStart, int queryEnd) const {
        // No overlap
        if (queryStart > end || queryEnd < start) {
            return T();
        }
        
        // Complete overlap
        if (queryStart <= start && end <= queryEnd) {
            return tree[node];
        }
        
        // Partial overlap
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        T leftSum = queryRange(leftChild, start, mid, queryStart, queryEnd);
        T rightSum = queryRange(rightChild, mid + 1, end, queryStart, queryEnd);
        
        return leftSum + rightSum;
    }
    
public:
    /**
     * @brief Constructor builds the segment tree from an array.
     * @param array The input array to build the tree from.
     */
    SegmentTree(const std::vector<T>& array) : arr(array), n(array.size()) {
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }
    
    /**
     * @brief Updates a single element and propagates the change up the tree.
     * @param index The index to update.
     * @param delta The value to add.
     * Time Complexity: O(log n)
     */
    void update(int index, T delta) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Index out of range");
        }
        updatePoint(0, 0, n - 1, index, delta);
    }
    
    /**
     * @brief Queries the sum of elements in a range [left, right].
     * @param left The left boundary of the range (inclusive).
     * @param right The right boundary of the range (inclusive).
     * @return The sum of elements in the range.
     * Time Complexity: O(log n)
     */
    T query(int left, int right) const {
        if (left < 0 || right >= n || left > right) {
            throw std::out_of_range("Invalid range");
        }
        return queryRange(0, 0, n - 1, left, right);
    }
    
    /**
     * @brief Displays the original array.
     */
    void display() const {
        std::cout << "Segment Tree Array: ";
        for (const T& val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Returns the size of the array.
     */
    int getSize() const {
        return n;
    }
};

#endif // SEGMENTTREE_HPP
