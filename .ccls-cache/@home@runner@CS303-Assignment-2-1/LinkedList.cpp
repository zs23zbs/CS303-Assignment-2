#include "LinkedList.h"
#include <iostream>

using namespace std; 

template<typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() { // Constructor

  // Set head and tail to null and initialize num_items
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

template<typename Item_Type>
SingleLinkedList<Item_Type>::~SingleLinkedList() { // Destructor
  Node* current = head; // Set a temp node as the head pointer 

  // while the current node is not null (aka empty)
  while (current != nullptr) {
    Node* nextptr = current->nextptr; // Set the next pointer to the node after current 
    delete current; // Delete the current node, able to reuse memory space
    current = nextptr; // Set the current node to the next one 
  }
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::print_list() const {
  Node* current = head; 

  // while the current pointer is not empty
  while (current != nullptr){
    cout << current->data << " "; // Print the data of the current node

    // Set the current node to the next node after it 
    current = current->nextptr; // This advances the node through list 
  }
  cout << endl; 
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& value) {
  // Create a new node for the given value 
  Node* new_node = new Node(value);

  // Set the new node's next pointer to head 
  new_node->nextptr = head;

  head = new_node; // Set the head to the new node, now front of the list

  // if the tail pointer is null
  if (tail == nullptr) {
    tail = new_node; // Set the tail to the new node
  }
  num_items++; // Increment number of items in the list
}