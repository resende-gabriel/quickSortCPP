#include "Stack.hpp"

using namespace std;

template <class T>
Stack<T>::~Stack<T>() {
	Node<T> *aux = this->top;
	while(this->top != nullptr) {
		this->top = this->top->next;
		delete aux;
		aux = this->top;
	}
}

template <class T>
void Stack<T>::Push(T val) {
	this->length++;
	Node<T> *newNode = new Node<T>(val);
	newNode->next = top;
	this->top = newNode;
	return;
}

template <class T>
T Stack<T>::Pop() {
	if(this->length <= 0) {
		return 0;
	}
	Node<T>* aux;
	this->length--;
	T data = top->data;
	aux = top;
	top = top->next;
	delete aux;
	return data;
}

template <class T>
int Stack<T>::Length() {
	return this->length;
}

template class Stack<int>;
template class Node<int>;