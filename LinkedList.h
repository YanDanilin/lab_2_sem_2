#pragma once

#include <iostream>
#include <initializer_list>
#include <algorithm>


template <class T> class LinkedList {
private:
	int size = 0;
	struct Node {
		T data;
		struct Node* next = nullptr;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	LinkedList();
	LinkedList(T* arr, int count);
	LinkedList(const LinkedList<T>& linked_list);
	LinkedList(std::initializer_list<T> lst);
	~LinkedList();

	void Print();
	void Print(int num);

	T GetFirst();
	T GetLast();
	T Get(int index);
	int GetLength();

	void MySwap(LinkedList<T>& list);
	LinkedList<T>& operator=(LinkedList<T> list);

	void Append(T item);
	void Prepend(T item);
	void InsertAt(int index, T item);
	void DeleteLast();
	LinkedList<T>* Concat(LinkedList<T>* list);
	LinkedList<T>* GetSublist(int start_index, int end_index);
};

template <class T> LinkedList<T>::LinkedList(){}
template <class T> LinkedList<T>::LinkedList(T* arr, int count) : size(count) {
	for (int i = 0; i < size; i++) {
		Node* ptr = new Node;
		ptr->data = arr[i];
		if (!head) {
			head = ptr;
			tail = ptr;
		} else {
			tail->next = ptr;
			tail = ptr;
		}
	}
}
template <class T> LinkedList<T>::LinkedList(const LinkedList<T>& linked_list) : size(linked_list.size) {
	Node* cur_ptr = linked_list.head;
	for (int i = 0; i < size; i++) {
		Node* ptr = new Node;
		ptr->data = cur_ptr->data;
		if (!head) {
			head = ptr;
			tail = ptr;
		} else {
			tail->next = ptr;
			tail = ptr;
		}
		cur_ptr = cur_ptr->next;
	}
}
template <class T> LinkedList<T>::LinkedList(std::initializer_list<T> lst) {
	size = lst.size();
	T* arr = new T[size];
	std::copy(lst.begin(), lst.end(), arr);
	for (int i = 0; i < size; ++i) {
		Node* ptr = new Node;
		ptr->data = arr[i];
		if (!head) {
			head = ptr;
			tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
	}
	delete[] arr;
}
template <class T> LinkedList<T>::~LinkedList() {
	Node* ptr = nullptr;
	while (head) {
		ptr = head;
		head = head->next;
		delete ptr;
	}
}
template <class T> T LinkedList<T>::GetFirst() {
	if (!head) {
		throw std::exception("Empty list");
	}
	return head->data;
}
template <class T> T LinkedList<T>::GetLast() {
	if (!tail) {
		throw std::exception("Empty list");
	}
	return tail->data;
}
template <class T> T LinkedList<T>::Get(int index) {
	if (index < 0 || index >= size) {
		throw std::exception("Index is out of range");
	}
	struct Node* ptr = head;
	for (int i = 0; i < index; ++i) {
		ptr = ptr->next;
	}
	return ptr->data;
}
template <class T> int LinkedList<T>::GetLength() {
	return size;
}
template <class T> void LinkedList<T>::MySwap(LinkedList<T>& list) {
	std::swap(size, list.size);
	std::swap(head, list.head);
	std::swap(tail, list.tail);
}
template <class T> LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> list) {
	MySwap(list);
	return *this;
}
template <class T> LinkedList<T>* LinkedList<T>::GetSublist(int start_index, int end_index) {//�������� ������
	if (start_index < 0 || start_index >= size || end_index < 0 || end_index >= size) {
		throw std::exception("Index is out of range");
	}
	LinkedList<T>* sublist = new LinkedList<T>;
	sublist->size = end_index - start_index + 1;
	Node* ptr = head;
	for (int i = 0; i < start_index; ++i) {
		ptr = ptr->next;
	}
	for (int i = start_index; i <= end_index; ++i) {
		Node* new_ptr = new Node;
		new_ptr->data = ptr->data;
		if (!sublist->head) {
			sublist->head = new_ptr;
			sublist->tail = new_ptr;
		} else {
			sublist->tail->next = new_ptr;
			sublist->tail = new_ptr;
		}
		ptr = ptr->next;
	}
	return sublist;
}
template <class T> void LinkedList<T>::Append(T item) {
	if (!head || !tail) {
		++size;
		Node* ptr = new Node;
		ptr->data = item;
		head = ptr;
		tail = ptr;
		return;
	}
	++size;
	Node* ptr = new Node;
	ptr->data = item;
	tail->next = ptr;
	tail = ptr;
}
template <class T> void LinkedList<T>::Prepend(T item) {
	if (!head || !tail) {
		++size;
		Node* ptr = new Node;
		head = ptr;
		tail = ptr;
	}
	++size;
	Node* ptr = new Node;
	ptr->data = item;
	ptr->next = head;
	head = ptr;
}
template <class T> void LinkedList<T>::InsertAt(int index, T item) {
	if (index < 0 || index >= size) {
		throw std::exception("Index is out of range");
	}
	++size;
	Node* ptr = head;
	for (int i = 0; i < index - 1; ++i) {
		ptr = ptr->next;
	}
	Node* new_node = new Node;
	new_node->data = item;
	new_node->next = ptr->next;
	ptr->next = new_node;
}
template <class T> void LinkedList<T>::DeleteLast() {
	if (head) {
		Node* ptr = head;
		if (ptr == tail) {
			delete ptr;
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}
		while (ptr->next != tail) {
			ptr = ptr->next;
		}
		delete tail;
		tail = ptr;
		ptr->next = nullptr;
	}
}
template <class T> LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list) {
	LinkedList<T>* new_list = new LinkedList<T>(*this);
	new_list->size = this->size + list->size;
	Node* ptr = list->head;
	while (ptr) {
		Node* new_node = new Node;
		new_node->data = ptr->data;
		if (!new_list->head) {
			new_list->head = ptr;
			new_list->tail = ptr;
		} else {
			new_list->tail->next = ptr;
			new_list->tail = ptr;
		}
		ptr = ptr->next;
	}
	return new_list;
}
template <class T> void LinkedList<T>::Print() {
	Node* ptr = head;
	while (ptr) {
		std::cout << ptr->data << '\n';
		ptr = ptr->next;
	}
}
template <class T> void LinkedList<T>::Print(int num) {
	Node* ptr = head;
	std::cout << " |";
	while (ptr) {
		std::cout << " -> " << ptr->data;
		ptr = ptr->next;
	}
	std::cout << '\n';
}