#pragma once
#include <iostream>

using namespace std;

template<typename Item_Type>
class SingleLinkedList {
private:
  struct Node { 
    Item_Type data;
    Node* nextptr;

    // Copy constructor for struct Node 
    Node(const Item_Type& data_item, Node* next_node = nullptr) : data(data_item), nextptr(next_node) {}
  };

  Node* head;
  Node* tail;
  size_t num_items;

public:
  SingleLinkedList(); // Constructor
 ~SingleLinkedList(); // Destructor

  void print_list() const; // Print the list to check

  void push_front(const Item_Type& value); // Add an element to the front of the list 

  
};