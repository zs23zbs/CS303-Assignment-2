#pragma once
#include "LinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename Item_Type>
class Stack {
private:
  vector<Item_Type> stack;

public:
  bool empty() const {
    return stack.empty();
  }

  void push(const Item_Type& item){
    stack.push_front(item);
  }

  void pop() {
    if (stack.empty()){
      throw out_of_range("Can't pop from an empty stack");
    }
    stack.pop_front();
  }

  Item_Type top() const {
    if (stack.empty()){
      throw out_of_range("Top is not there, aka empty stack");
    }
    return stack.front();
  }

  // Get the average of the items in the stack 
  double average() const {
    if (stack.empty()){
      throw out_of_range("Stack is empty");
    }

    double sum = 0;
    size_t count = 0;
    auto current = stack.begin(); // Iterator

    while (current != nullptr){
      sum += current->data;
      current = current->nextptr; 
      ++count;
    }

    return sum / count;
  }

  void print_stack() const {
    stack.print_list();
  }

};