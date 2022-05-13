#pragma once

#include <initializer_list>
#include "DynamicArray.h"
#include "LinkedList.h"


template <class T> class Sequence {
public:
	virtual ~Sequence() = 0;
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual T Get(int index) = 0;
	virtual int GetLength() = 0;

	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void InsertAt(int index, T item) = 0;
	virtual void DeleteLast() = 0;

	virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
	virtual Sequence<T>* GetSubsequence(int start_index, int end_index) = 0;
	virtual void Print() = 0;
	virtual void Print(int num) = 0;
};

template <class T> Sequence<T>::~Sequence() {}

template <class T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* array_items = nullptr;
public:
	ArraySequence() {
		array_items = new DynamicArray<T>;
	}
	ArraySequence(size_t size, T* items) {
		array_items = new DynamicArray<T>(size, items);
	}
	ArraySequence(const ArraySequence<T>& another) {
		array_items = new DynamicArray<T>(*(another.array_items));
	}
	ArraySequence(std::initializer_list<T> lst) {
		array_items = new DynamicArray<T>(lst);
	}
	~ArraySequence() override {
		delete array_items;
	}
	T GetFirst() override {
		return array_items->Get(0);
	}
	T GetLast() override {
		return array_items->Get(array_items->GetSize() - 1);
	}
	T Get(int index) override {
		return array_items->Get(index);
	}
	int GetLength() override {
		return array_items->GetSize();
	}
	void Append(T item) override {
		array_items->Resize(array_items->GetSize() + 1);
		array_items->Set(array_items->GetSize() - 1, item);
	}
	void Prepend(T item) override {
		array_items->InsertAt(0, item);
	}
	void InsertAt(int index, T item) override {
		array_items->InsertAt(index, item);
	}
	void DeleteLast() override {
		array_items->Resize(array_items->GetSize() - 1);
	}
	ArraySequence<T>* Concat(Sequence<T>* list) override {
		ArraySequence<T>* arr_seq_ptr = static_cast<ArraySequence<T>*>(list);
		ArraySequence<T>* res = new ArraySequence<T>;
		res->array_items = array_items->Concat(arr_seq_ptr->array_items);
		return res;
	}
	ArraySequence<T>* GetSubsequence(int start_index, int end_index) override {
		ArraySequence<T>* res = new ArraySequence<T>;
		res->array_items = array_items->GetSublist(start_index, end_index);
		return res;
	}
	void Print() override {
		array_items->Print();
	}
	void Print(int num) override {
		array_items->Print(num);
	}
	bool operator==(const ArraySequence<T>& arr) {
		return (*array_items == *arr.array_items);
	}
};

template <class T> class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* list_items = nullptr;
public:
	LinkedListSequence() {
		list_items = new LinkedList<T>;
	}
	LinkedListSequence(size_t size, T* items) {
		list_items = new LinkedList<T>(size, items);
	}
	LinkedListSequence(const LinkedListSequence<T>& another) {
		list_items = new LinkedList<T>(*(another.list_items));
	}
	LinkedListSequence(std::initializer_list<T> lst) {
		list_items = new LinkedList<T>(lst);
	}
	~LinkedListSequence() override {
		delete list_items;
	}
	T GetFirst() override {
		return list_items->GetFirst();
	}
	T GetLast() override {
		return list_items->GetLast();
	}
	T Get(int index) override {
		return list_items->Get(index);
	}
	int GetLength() override {
		return list_items->GetLength();
	}
	void Append(T item) override {
		list_items->Append(item);
	}
	void Prepend(T item) override {
		list_items->Prepend(item);
	}
	void InsertAt(int index, T item) override {
		list_items->InsertAt(index, item);
	}
	void DeleteLast() override {
		list_items->DeleteLast();
	}
	LinkedListSequence<T>* Concat(Sequence<T>* list) override {
		LinkedListSequence<T>* lst_seq_ptr = static_cast<LinkedListSequence<T>*>(list);
		LinkedListSequence<T>* res = new LinkedListSequence<T>;
		res->list_items = list_items->Concat(lst_seq_ptr->list_items);
		return res;
	}
	LinkedListSequence<T>* GetSubsequence(int start_index, int end_index) override {
		LinkedListSequence<T>* res = new LinkedListSequence<T>;
		res->list_items = list_items->GetSublist(start_index, end_index);
		return res;
	}
	void Print() override {
		list_items->Print();
	}
	void Print(int num) override {
		list_items->Print(num);
	}
	bool operator==(const LinkedListSequence<T>& lst) {
		return (*list_items == *lst.list_items);
	}
};