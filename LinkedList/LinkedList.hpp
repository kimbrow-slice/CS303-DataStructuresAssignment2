// LinkedList.hpp
namespace JK {

    // Constructor to initialize an empty list
    template <typename Item_Type>
    LinkedList<Item_Type>::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor to allow for deallocation of all nodes to prevent memory leaks
    template <typename Item_Type>
    LinkedList<Item_Type>::~LinkedList() {
        while (!empty()) pop_front();
    }

    // Continuously remove from front until the list is empty
    template <typename Item_Type>
    void LinkedList<Item_Type>::push_front(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item, head); // Create a new node with the inserted element. 
        head = newNode;
        if (tail == nullptr) tail = head; // If the list is currently empty, update the tail node to the new node.
        num_items++; // increment the item count
    }

    // Adds a new elements to the front of our list
    template <typename Item_Type>
    void LinkedList<Item_Type>::push_back(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item); // Create a new node with the inserted element. 
        if (tail != nullptr) {
            tail->next = newNode; // Link the tail node to the new node
            tail = newNode; // Update the tail node to the new node
        }
        else {
            head = tail = newNode; // For an empty list, head and tail points to the new node.
        }
        num_items++;
    }

    // Validate for an empty list
    template <typename Item_Type>
    bool LinkedList<Item_Type>::empty() const {
        return num_items == 0; // If num_items is 0, then the list is empty. 
    }

    // Reference to the data within the first node
    template <typename Item_Type>
    Item_Type& LinkedList<Item_Type>::front() {
        if (empty()) throw std::out_of_range("The list is currently empty. Trying using option 1 to add more values!");
        return head->data;
    }

    // Refencer to data within the last node
    template <typename Item_Type>
    Item_Type& LinkedList<Item_Type>::back() {
        if (empty()) throw std::out_of_range("The list is currently empty. Trying using option 1 to add more values!");
        return tail->data;
    }

    // Remove the first element from our list
    template <typename Item_Type>
    void LinkedList<Item_Type>::pop_front() {
        if (empty()) throw std::out_of_range("The list is already empty. Trying using option 1 to add more values!");
        Node<Item_Type>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
        num_items--;
    }

    // Remove the last element from our list.
    template <typename Item_Type>
    void LinkedList<Item_Type>::pop_back() {
        if (empty()) throw std::out_of_range("The list is already empty. Trying using option 1 to add more values!");
        if (head == tail) {
            // if there is only one element in the list
            delete head; // Delete the head node which is also the tail node.
            head = tail = nullptr; // Reset the head and tail nodes to nullptr
        }
        else {
            // If more than one element in the list
            Node<Item_Type>* temp = head;
            // Find node before tail node
            while (temp->next != tail) temp = temp->next;
            delete tail; // Delete the tail node
            tail = temp; // Update the tail to the previous node
            tail->next = nullptr; // Set the new tail's next node to nullptr
        }
        num_items--; // Decrement the item count
    }

    // Insert an element at a specificed index. 
    template <typename Item_Type>
    void LinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
        // If user tries to inset at front or the list is empty
        if (index == 0 || empty()) {
            push_front(item);
        }
        else {
            Node<Item_Type>* temp = head;
            // Find one node before the specificed index
            for (size_t i = 1; temp != nullptr && i < index; ++i) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                // If it is the end of the list, insert the element to the back of the list.
                push_back(item);
            }
            else {
                // Insert a new node at the current index in the list
                temp->next = new Node<Item_Type>(item, temp->next);
                if (temp->next->next == nullptr) { // Update the tail node if element was inserted at the end
                    tail = temp->next; 
                }
                num_items++; // Increment the item count
            }
        }
    }
    // Finds the index of the first occurrence of an element in the list
    template <typename Item_Type>
    size_t LinkedList<Item_Type>::find(const Item_Type& item) const {
        Node<Item_Type>* current = head;
        size_t index = 0;
        // Find the specific element within the list
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return num_items; // Return num_items as a indicator of element not being found.
    }

    // Print all the current elements within the list
    template <typename Item_Type>
    void LinkedList<Item_Type>::print() const {
        Node<Item_Type>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " "; // Display the current node's data
            current = current->next;
        }
        std::cout << std::endl; // print a new line at the end of the list
    }

    // Overload the << operator for easy list printing
    template <typename Item_Type>
    std::ostream& operator<<(std::ostream& os, const JK::LinkedList<Item_Type>& list) {
        Node<Item_Type>* current = list.head;
        while (current != nullptr) {
            os << current->data << ' '; // Insert the current node's data into the stream
            current = current->next;
        }
        return os; // Return the stream for chai9ning
    }

}