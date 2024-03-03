#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class IntStack {
public:
    // Check is the stack is empty. Return true if stack is empty, else return false. 
    bool isEmpty() const {
        return data.empty();
    }
    // Push a new integer onto the top of the stack and checks for duplicate v
    bool push(int value) {
        if (std::find(data.begin(), data.end(), value) != data.end()) {
            std::cout << "This value already exists in the stack. No duplicates allowed.\n";
            return false; // Indicate that the push operation was not successful.
        }
        // If the value does not exist, push it onto the stack
        data.push_back(value);
        return true;
    }
    // Remove and returns the top element of the stack. 
    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Sorry, the stack is currently empty. Try option 2 to insert some integers!");
        }
        int topElement = data.back();
        data.pop_back();
        return topElement;
    }
    // Get and return the top element of the stack. 
    int top() const {
        if (isEmpty()) {
            throw std::out_of_range("Sorry, the stack is currently empty. Try option 2 to insert some integers!");
        }
        return data.back();
    }
    // Calculate the average value of all elements stored in the stack. Throw an error if user selects option 5 when the stack is empty.
    int average() const {
        if (isEmpty()) {
            throw std::out_of_range("Sorry, the stack is currently empty. Try option 2 to insert some integers!");
        }
        int sum = 0;
        for (int num : data) {
            sum += num;
        }
        return sum / static_cast<int>(data.size());
    }
    // Function to print all of the elements in the stack, from top to bottom. If the stack is empty, inform the user. 
    void printStack() const {
        if (isEmpty()) {
            std::cout << "Sorry, the stack is currently empty. Try option 2 to insert some integers!\n";
        }
        else {
            std::cout << "The integers below are currently in the stack. Values will be printed from top to bottom:\n";
            for (auto it = data.rbegin(); it != data.rend(); ++it) {
                std::cout << *it << std::endl;
            }
        }
    }

private:
    std::vector<int> data; // Container to store the elements in the stack.
};

// Prompt the user for an integer and validate their input. Continue to prompt the user until valid input is given.
int readInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Only integers values are considered valid input. Please try again\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

#endif // STACK_H
