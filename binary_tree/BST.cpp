#include<iostream>

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
       // Constructor to initialize a node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
    private:
    Node* root;
    
    // Constructor
   
    
    public:
     BST () : root(nullptr) {}
    
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        
        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        }
        if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }
        return root;
    }
     
      bool search(int value) {
        return searchRecursive(root, value);
    }

    // Recursive helper method to search for a value in the BST
    bool searchRecursive(Node* root, int value) {
        if (root == nullptr) {
            return false;
        }
        if (value == root->data) {
            return true;
        }
        if (value < root->data) {
            return searchRecursive(root->left, value);
        }
        else {
            return searchRecursive(root->right, value);
        }
    }
    
    
    void printTree() {
        printInOrder(root);
    }

    void printInOrder(Node* root) {
        if (root != nullptr) {
            printInOrder(root->left);
            std::cout << root->data << " ";
            printInOrder(root->right);
        }
    }
};
    

int main() {
    // Create a new Binary Search Tree
    BST bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Binary Search Tree: ";
    bst.printTree();
    std::cout << std::endl;

    return 0;
}
