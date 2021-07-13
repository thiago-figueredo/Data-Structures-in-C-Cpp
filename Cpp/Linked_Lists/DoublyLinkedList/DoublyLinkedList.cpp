#include <iostream>
#include <assert.h>
#include "Node.h"
#define DoublyLinkedList DLL

template <typename T> 

class DLL {
  Node<T> *head;
  int size;

  public:
    DLL<T>() : head(nullptr), size(0) {};

    ~DLL<T> () {
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

    Node<T>* traverseTo (int index = 0) {
      Node<T> *cursor = head;

      assert(head != nullptr);
      if (index == 0) {
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
      if (head != nullptr) {
        newNode->next = head;
        head->previous = newNode;
      }

      head = newNode;
      size++;
    }

    void insertLast (T data) {
      Node<T> *newNode = new Node<T>(data);
      Node<T> *previous = traverseTo();
      previous->next = newNode;
      newNode->previous = previous;
      size++;
    }

    void insert (T data, int index) {
      Node<T> *newNode = new Node<T>(data);
      Node<T> *temp = head;
      Node<T> *previousNode = nullptr;

      if (head == nullptr) {
        return index == 0 ? insertFirst(data) : assert(head == nullptr && index == 0);
      } 
      
      if (index == 0) return insertFirst(data);
      if (index == size - 1) return insertLast(data);
      
      for (int k = 0; k < index; k++) {
        assert(temp != nullptr);
        previousNode = temp;
        temp = temp->next;
      }

      if (previousNode == nullptr) {
        head = newNode;
      } else {
        newNode->next = previousNode->next;
        previousNode->next = newNode;
        newNode->previous = previousNode;
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
      Node<T> *penultElement = traverseTo(size-2);
      Node<T> *LastElement = penultElement->next;
      penultElement->next = nullptr;
      delete LastElement;
      size--;
    }

    void deleteAt (int index) {
      if (index == 0) return deleteFirst();
      if (index == size-1) return deleteLast();
      if (index < 0 || index >= size) return;

      Node<T> *previous = nullptr;
      Node<T> *temp = head; 

      for (int i = 0; i < index; i++) {
        assert(temp != nullptr); //  1 -> 3 -> 5 -> 7 -> 8
        previous = temp;        
        temp = temp->next;      
      }

      previous->next = temp->next;
      delete temp;
      size--;
    }

    void print () {
      Node<T> *current = head;

      if (isEmpty()) {
        std::cout << "List is Empty"; 
        return;
      } 
      
      std::cout << "Linked List:\n";

      while (current) {
        if (current->previous == nullptr && current->next == nullptr) {
          std::cout << "NULL" << " <- " << current->data << " -> ";
        }

        if (current)
      
        std::cout << current->previous << " <- " << current->data << " -> " << current->next;
        current = current->next;
      }

      std::cout << "NULL";
      std::cout << '\n';
    }
};