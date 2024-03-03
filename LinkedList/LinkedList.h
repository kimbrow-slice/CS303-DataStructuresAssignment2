#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

// Define my namespace "JK" to be a container the LinkedList and Node structures.
namespace JK {
    using std::cin;
    using std::cout;
    using std::endl;

    // Define a templated Node structure for the linked list
    template <typename Item_Type>
    struct Node {
        Item_Type data; // Data stored of the templated type
        Node* next; // Pointer to the next node in the list

        // Constructor to initialize a node with data and optionally, the next node pointer
        Node(const Item_Type& data_item, Node<Item_Type>* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
    };

    // Define a templated LinkedList class
    template <typename Item_Type>
    class LinkedList {
    private:
        Node<Item_Type>* head; // Pointer to the first node in the list
        Node<Item_Type>* tail; // Pointer to the last node in the list
        size_t num_items; // Count of items in the list

    public:
        // Default constructor
        LinkedList();
        // Destructor to clean up dynamically allocated nodes
        ~LinkedList();

    
        void push_front(const Item_Type& item);
        void push_back(const Item_Type& item);
        bool empty() const;
        Item_Type& front();
        Item_Type& back();
        void pop_front();
        void pop_back();
        void insert(size_t index, const Item_Type& item);
        // Member function to remove an item at a specified index
        bool remove(size_t index);
        size_t find(const Item_Type& item) const;
        // Member function to print all items in the list to standard output
        void print() const;

        // Overload the output operator to allow me to output using std::cout << to accomplish printing the list to the user
        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
    };
}


// Include the implementation of LinkedList methods
#include "LinkedList.hpp"

#endif // LINKED_LIST_H
