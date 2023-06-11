#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hashtable

    // Hash node structure
    struct HashNode {
        int key;
        std::string value;
    };

    std::vector<std::list<HashNode>> table; // Array of linked lists

    // Hash function to map keys to indices
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Constructor
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // Insert a key-value pair into the hashtable
    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // Search for a value given a key
    std::string search(int key) {
        int index = hashFunction(key);
        for (const auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return ""; // Key not found
    }

    // Remove a key-value pair from the hashtable
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};

int main() {
    HashTable ht;
    
    // Insert key-value pairs
    ht.insert(1, "Value1");
    ht.insert(2, "Value2");
    ht.insert(11, "Value11");
    ht.insert(12, "Value12");

    // Search for values
    std::cout << ht.search(1) << std::endl;  // Output: Value1
    std::cout << ht.search(2) << std::endl;  // Output: Value2
    std::cout << ht.search(11) << std::endl; // Output: Value11
    std::cout << ht.search(12) << std::endl; // Output: Value12
    std::cout << ht.search(3) << std::endl;  // Output: (empty string)

    // Remove key-value pair
    ht.remove(2);
    std::cout << ht.search(2) << std::endl;  // Output: (empty string)

    return 0;
}
