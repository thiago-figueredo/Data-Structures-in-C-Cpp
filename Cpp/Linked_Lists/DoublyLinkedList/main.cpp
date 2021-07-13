#include "DoublyLinkedList.cpp"

int main () {
  DLL<int> intList;
  intList.insertFirst(5);
  intList.insertFirst(7);
  intList.print();
  return 0;
}