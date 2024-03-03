#include "LinkedList.h"
#include <iostream>
#include <limits>

using namespace JK; // Namespace JK for LinkedList implementation
using std::numeric_limits; // Numeric_limits for input validation
using std::streamsize; // Streamsize for input validation


int main() {
    LinkedList<int> list; // Initialize a linked list for integers
    int choice, value; // Variables to store user's choice and input value

    while (true) { // Infinite loop to keep the program running until the user decides to exit
        cout << "\nLinked List Operations:\n"; 
        cout << "1. Add to Front\n"; 
        cout << "2. Add to Back\n"; 
        cout << "3. Remove from Front\n"; 
        cout << "4. Remove from Back\n"; 
        cout << "5. Print List\n"; 
        cout << "0. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 

        // Input validation
        if (cin.fail()) { // Check if the previous extraction operation failed
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the rest of the current line
            cout << "The input you have provided is not valid. Please try using the numbers 0 - 5 for the options.\n" << endl; // Prompting the user for valid input
            continue; // Continue to the next iteration of the loop
        }

        switch (choice) {
        case 1: // Insert a value to the front of our list
            cout << "Enter a value you would like to add to the front of our list: "; 
            cin >> value; 
            list.push_front(value); 
            break;
        case 2: // Insert a value to the back of our list
            cout << "Enter a value you would like to add to the back of our list: "; 
            cin >> value; 
            list.push_back(value); 
            break;
        case 3: // Remove a value from the front of our list
            if (!list.empty()) { 
                list.pop_front(); 
                cout << "You have removed one item from the front of the list!" << endl;
            }
            else {
                cout << "The list is already empty. Trying using option 1 to add more values!" << endl; // Output to the user the list is empty
            }
            break;
        case 4: // Remove a value from the back of the list
            if (!list.empty()) { // Check if the list is not empty
                list.pop_back(); // Removing a valuer from the back of the list
                cout << "Removed one item from the back." << endl; // Inform user of the action
            }
            else {
                cout << "The list is already empty. Trying using option 1 to add more values!" << endl; 
            }
            break;
        case 5: // Print all elements currently in the list
            cout << "Current List: "; 
            list.print(); 
            cout << endl;
            break;
        case 0: // Exit the program here
            cout << "You are exiting the program now. See you next time!" << endl; 
            return 0; 
        default:
            cout << "Invalid choice. Please try again." << endl; 
            break;
        }
    }
}


