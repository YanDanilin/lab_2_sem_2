#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>

//using namespace std;

template <class T> class DynamicArray {
private:
	int size = 0;
	T* array = nullptr;
public:
	DynamicArray(){};
	DynamicArray(int size, T* arr);
	DynamicArray(const DynamicArray<T>& d_arr);
	DynamicArray(std::initializer_list<T> lst);
	~DynamicArray();

	void MySwap(DynamicArray<T>& d_arr);
	DynamicArray<T>& operator=(DynamicArray<T> d_arr);

	void Print();
	void Print(int num);

	T Get(int index);
	int GetSize();
	void Set(int index, T value);
	void Resize(int new_size);
	void InsertAt(int index, T value);

	DynamicArray<T>* GetSublist(int start_index, int end_index);
	DynamicArray<T>* Concat(DynamicArray<T>* another);
};

template <class T> DynamicArray<T>::DynamicArray(int size, T* arr) : size(size), array(new T[size + 1]) {
	memcpy(array, arr, size * sizeof(T));
}
template <class T> DynamicArray<T>::DynamicArray(const DynamicArray<T>& d_arr) : DynamicArray(d_arr.size, d_arr.array) {
	//memcpy(array, d_arr.array, size * sizeof(T));
}
template <class T> DynamicArray<T>::DynamicArray(std::initializer_list<T> lst) {
	size = lst.size();
	this->array = new T[size];
	std::copy(lst.begin(), lst.end(), this->array);
}
template <class T> DynamicArray<T>::~DynamicArray() {
	delete[] array;
}
template <class T> void DynamicArray<T>::MySwap(DynamicArray<T>& d_arr) {
	std::swap(size, d_arr.size);
	swap(array, d_arr.array);
}
template <class T> DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> d_arr) {
	MySwap(d_arr);
	return *this;
//DynamicArray& operator=(DynamicArray& d_arr) {
//if (array) {
//		delete[] array;
//	}
//size = d_arr.size;
//array = new T[];
//memcpy(array, d_arr, size*sizeof(T));
//}
}
template <class T> T DynamicArray<T>::Get(int index) {
	if (index < 0 || index >= size) {
		throw std::exception("Index is out of range");
	}
	return array[index];
}
template <class T> int DynamicArray<T>::GetSize() {
	return size;
}
template <class T> void DynamicArray<T>::Set(int index, T value) {
	if (index < 0 || index > size) {
		throw std::exception("Index is out of range");
	}
	array[index] = value;
}
template <class T> void DynamicArray<T>::Resize(int new_size) {
	if (new_size < 0) {
		throw std::exception("Index is out of range");
	}
	T* buf = new T[size];
	std::memcpy(buf, array, size * sizeof(T));
	delete[] this->array;
	array = new T[new_size + 1];
	std::memcpy(array, buf, size * sizeof(T));
	delete[] buf;
	size = new_size;
}
template <class T> void DynamicArray<T>::InsertAt(int index, T value) {
	if (index < 0 || index > size) {
		throw std::exception("Index is out of range");
	} else {
		Resize(size + 1);
		//for (int i = size - 1; i > index; i--) {
		//	Set(i, array[i - 1]);
		//}
		//Set(index, value);
		std::memmove(array + index + 1, array + index, (size - index - 1) * sizeof(T));
		Set(index, value);
	}
}
template <class T> DynamicArray<T>* DynamicArray<T>::GetSublist(int start_index, int end_index) {
	if (start_index < 0 || start_index >= size || end_index < 0 || end_index >= size) {
		throw std::exception("Index is out of range");
	} else {
		DynamicArray<T>* res = new DynamicArray<T>(end_index - start_index + 1, array + start_index);
		return res;
	}
}
template <class T> DynamicArray<T>* DynamicArray<T>::Concat(DynamicArray<T>* another) {
	DynamicArray<T>* res = new DynamicArray<T>(*this);
	res->Resize(another->GetSize() + this->GetSize());
	std::memcpy(res->array + size, another->array, another->GetSize() * sizeof(T));
	return res;
}
template <class T> void DynamicArray<T>::Print() {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << '\n';
	}
}
template <class T> void DynamicArray<T>::Print(int num) {
	std::cout << " |";
	for (int i = 0; i < size; ++i) {
		std::cout << " -> " << array[i] ;
	}
	std::cout << '\n';
}
