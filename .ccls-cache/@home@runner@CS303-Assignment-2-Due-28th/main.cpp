#include "LinkedList.h"
#include "stack.h" // Everything is working so far, just need to make program
#include <iostream>

using namespace std;

int main() {

  // Hell yeah!!!! All member functions are working!!! Now need to make the stack program. 
  SingleLinkedList<int> list;
  list.push_front(3);
  list.push_front(10);
  list.push_front(24546);
  list.insert(0, 2);
  list.insert(90, 4);
  list.remove(2);
  list.print_list();
  
  // Find and print the positions of elements in the list
  size_t pos1 = list.find(6);
  cout << "Position of 6: " << pos1 << endl;

  size_t pos2 = list.find(90);
  cout << "Position of 90: " << pos2 << endl;
  return 0;
}