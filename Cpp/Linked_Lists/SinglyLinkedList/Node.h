#ifndef NODE_H
#define NODE_H
template <typename T> 

struct Node { 
  T data;
  Node<T> *next;

  Node (T data = NULL, Node<T> *next = nullptr) {
    this->data = data;
    this->next = next;
  };
};

#endif