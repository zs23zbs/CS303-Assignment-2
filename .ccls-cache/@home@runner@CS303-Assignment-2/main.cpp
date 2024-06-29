#include "LinkedList.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack<int> stack; // Stack class object created
  char choice = 0; // Declare and initialize a user choice variable 

  while (choice != 'Q') {

    // Display the menu for user base for the program 
    
    cout << endl;
    cout << "\t\t MENU" << endl;
    cout << "A) Check if the stack is empty" << endl;
    cout << "B) Insert some integer values onto the stack" << endl;
    cout << "C) Remove an element from the stack" << endl;
    cout << "D) Find the top element of the stack" << endl;
    cout << "E) Find the average value of the stack elements" << endl;
    cout << "F) Print the current stack" << endl;
    cout << "Q) Press Q to quit" << endl << endl;

    // Prompt the user 
    cout << "Please enter a letter of you choice from the menu: ";
    cin >> choice; 
    
    choice = toupper(choice);

    cout << endl;

    // Swtich statement to call the functions based on the user's choice
    
    switch(choice){ // Checks if the stack is empty
      case 'A': { 
        if (stack.empty()){ 
          cout << "The stack is currently empty" << endl;
        }
        else {
          cout << "The stack is not empty" << endl << endl;
        }
        break;
      }
      
      case 'B' : { // Insert an integer into the stack 
        int value; // Declare a value for user to enter 
        cout << "Please enter an integer value: ";
        cin >> value;
        stack.push(value); // Push the value onto the stack
        cout << "The value you entered " << value << " has been pushed onto the stack" << endl << endl;
        break;
      }
      
      case 'C': { // Remove an element from the stack based on index 
        size_t index;
        cout << "Please enter the index of the element to remove: ";
        cin >> index;
        if (stack.remove(index)) {
            cout << "The element at index " << index << " has been removed from the stack" << endl;
        } else {
            cout << "Error: Index " << index << " is out of range" << endl << endl;
        }
        break;
      }
      
      case 'D': { // Return the top element of the stack
        try {
          int top = stack.top(); // Find the top element of the stack
          cout << "The top element of the stack is " << top << endl << endl;
        }
        catch (const out_of_range& e){
          cout << "Error: " << e.what() << endl;
        }
        break;
      }
      
      case 'E' : { // Calculate the average all the elements in the stack 
        try {
          double average = stack.average(); // Find the average of the stack elements
          cout << "The average of the stack elements is " << average << endl << endl;
        }
        catch (const out_of_range& e){
          cout << "Error: " << e.what() << endl;
        }
        break;
      }

      case 'F': { // Print the current stack 
        cout << "Printing the current stack: " << endl;
        stack.print_stack(); // Print the current stack
        cout << endl;
        break;
      }
      
      case 'Q' : { // Quit the program 
        cout << "Quitting the program..." << endl << endl;
        break;
      }
      
      default: { // In case the user enters and invalid entry 
        cout << "You have entered an invalid entry. Please select among the options in the menu displayed." << endl;
        break;
      }
    }
  }
  cout << "Thank you for using the program. Have a good day!" << endl;
  return 0;
}