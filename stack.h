#include "LinkedList.h"
#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Stack class 

template<typename Item_Type>
class Stack {
private:
  vector<Item_Type> stack;

public:
  bool empty() const { // function to check if stack is empty
    return stack.empty();
  }

  void push(const Item_Type& item){ // function to push an item onto the stack
    stack.push_back(item); 
  }

  bool remove(size_t index) { 
    if (stack.empty()){ 
      throw out_of_range("Can't pop from an empty stack");
    }
    if (index >= stack.size()) {
      return false; // Index is out of bound
    }
    stack.erase(stack.begin() + index); // Find the index of the item to remove
    return true;
  }

  Item_Type top() const {
    if (stack.empty()){
      throw out_of_range("Top is not there, aka empty stack");
    }
    return stack.front(); // Get the top element in the stack
  }

  // Get the average of the items in the stack 
  double average() const {
    if (stack.empty()){
      throw out_of_range("Stack is empty");
    }
    double sum = 0;
    size_t count = 0;
    
    for (auto const& item : stack) { // Iterate over each element in the stack
      sum += item; // Add up all the integers in the stack altogether and store into sum 
      count++; // Count the number of items in the stack 
    }
    return sum / count; // Find average of the sum of all elements divided by the number of elements in the stack
  }

  // Print the current stack 
  void print_stack() const {
    for (auto const& item : stack) {
      cout << item << " ";
    }
    cout << endl;
  }

};