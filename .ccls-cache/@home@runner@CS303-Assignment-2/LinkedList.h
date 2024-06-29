#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include <iostream>

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

  void push_back(const Item_Type& value); // Add an element to the back of the list

  void pop_front(); // Remove the first element of the list

  void pop_back(); // Remove the last element of the list

  void front() const; // Return the first element of the list

  void back() const; // Return the last element of the list

  bool empty() const; // Check if the list is empty

  void insert(const Item_Type& value, size_t index); // Insert an item at specific index

  bool remove(size_t index); // Remove an item at specific index

  size_t find(const Item_Type& item); // Find the index of an item
};

#endif