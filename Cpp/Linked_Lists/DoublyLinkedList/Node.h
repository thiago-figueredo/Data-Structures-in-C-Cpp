#ifndef __NODE_H
#define __NODE_H

template <typename T>

struct Node {
  T data;
	Node<T> *previous;
	Node<T> *next;

	Node (T data = NULL, Node<T> *previous = nullptr, Node<T> *next = nullptr) {
		this->data = data;
		this->previous = previous;
		this->next = next;
	}
};


#endif