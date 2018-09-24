#pragma once

#include "SLNode.h"
#include "SLIterator.h"

template <typename T>
class Stack{
private:
	SLNode<T>* sp;
	unsigned int count;

public:
	Stack() {
		sp = nullptr;
		count = 0;
	}

	~Stack() {
		while (sp)  // sp *exists*
			pop();
	}

	void push(T data) {
		sp = new SLNode<T>(data, SP);
		count++;
	}

	void pop() {
		if (SP != nullptr) {
			SLNode<T>* toDelete = sp;
			sp = sp->next;
			delete toDelete;
			count--;
		}
	}

	T top() {
		if (SP) {
			return SP->data;
		}
		return NULL;
	}

	unsigned int size() {
		return count;
	}

	SLIterator<T>* begin() {
		return new SLIterator<T>(sp);
	}
};