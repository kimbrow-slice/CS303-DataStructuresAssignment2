# CS303-Assignment2
 CS 303 Data Structures Assignment 2

#### References: 
[C++ ostream, friends and namspaces](https://stackoverflow.com/questions/10405312/c-ostream-friends-and-namespaces)

[C++ Using your own namespace within your own project](https://stackoverflow.com/questions/10405312/c-ostream-friends-and-namespaces)

[C++ Problems with friends of class template](https://stackoverflow.com/questions/73385794/problems-with-friends-of-class-template)

[C++ std::out_of_range error](https://stackoverflow.com/questions/2918267/stdout-of-range-error)

[C++ static_cast-ing versus floor-ing](https://stackoverflow.com/questions/2918267/stdout-of-range-error)


#### To Do:

- Error handling for edge cases within LinkedList.
- Error handling remove item from stack if it is already empty.
  

## Overview

LinkedList - The purpose of this program was to create a single linked list class which contains the data members head, tail, and num_items. This program enables the user to interact with a CLI that allows them complete operations such as adding, removing, and finding elements within the list, as well functions to allow for input validation and stream insertion. 

StackProject - The goal for this program was to implement a stack of integers using a vector with push and pop operations. I created a basic UI that allows the user create a stack object, check for an empty stack, insert integers onto the stack, remove elements from the stack, find the top of the stack, and to find the average value of the elements currently in the stack. 

## Setup

1. Open Visual Studio Community. (Tested in Visual Studio Community 2022 only)
2. Select File -> Open -> Project/Solution and navigate to teh downloaded project files. 
3. Choose the solution file (.sln) file or main.cpp to open the project.
4. Right click the Project in the Solution Explorer and click Set as Startup Project. 
5. Press Crtl + F5 to build and run the program without debugging, or F5 to run with debugging. 


### Linked List Insert Elements
Input : Add front (1): 13, Add back (2): 55, Add front (1): 33, Print List (5)
![Valid data input from user](/LinkedList/insertElements.png)

### Linked List Remove Elements
Input : Remove front (3): 13 removed, Remove back (4): 55 removed, Print List (5)
![Valid data input from user](/LinkedList/removeElements.png)

### Linked List Error Handling
Input : Add front (1): 5.0, Exit program (0) 
![Invalid data input from user](/LinkedList/errorHandling.png)

### Stack Implementation
Input: Check if stack is empty (1): Currently empty, Insert an element from the stack (2): 13, Insert an element from the stack (2): 12, Find the average value of the stack (5): 12
![Valid data input from user](/StackProject/Output.png)

### Stack Implementation
Input: Print the current elements in the stack [top to bottom] (6): 12 | 13, Find the top of the stack (4): 12, Remove an element from the stack (3): 12 removed, Print the current elements in the stack (6): 13
![Valid data input from user](/StackProject/Output2.png)


