#include <iostream>
#include <assert.h>
#include "Node.h"
#define SinglyLinkedList SLL

template <typename T> 

class SLL {
  Node<T> *head;
  int size;

  public:
    SLL<T>() : head(nullptr), size(0) {};

    ~SLL<T> () {
      Node<T> *temp = head;

      while (temp) {
        Node<T> *nextNode = temp->next;
        delete temp;
        temp = nextNode;
        size--;
      }
    }

    Node<T>* getHead () const {
      return head;
    }

    int getSize () const {
      return size;
    }

    bool isEmpty () {
      return size == 0 ? true : false;
    }

    Node<T>* traverseTo (int index = -1) {
      Node<T> *cursor = head;

      if (index == 0) {
        return cursor;
      } else if (index == -1) {
        for (int i = 0; i < size-1; i++) {
          cursor = cursor->next;
        }
      } else {
        for (int j = 0; j < index; j++) {
          cursor = cursor->next;
        }
      }

      return cursor;
    }

    void insertFirst (T data) {
      Node<T> *newNode = new Node<T>(data);
      if (head != nullptr) newNode->next = head;
      head = newNode;
      size++;
    }

    void insertLast (T data) {
      if (size == 0) return insertFirst(data);
      
      Node<T> *newNode = new Node<T>(data);
      Node<T> *previous = traverseTo();
      previous->next = newNode;
      size++;
    }

    void insert (T data, int index) {
      Node<T> *newNode = new Node<T>(data);
      Node<T> *temp = head;
      Node<T> *previous = nullptr;

      if (head == nullptr) return index == 0 ? insertFirst(data) : assert(head == nullptr && index == 0);
      if (index == 0) return insertFirst(data);
      if (index == size-1) return insertLast(data);
      
      for (int k = 0; k < index; k++) {
        assert(temp != nullptr);
        previous = temp;
        temp = temp->next;
      }

      if (previous == nullptr) {
        head = newNode;
      } else {
        newNode->next = previous->next;
        previous->next = newNode;
      }

      size++;
    }

    void deleteFirst () {
      assert(head != nullptr);
      Node<T> *oldHead = head;
      head = oldHead->next;
      delete oldHead;
      size--;
    }

    void deleteLast () {
      Node<T> *penultNode = nullptr;
      Node<T> *lastNode = nullptr;
      
      if (size == 1) {
        head = nullptr;
        delete head;
      } else {
        penultNode = traverseTo(size-2);
        lastNode = penultNode->next;
        penultNode->next = nullptr;
        delete lastNode;
      }

      size--;
    }

    void deleteAt (int index) {
      if (index == 0) return deleteFirst();
      if (index == size-1) return deleteLast();
      if (index < 0 || index >= size) return;

      Node<T> *previous = nullptr;
      Node<T> *temp = head; 

      for (int i = 0; i < index; i++) {
        assert(temp != nullptr); 
        previous = temp;        
        temp = temp->next;      
      }

      previous->next = temp->next;
      delete temp;
      size--;
    }

    void reverse (Node<T> *node = nullptr) {
      Node<T> *previousNode = nullptr;
      Node<T> *currentNode = head;
      Node<T> *nextNode = nullptr;

      while (currentNode) {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
      }

      head = previousNode;
    }

    void print () {
      Node<T> *current = head;

      if (isEmpty()) {
        std::cout << "List is Empty"; 
      } else {
        std::cout << "Linked List:\n";

        while (current) {
          if (current->previous == nullptr && current->next == nullptr) 
            std::cout << "NULL" << current->data << " -> ";
          current = current->next;
        }

        std::cout << "NULL";
        std::cout << '\n';
      }
    }
};
