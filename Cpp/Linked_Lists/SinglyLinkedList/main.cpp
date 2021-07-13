#include "SinglyLinkedList.cpp"
#include <string>

int main () {
  SLL<int> intList;
  intList.insertFirst(10);
  intList.insertFirst(20);
  intList.insertFirst(30);
  intList.insertLast(7);
  intList.insertLast(17);
  intList.insertLast(77);
  intList.deleteFirst();
  intList.deleteFirst();
  intList.deleteLast();
  intList.deleteLast();
  intList.insert(5,0);
  intList.insert(15, intList.getSize() - 1);
  intList.insert(4,1);
  intList.insert(14,2);
  intList.insert(0,1);
  intList.insert(24,5);
  intList.deleteAt(0);
  intList.deleteAt(intList.getSize() + 10);
  intList.deleteAt(-10);
  intList.deleteAt(intList.getSize() - 1);
  intList.deleteAt(2);
  intList.deleteAt(1);

  intList.print(); // 0 -> 10 -> 24 -> - 7 -> NULL

  intList.reverse();
  intList.print(); // 7 -> 24 -> 10 -> 0 -> NULL

  // SLL<std::string> stringList;
  // stringList.insertFirst("a");
  // stringList.insertFirst("bob");
  // stringList.insertFirst("c++");
  // stringList.insertLast("d");
  // stringList.insertLast("c");
  // stringList.insertLast("fox");
  // stringList.deleteFirst();
  // stringList.deleteLast();
  // stringList.insert("hi", 0);
  // stringList.insert("hello world", stringList.getSize() - 1);
  // stringList.insert("Singly Linked List", 3);
  // stringList.insert("void", 1);
  // stringList.deleteFirst();
  // stringList.deleteLast();
  // stringList.deleteAt(2);
  // stringList.deleteAt(0);
  // stringList.deleteAt(stringList.getSize() - 1);

  // stringList.print(); // bob -> Singly Linked List -> d -> NULL 

  // stringList.reverse();
  // stringList.print(); // d -> Singly Linked List -> bob

  // SLL<bool> boolList;
  // boolList.insertFirst(true);
  // boolList.insertLast(false);
  // boolList.insert('0', 1);
  // boolList.insert('1', boolList.getSize() - 1);
  // boolList.insert(false, 0);
  // boolList.deleteFirst();
  // boolList.deleteLast();
  // boolList.deleteAt(1);

  // boolList.print(); // 1 -> 1 -> NULL

  // boolList.reverse();
  // boolList.print(); // 1 -> 1 -> NULL

  // SLL<char> charList;
  // charList.insertLast('n'); 
  // charList.insertFirst('k'); 
  // charList.insert('p', charList.getSize() - 1); 
  // charList.insert('^', 0);
  // charList.insert('~', 2);
  // charList.deleteFirst();
  // charList.deleteLast();
  // charList.deleteAt(1);

  // charList.print(); // k -> n -> NULL

  // charList.reverse();
  // charList.print(); // n -> k -> NULL

  return 0;
}