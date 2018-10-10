#pragma once

#include "SLIterator.h"

template<typename T>
class Queue {
private:
	SLNode <T>* tail;
	unsigned int count;

public:
	Queue() {
		tail = nullptr;
		count = 0;
	}

	~Queue() {
		while (tail)
			pop();
	}

	void push(T data) {
		if (tail) {
			tail = tail->next = new SLNode<T>(data, tail->next);
		}
		else {
			tail = new SLNode<T>(data, nullptr);
			tail->next = tail;
		}
		count++;
	}

	void pop() {
		if (tail){
			SLNode<T>* toDelete = tail->next;
			if (tail->next == tail)
				tail = nullptr;
			else
				tail->next = toDelete->next;
			delete toDelete;
			count--;
		}
	}
	
	unsigned int size() {
		return count;
	}

	T front() {
		if (tail)
			return tail->next->data;
		return NULL;
	}

	T back() {
		if (tail)
			return tail->data;
		return NULL;
	}

	SLIterator<T>* begin() {
		return new SLIterator<T>(tail->next);
	}
};
