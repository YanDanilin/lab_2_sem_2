#pragma once

#include "Sequence.h"
#include <initializer_list>



template <class T>
class Stack {
private:
	Sequence<T>* ptr_sequence = nullptr;
	int var = 0;
	void Choose();
public:
	Stack();
	Stack(int var);
	Stack(int size, T* items);
	Stack(Stack<T>& another);
	Stack(std::initializer_list<T> lst);
	Stack(std::initializer_list<T> lst, int var);
	~Stack();

	int Size();
	void Pop();
	void Push(T item);
	T Top();
	bool Empty();
	Stack<T>* Concat(Stack<T>* stack);
	Stack<T>* GetSubstack(int start_index, int end_index);

	Stack<T> Map(T(*func)(T));
	T Reduce(T(*func)(T, T), T value);

	void Print();
	void Print(int num);
};
template <class T>
void Stack<T>::Choose() {
	std::cout << "Chose base for your stack\n 1. Array\n 2. Linked list\n";
	std::cin >> var;
}
template <class T>
Stack<T>::Stack() {
	Choose();
	switch (var) {
	case 1: 
		ptr_sequence = new ArraySequence<T>;
		break;
	case 2: 
		ptr_sequence = new LinkedListSequence<T>;
		break;
	default: 
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::Stack(int variant): var(variant) {
	switch (var) {
	case 1:
		ptr_sequence = new ArraySequence<T>;
		break;
	case 2:
		ptr_sequence = new LinkedListSequence<T>;
		break;
	default:
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::Stack(int size, T* items) {
	Choose();
	switch (var) {
	case 1:
		ptr_sequence = new ArraySequence<T>(size, items);
		break;
	case 2:
		ptr_sequence = new LinkedListSequence<T>(size, items);
		break;
	default:
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::Stack(Stack<T>& another) {
	var = another.var;
	ArraySequence<T>* copy_arr = static_cast<ArraySequence<T>*>(another.ptr_sequence);
	LinkedListSequence<T>* copy_list = static_cast<LinkedListSequence<T>*>(another.ptr_sequence);
	switch (var) {
	case 1:
		ptr_sequence = new ArraySequence<T>(*copy_arr);
		break;
	case 2:
		ptr_sequence = new LinkedListSequence<T>(*copy_list);
		break;
	default:
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::Stack(std::initializer_list<T> lst, int var) {
	switch (var) {
	case 1:
		ptr_sequence = new ArraySequence<T>(lst);
		break;
	case 2:
		ptr_sequence = new LinkedListSequence<T>(lst);
		break;
	default:
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::Stack(std::initializer_list<T> lst) {
	Choose();
	switch (var) {
	case 1:
		ptr_sequence = new ArraySequence<T>(lst);
		std::cout << "Array is used\n";
		break;
	case 2:
		ptr_sequence = new LinkedListSequence<T>(lst);
		std::cout << "List is used\n";
		break;
	default:
		throw std::exception("Not appropriate variant");
	}
}
template <class T>
Stack<T>::~Stack() {
	delete ptr_sequence;
}
template <class T>
int Stack<T>::Size() {
	return ptr_sequence->GetLength();
}
template <class T>
void Stack<T>::Push(T item) {
	ptr_sequence->Append(item);
}
template <class T>
T Stack<T>::Top() {
	return ptr_sequence->GetLast();
}
template <class T>
bool Stack<T>::Empty() {
	if (ptr_sequence->GetLength() == 0) {
		return true;
	} else {
		return false;
	}
}
template <class T>
void Stack<T>::Pop() {
	ptr_sequence->DeleteLast();
}
template <class T>
Stack<T>* Stack<T>::Concat(Stack<T>* stack) {
	if (var != stack->var) {
		throw std::exception("Incomparable types of stacks");
	}
	Stack<T>* res = new Stack<T>(var);
	res->ptr_sequence = ptr_sequence->Concat(stack->ptr_sequence);
	return res;
}
template <class T>
Stack<T>* Stack<T>::GetSubstack(int start_index, int end_index) {
	Stack<T>* res = new Stack<T>(var);
	res->ptr_sequence = ptr_sequence->GetSubsequence(start_index, end_index);
	return res;
}

template <class T>
Stack<T> Stack<T>::Map(T(*func)(T)) {
	Stack<T> tmp(this->var);
	for (int i = 0; i < this->Size(); ++i) {
		tmp.Push(func(this->Top()));
	}
	Stack<T> res(this->var);
	for (int j = 0; j < this->Size(); ++j) {
		res.Push(tmp.Top());
	}
	return res;
}
template <class T>
T Stack<T>::Reduce(T(*func)(T, T), const T value) {
	Stack<T> copy(*this);
	T res = func(copy.Top(), value);
	copy.Pop();
	for (int i = 1; i < this->Size(); ++i) {
		res = func(copy.Top(), res);
		copy.Pop();
	}
	return res;
}
template <class T>
void Stack<T>::Print() {
	ptr_sequence->Print();
}
template <class T>
void Stack<T>::Print(int num) {
	ptr_sequence->Print(num);
}
