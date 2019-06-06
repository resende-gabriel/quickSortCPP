#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

// Nodo generico, pode ser usado com qualquer tipo
template<class T>
class Node {

	public:
		Node<T>(T val) {
			this->data = val;
			this->next = nullptr;
		};
		Node<T> *next;
		T data;

	private:
};

// Pilha generica, pode ser usada com qualquer tipo
template<class T>
class Stack {

	public:
		Stack<T>() {
			this->top = nullptr;
			this->length = 0;
		};
		~Stack<T>();
		
		// Retira o ultimo nodo da pilha, retornando seu conteudo
		T Pop();
		// Insere um novo nodo na pilha com o valor recebido
		void Push(T val);
		// Retorna o tamanho da pilha. 0 = vazia
		int Length();

	private:
		Node<T> *top;
		int length;
};

#endif