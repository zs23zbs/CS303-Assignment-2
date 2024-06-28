#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  SingleLinkedList<int> list; 

  list.push_front(1);
  list.push_front(4);
  list.print_list();
}