#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class BinarySearchTree
 * @brief A template-based binary search tree implementation.
 *
 * Supports recursive insertion, deletion, and three types of traversals:
 * - Inorder (Left-Root-Right): sorted order
 * - Preorder (Root-Left-Right): root first
 * - Postorder (Left-Right-Root): root last
 *
 * @tparam T The data type stored in the tree. Must support comparison operators.
 */
template <typename T>
class BinarySearchTree {
private:
    /**
     * @struct Node
     * @brief Represents a node in the binary search tree.
     */
    struct Node {
        T data;
        Node* left;
        Node* right;
        
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    /**
     * @brief Recursively inserts a value into the tree.
     * Time Complexity: O(log n) average, O(n) worst case
     */
    Node* insertRecursive(Node* node, const T& value) {
        if (!node) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        
        return node;
    }
    
    /**
     * @brief Recursively searches for a value in the tree.
     * Time Complexity: O(log n) average, O(n) worst case
     */
    bool searchRecursive(Node* node, const T& value) const {
        if (!node) {
            return false;
        }
        
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
    
    /**
     * @brief Finds the minimum value node in a subtree.
     */
    Node* findMin(Node* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    /**
     * @brief Recursively deletes a value from the tree.
     * Time Complexity: O(log n) average, O(n) worst case
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
            // Node with only one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Node with two children: get inorder successor
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = deleteRecursive(node->right, minRight->data);
        }
        
        return node;
    }
    
    /**
     * @brief Inorder traversal: Left-Root-Right (sorted order).
     * Time Complexity: O(n)
     */
    void inorderRecursive(Node* node) const {
        if (!node) return;
        inorderRecursive(node->left);
        std::cout << node->data << " ";
        inorderRecursive(node->right);
    }
    
    /**
     * @brief Preorder traversal: Root-Left-Right.
     * Time Complexity: O(n)
     */
    void preorderRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
    
    /**
     * @brief Postorder traversal: Left-Right-Root.
     * Time Complexity: O(n)
     */
    void postorderRecursive(Node* node) const {
        if (!node) return;
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        std::cout << node->data << " ";
    }
    
    /**
     * @brief Recursively clears all nodes in the tree.
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
    BinarySearchTree() : root(nullptr) {}
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~BinarySearchTree() {
        clear();
    }
    
    /**
     * @brief Inserts a value into the tree.
     * @param value The value to insert.
     */
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }
    
    /**
     * @brief Searches for a value in the tree.
     * @param value The value to search for.
     * @return True if found, false otherwise.
     */
    bool search(const T& value) const {
        return searchRecursive(root, value);
    }
    
    /**
     * @brief Deletes a value from the tree.
     * @param value The value to delete.
     */
    void deleteValue(const T& value) {
        root = deleteRecursive(root, value);
    }
    
    /**
     * @brief Performs inorder traversal (Left-Root-Right).
     * Output is in sorted order.
     */
    void inorder() const {
        std::cout << "Inorder traversal: ";
        inorderRecursive(root);
        std::cout << std::endl;
    }
    
    /**
     * @brief Performs preorder traversal (Root-Left-Right).
     */
    void preorder() const {
        std::cout << "Preorder traversal: ";
        preorderRecursive(root);
        std::cout << std::endl;
    }
    
    /**
     * @brief Performs postorder traversal (Left-Right-Root).
     */
    void postorder() const {
        std::cout << "Postorder traversal: ";
        postorderRecursive(root);
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
};

#endif // BINARYSEARCHTREE_HPP
