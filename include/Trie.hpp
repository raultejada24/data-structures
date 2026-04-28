#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <string>
#include <unordered_map>

/**
 * @class Trie
 * @brief A prefix tree (trie) implementation for efficient string searching and storage.
 *
 * Supports insertion, search, and prefix matching for dictionary operations.
 * Each node contains a map of character to child nodes.
 */
class Trie {
private:
    /**
     * @struct TrieNode
     * @brief Represents a single node in the trie structure.
     */
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        
        TrieNode() : isEndOfWord(false) {}
    };
    
    TrieNode* root;
    
    /**
     * @brief Recursively searches for words with a given prefix.
     */
    void searchWordsWithPrefix(TrieNode* node, std::string currentWord, int& count) const {
        if (!node) return;
        
        if (node->isEndOfWord) {
            std::cout << currentWord << " ";
            count++;
        }
        
        for (auto& [ch, child] : node->children) {
            searchWordsWithPrefix(child, currentWord + ch, count);
        }
    }
    
    /**
     * @brief Recursively clears all nodes.
     */
    void clearRecursive(TrieNode* node) {
        if (!node) return;
        
        for (auto& [ch, child] : node->children) {
            clearRecursive(child);
        }
        delete node;
    }
    
public:
    /**
     * @brief Default constructor initializes an empty trie.
     */
    Trie() {
        root = new TrieNode();
    }
    
    /**
     * @brief Destructor deallocates all nodes.
     */
    ~Trie() {
        clearRecursive(root);
    }
    
    /**
     * @brief Inserts a string into the trie.
     * @param word The string to insert.
     * Time Complexity: O(m) where m is the length of the word.
     */
    void insert(const std::string& word) {
        TrieNode* current = root;
        
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        
        current->isEndOfWord = true;
    }
    
    /**
     * @brief Searches for an exact word in the trie.
     * @param word The word to search for.
     * @return True if the word exists, false otherwise.
     * Time Complexity: O(m) where m is the length of the word.
     */
    bool search(const std::string& word) const {
        TrieNode* current = root;
        
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        
        return current->isEndOfWord;
    }
    
    /**
     * @brief Checks if there is any word in the trie with the given prefix.
     * @param prefix The prefix to check.
     * @return True if any word starts with the prefix, false otherwise.
     * Time Complexity: O(m) where m is the length of the prefix.
     */
    bool startsWith(const std::string& prefix) const {
        TrieNode* current = root;
        
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        
        return true;
    }
    
    /**
     * @brief Searches for all words that start with the given prefix.
     * @param prefix The prefix to search for.
     * Time Complexity: O(n) where n is the number of nodes in the subtrie.
     */
    void searchByPrefix(const std::string& prefix) const {
        TrieNode* current = root;
        
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                std::cout << "No words found with prefix: " << prefix << std::endl;
                return;
            }
            current = current->children[ch];
        }
        
        std::cout << "Words with prefix '" << prefix << "': ";
        int count = 0;
        searchWordsWithPrefix(current, prefix, count);
        if (count == 0) {
            std::cout << "(none)";
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Clears all words from the trie.
     */
    void clear() {
        clearRecursive(root);
        root = new TrieNode();
    }
};

#endif // TRIE_HPP
