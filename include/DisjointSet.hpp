#ifndef DISJOINTSET_HPP
#define DISJOINTSET_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @class DisjointSet
 * @brief Union-Find data structure for tracking connectivity between elements.
 *
 * Efficiently handles union and find operations with path compression optimization.
 * Useful for detecting cycles and finding connected components.
 */
class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int numElements;
    
public:
    /**
     * @brief Constructor initializes the disjoint set.
     * @param n The number of elements in the set.
     */
    DisjointSet(int n) : numElements(n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Each element is its own parent initially
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    /**
     * @brief Finds the representative (root) of the set containing element x.
     * Uses path compression for optimization.
     * @param x The element to find the root for.
     * @return The representative of the set.
     * Time Complexity: O(α(n)) where α is the inverse Ackermann function (nearly O(1)).
     */
    int find(int x) {
        if (x < 0 || x >= numElements) {
            throw std::out_of_range("Element out of range");
        }
        
        // Path compression: make every node point directly to root
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        
        return parent[x];
    }
    
    /**
     * @brief Unions two sets containing elements x and y.
     * Uses union by rank for optimization.
     * @param x An element from the first set.
     * @param y An element from the second set.
     * Time Complexity: O(α(n)) where α is the inverse Ackermann function (nearly O(1)).
     */
    void unite(int x, int y) {
        if (x < 0 || x >= numElements || y < 0 || y >= numElements) {
            throw std::out_of_range("Element out of range");
        }
        
        int rootX = find(x);
        int rootY = find(y);
        
        // Already in the same set
        if (rootX == rootY) {
            return;
        }
        
        // Union by rank: attach smaller rank tree under larger rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    /**
     * @brief Checks if two elements are in the same set.
     * @param x The first element.
     * @param y The second element.
     * @return True if they are in the same set, false otherwise.
     * Time Complexity: O(α(n))
     */
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
    
    /**
     * @brief Finds the number of disjoint sets.
     * @return The number of connected components.
     * Time Complexity: O(n)
     */
    int countSets() const {
        int count = 0;
        for (int i = 0; i < numElements; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
    
    /**
     * @brief Displays the parent array (useful for debugging).
     */
    void display() const {
        std::cout << "Parent array: ";
        for (int i = 0; i < numElements; i++) {
            std::cout << parent[i] << " ";
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Displays the disjoint sets.
     */
    void displaySets() const {
        std::cout << "Disjoint Sets:" << std::endl;
        
        std::vector<bool> visited(numElements, false);
        
        for (int i = 0; i < numElements; i++) {
            if (!visited[i]) {
                int root = find(i);
                std::cout << "Set of " << root << ": ";
                
                for (int j = 0; j < numElements; j++) {
                    if (find(j) == root) {
                        std::cout << j << " ";
                        visited[j] = true;
                    }
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif // DISJOINTSET_HPP
