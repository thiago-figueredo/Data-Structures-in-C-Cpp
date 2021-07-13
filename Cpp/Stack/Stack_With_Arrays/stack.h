#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdint>

template <typename T>

class Stack {
  T* arr;
  int64_t top;
  size_t capacity;

  public:
    Stack () {
      arr = NULL;
      top = - 1;
      capacity = 0;
    }

    Stack (size_t capacity) {
      arr = new T[capacity];
      this->capacity = capacity;
      top = -1;
    }
    
    ~Stack () {
      delete[] arr;
    }

    bool isEmpty () {
      return capacity == 0;
    }

    bool isFull () {
      return top == capacity - 1;
    } 

    void isEmptyError () {
      std::cout << "Stack is Empty!" << '\n';
      exit(EXIT_FAILURE);
    }

    void isFullError () {
      std::cout << "Stack is Full!" << '\n';
      exit(EXIT_FAILURE);
    }

    void print () {
      if (isEmpty()) isEmptyError();

      std::cout << "Stack: ";
      for (size_t i = 0; i <= top; i++) {
        std::cout << arr[i];

        if (i < top) std::cout << ", ";
      }

      std::cout << '\n';
    }

    void push (T element) {
      if (isFull()) isFullError();
      arr[++top] = element;
    }

    T peek () {
      if (isEmpty()) isFullError();
      return arr[top];
    }

    void pop () {
      if (isEmpty()) isEmptyError();
      return arr[top--];
    }

    size_t size () {
      return top + 1;
    }
};

#endif
