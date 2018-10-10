#pragma once

#include "SLNode.h"

template <typename T>
class SLIterator {
private:
	SLNode<T>* node;

public:
	SLIterator(SLNode<T>* node) {
		this->node = node;

	}

	T getData() {
		if (node) // node *exists*
			return node->data;
	
		return nullptr;
	}

	bool goNext() {
		if (node->next) { // next node *exists*
			node = node->next;
			return true;
		}
		return false;
	}
};
