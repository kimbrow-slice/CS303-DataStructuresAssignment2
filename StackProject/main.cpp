#include <iostream>
#include "stack.h" // Our stack class.

// Function to print the menu options to the end user. 
void printMenu() {
    std::cout << "\n--- Stack Operations ---\n"
        << "1. Check if the stack is empty\n"
        << "2. Insert an integer onto the stack\n"
        << "3. Remove an element from the stack\n"
        << "4. Find the top of the stack\n"
        << "5. Find the average value of the stack\n"
        << "6. Print the current elements in the stack\n"
        << "0. Back your bags and leave :C \n" // Exit option
        << "Enter your choice now: ";
}

int main() {
    IntStack stack; // Initializ stack object
    int choice; // Variable to store the user's  choice

    // Continue displaying the menu and responding to input until the user decides to back their bags and go home!
    do {
        printMenu(); // Show the menu options to the user
        if (std::cin >> choice) {
            // If a integer is successfully read, ignore remaining input until newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            // If input is invalid (not an integer), clear the error and ignore remaining input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The input you have provided is not valid. Please enter an integer to continue!\n";
            continue;
        }

        // Begin to process the users choice
        switch (choice) {
        case 1:
            // Check if the stack is currently empty, if so inform user, else continue. 
            std::cout << (stack.isEmpty() ? "The stack currently has no elements present. Try option 2 to insert some integers!\n" : "The stack currently has elements and is no longer empty!\n");
            break;

            // Push a new integer onto the top of the stack. 
        case 2: {
            int value = readInteger("Enter an integer to push onto the stack:\n");
            if (stack.push(value)) { // Only display success message if push returns true.
                std::cout << value << " Has been added to the stack!\n";
            }
            break;
        }

        case 3:
            // Remove an element from teh stack.
            try {
                int removedValue = stack.pop();
                std::cout << "You've remove element: " << removedValue << " from the stack!" << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 4:
            // Display the value stored in the top element of the stack.
            try {
                std::cout << "The top of the stack is: " << stack.top() << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 5:
            // Display an average value of all elements in the stack (rounding down).
            if (stack.isEmpty()) {
                std::cout << "Sorry, the stack is currently empty. Try option 2 to insert some integers!" << std::endl;
            }
            else {
                std::cout << "Average value of the stack is: " << stack.average() << std::endl;
            }
            break;

        case 6:
            // Print all of the elements in the stack to the end user.
            stack.printStack();
            break;

        case 0:
            // Exit statement
            std::cout << "See you next time! - JK \n";
            break;

        default:
            std::cout << "The input you have provided is not valid. Please try using the numbers 0 - 6 for the options.\n";
            break;
        }
    } while (choice != 0); // Continue until the user chooses to exit

    return 0;
}
