#include <iostream>

class Node {
    public:
    Node* next;
    int data;

// const
   Node(int value) {
    next = nullptr;
    data = value;
   }

};

class LinkedList {
    Node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

void insert(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    }

void remove(int value) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot remove element." << std::endl;
        return;
        }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Removed element: " << value << std::endl;
        return;

       }

    Node* current = head;
    Node* prev = nullptr;
    
    while (current->next != nullptr) {
           if(current->data == value) {
           prev->next = current->next;
           delete current;
           std::cout << "Removed element: " << value << std::endl;
           return;
        
    }
       prev = current;
       current = current->next;
    }
       std::cout << "Element not found in the list." << std::endl;
    }

     void print() {
        Node* current = head;
        std::cout << "List elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
            }
        std::cout << std::endl;
    }
};


int main() {

    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(69);
    list.insert(30);
   
    list.print();

    list.remove(20);
    list.remove(40);
    list.print();
    



    return 0;
}