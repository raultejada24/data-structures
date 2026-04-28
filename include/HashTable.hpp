#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <stdexcept>
#include <utility>
#include <string>

/**
 * @class HashTable
 * @brief A template-based hash table with collision handling via chaining.
 *
 * Uses linked lists to handle collisions. Supports insertion, deletion, and search.
 *
 * @tparam K The key type. Must support comparison and have a hash function.
 * @tparam V The value type associated with each key.
 */
template <typename K, typename V>
class HashTable {
private:
    static const int DEFAULT_CAPACITY = 10;
    
    /**
     * @struct Entry
     * @brief Represents a key-value pair in the hash table.
     */
    struct Entry {
        K key;
        V value;
        Entry* next;
        
        Entry(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };
    
    Entry** table;
    int capacity;
    int size;
    
    /**
     * @brief Simple hash function for integer keys.
     */
    int hash(int key) const {
        return key % capacity;
    }
    
    /**
     * @brief Hash function for string keys using polynomial rolling hash.
     */
    int hash(const std::string& key) const {
        int hashValue = 0;
        int prime = 31;
        
        for (char ch : key) {
            hashValue = (hashValue * prime + ch) % capacity;
        }
        
        return hashValue < 0 ? hashValue + capacity : hashValue;
    }
    
public:
    /**
     * @brief Constructor initializes the hash table.
     */
    HashTable() : capacity(DEFAULT_CAPACITY), size(0) {
        table = new Entry*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }
    
    /**
     * @brief Destructor deallocates all entries and the table.
     */
    ~HashTable() {
        clear();
        delete[] table;
    }
    
    /**
     * @brief Inserts a key-value pair into the hash table.
     * @param key The key to insert.
     * @param value The value associated with the key.
     * Time Complexity: O(1) average, O(n) worst case.
     */
    void insert(const K& key, const V& value) {
        int index = hash(key);
        Entry* current = table[index];
        
        // Update existing key
        while (current) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        
        // Insert new key-value pair at the beginning (O(1))
        Entry* newEntry = new Entry(key, value);
        newEntry->next = table[index];
        table[index] = newEntry;
        size++;
    }
    
    /**
     * @brief Searches for a value by key.
     * @param key The key to search for.
     * @param value Output parameter to store the found value.
     * @return True if key exists, false otherwise.
     * Time Complexity: O(1) average, O(n) worst case.
     */
    bool search(const K& key, V& value) const {
        int index = hash(key);
        Entry* current = table[index];
        
        while (current) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        
        return false;
    }
    
    /**
     * @brief Deletes a key-value pair from the hash table.
     * @param key The key to delete.
     * @return True if deleted, false if not found.
     * Time Complexity: O(1) average, O(n) worst case.
     */
    bool deleteKey(const K& key) {
        int index = hash(key);
        Entry* current = table[index];
        Entry* prev = nullptr;
        
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        
        return false;
    }
    
    /**
     * @brief Displays all key-value pairs in the hash table.
     * Time Complexity: O(n)
     */
    void display() const {
        std::cout << "HashTable contents:" << std::endl;
        
        for (int i = 0; i < capacity; i++) {
            std::cout << "[" << i << "]: ";
            Entry* current = table[i];
            
            if (!current) {
                std::cout << "empty";
            } else {
                while (current) {
                    std::cout << "(" << current->key << ", " << current->value << ") ";
                    current = current->next;
                }
            }
            std::cout << std::endl;
        }
    }
    
    /**
     * @brief Returns the number of entries in the hash table.
     */
    int getSize() const {
        return size;
    }
    
    /**
     * @brief Clears all entries from the hash table.
     * Time Complexity: O(n)
     */
    void clear() {
        for (int i = 0; i < capacity; i++) {
            Entry* current = table[i];
            while (current) {
                Entry* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        size = 0;
    }
    
    /**
     * @brief Checks if the hash table is empty.
     */
    bool isEmpty() const {
        return size == 0;
    }
};

#endif // HASHTABLE_HPP
