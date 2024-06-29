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
void SingleLinkedList<Item_Type>::print_list () const {
  Node* current = head;

  // While current pointer is not empty
  while (current != nullptr) { 
    cout << current->data << " "; // Print the data of the current node

    // Set current to the current's next pointer
    current = current->nextptr; 
  }
  cout << endl;
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& value) { 
  // Head = front of the list 
  
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

template<typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& value) {
  // Tail = end of the list 

  // If the tail pointer is not null aka empty 
  if (tail != nullptr){

    // Set tail's next pointer to a new node for the given value 
    tail->nextptr = new Node(value); 
    tail = tail->nextptr; // Set the newly create node as the tail

    num_items++; // Increment the number of items 
  }
  else {
    // if the tail pointer is empty, push value to the front of the list 
    push_front(value);
  }
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {
  // Check if the head is empty
  if (head == nullptr){
    throw invalid_argument("Attempt to call function on empty list");
  }

  Node* remove_node = head; // Set the remove node to the head pointer
  head = head->nextptr; // Update to point to the next node after head
  delete remove_node; // Delete the node that was removed

  // if the head is not empty
  if (head != nullptr) {
    tail = nullptr; // Set the tail to null
  }
  num_items--; // Decrement the number of items in the list
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {
  // Check if the tail is empty
  if (tail == nullptr){
    throw invalid_argument("Attempt to call function on empty list");
  }

  // if the list has only one node in it
  if(head == tail){
    head = nullptr;
    tail = nullptr;
  }
  else {
    Node* current = head; // Set the current node to the head of the list
    while (current->nextptr != tail) {// loop through list until last node
      current = current->nextptr; // Advance node to traverse the list 
    }

    current->nextptr = nullptr; // Second to last node in list, now null
    delete tail;
    tail = current; // Sets the new tail 
  }
  num_items--; // Decrement the number of items in the list
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::front() const {
  // Check if the head is empty
  if (head == nullptr){
    throw invalid_argument("Attempt to call function on empty list");
  }

  // if the head is not empty
  // Print the data of the head node
  cout << head->data << endl; // Return the data at the head node
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::back() const {
  // Check if the tail is empty
  if (tail == nullptr){
    throw invalid_argument("Attempt to call function on empty list");
  }

  // if the tail is not empty
  // print the data of the tail node
  cout << tail->data << endl; // Return the data at the tail node
}

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
  if (head == nullptr) { // If the head is null, aka the has to mean the list is empty 
    cout << "True" << endl;
    return true;
  }
  else {
    cout << "False" << endl;
    return false;
  }
}

template<typename Item_Type>
void SingleLinkedList<Item_Type>::insert(const Item_Type& value, size_t index){
  // Check if there is any node 
  if (index == 0){
    push_front(value);
    return;
  }

  Node* current = head;
  size_t size = 0;

  // Traverse the list to find node before the given index (index - 1)
  while (current != nullptr && size < index - 1) {
    current = current->nextptr;
    size++;
  }

  // Check if the index is out of bound 
  if (current == nullptr && current->nextptr == nullptr) {
    push_back(value);
    return;
  }

  // Create new node for the given value and update the pointers to new node
  Node* new_node = new Node(value);
  new_node->nextptr = current->nextptr;
  current->nextptr = new_node;

  num_items++; // Increment the number of items in the list
}

template<typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index){
  // Check is the list is empty
  if (index == 0){
    if (head == nullptr){
      return false;
    }
    pop_front(); // Remove the first node
    return true;
  }

  Node* current = head;
  size_t size = 0;


  // Traverse through list to the desired index
  while (current != nullptr && size < index - 1) {
    current = current->nextptr;
    size++; 
  }

  // if the current node is null or next is null, index is out of bound
  if (current == nullptr || current->nextptr == nullptr){
    return false;
  }

  // Remove the node at the given index
  Node* remove_node = current->nextptr;
  current->nextptr = remove_node->nextptr;

  // if note is the tail, set the tail to the current node
  if (remove_node == tail){
    tail = current;
  }

  delete remove_node; // Delete the node that was removed
  num_items--; // Decrement 
  return true;
}

template<typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) {
  // Set the current node to the head and index to 0
  Node* current = head; 
  size_t index = 0;

  // Traverse the list to find the item
  while (current != nullptr){
    if (current->data == item){ // if the current node's data is the item
      return index; // The item is found, return the index of item
    }
    current = current->nextptr;
    index++;
  }

  // Item is not found, return the size of the list 
  return num_items;
}

// Explicit template instantiation for integer type
template class SingleLinkedList<int>;