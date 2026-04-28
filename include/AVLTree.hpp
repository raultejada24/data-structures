#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

/**
 * @class AVLTree
 * @brief A template-based AVL (Adelson-Velsky and Landis) tree implementation.
 *
 * Self-balancing binary search tree that maintains a height-balanced property.
 * Supports insertion, deletion, and traversals with automatic rotations.
 *
 * @tparam T The data type stored in the tree. Must support comparison operators.
 */
template <typename T>
class AVLTree {
private:
    /**
     * @struct Node
     * @brief Represents a node in the AVL tree.
     */
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        
        Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;
    
    /**
     * @brief Returns the height of a node.
     */
    int getHeight(Node* node) const {
        return node ? node->height : 0;
    }
    
    /**
     * @brief Calculates the balance factor of a node.
     */
    int getBalanceFactor(Node* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    /**
     * @brief Updates the height of a node.
     */
    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }
    
    /**
     * @brief Right rotation.
     *        y                x
     *       / \              / \
     *      x   C      =>    A   y
     *     / \                  / \
     *    A   B                B   C
     */
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* B = x->right;
        
        x->right = y;
        y->left = B;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    /**
     * @brief Left rotation.
     *      x                y
     *     / \              / \
     *    A   y      =>    x   C
     *       / \          / \
     *      B   C        A   B
     */
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* B = y->left;
        
        y->left = x;
        x->right = B;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    /**
     * @brief Recursively inserts a value and rebalances the tree.
     * Time Complexity: O(log n)
     */
    Node* insertRecursive(Node* node, const T& value) {
        if (!node) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        } else {
            return node; // Duplicate
        }
        
        updateHeight(node);
        int balance = getBalanceFactor(node);
        
        // Left-Left case
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }
        
        // Right-Right case
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }
        
        // Left-Right case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        // Right-Left case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    /**
     * @brief Finds the minimum value node.
     */
    Node* findMin(Node* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    /**
     * @brief Recursively deletes a value and rebalances the tree.
     * Time Complexity: O(log n)
     */
    Node* deleteRecursive(Node* node, const T& value) {
        if (!node) {
            return nullptr;
        }
        
        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = deleteRecursive(node->right, minRight->data);
        }
        
        updateHeight(node);
        int balance = getBalanceFactor(node);
        
        // Left-Left case
        if (balance > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }
        
        // Left-Right case
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        // Right-Right case
        if (balance < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        
        // Right-Left case
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    /**
     * @brief Inorder traversal helper.
     */
    void inorderRecursive(Node* node) const {
        if (!node) return;
        inorderRecursive(node->left);
        std::cout << node->data << " ";
        inorderRecursive(node->right);
    }
    
    /**
     * @brief Recursively clears all nodes.
     */
    void clearRecursive(Node* node) {
        if (!node) return;
        clearRecursive(node->left);
        clearRecursive(node->right);
        delete node;
    }
    
public:
    /**
     * @brief Default constructor initializes an empty tree.
     */
    AVLTree() : root(nullptr) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~AVLTree() {
        clear();
    }
    
    /**
     * @brief Inserts a value into the AVL tree with automatic rebalancing.
     * @param value The value to insert.
     */
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }
    
    /**
     * @brief Deletes a value from the AVL tree with automatic rebalancing.
     * @param value The value to delete.
     */
    void deleteValue(const T& value) {
        root = deleteRecursive(root, value);
    }
    
    /**
     * @brief Performs inorder traversal.
     */
    void inorder() const {
        std::cout << "AVL Inorder traversal: ";
        inorderRecursive(root);
        std::cout << std::endl;
    }
    
    /**
     * @brief Checks if the tree is empty.
     */
    bool isEmpty() const {
        return root == nullptr;
    }
    
    /**
     * @brief Clears all nodes from the tree.
     */
    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
    
    /**
     * @brief Returns the height of the tree.
     */
    int height() const {
        return getHeight(root);
    }
};

#endif // AVLTREE_HPP
