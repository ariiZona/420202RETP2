#pragma once

template <typename T>
class SLNode {
public:
	T data;
	SLNode<T>* next;

	SLNode(T data, SLNode<T>* next) {
		this->data = data;
		this->next = next;
	}
};