#pragma once

#include "Sequence.h"
#include <initializer_list>


//using namespace std;

template <class T>
class Stack {
private:
	Sequence<T>* ptr_sequence = nullptr;
	int var = 0;
	void Choose();
public:
	Stack();
	Stack(int var);
	Stack(Stack<T>& another);
	Stack(std::initializer_list<T> lst);
	~Stack();

	int Size();
	void Pop();
	void Push(T item);
	T Top();
	bool Empty();
	Stack<T>* Concat(Stack<T>* stack);
	Stack<T>* GetSubstack(int start_index, int end_index);

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
Stack<T>::Stack(Stack<T>& another) {
	var = another.var;
	switch (var) {
	case 1:
		ArraySequence<T> *copy_arr = static_cast<Sequence<T>*>(another.ptr_sequence);
		ptr_sequence = new ArraySequence<T>(*copy_arr);
		break;
	case 2:
		LinkedListSequence<T> *copy_list = static_cast<Sequence<T>*>(another.ptr_sequence);
		ptr_sequence = new LinkedListSequence<T>(*copy_list);
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
void Stack<T>::Print() {
	ptr_sequence->Print();
}
template <class T>
void Stack<T>::Print(int num) {
	ptr_sequence->Print(num);
}