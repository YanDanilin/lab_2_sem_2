#pragma once

#include <iostream>
#include "Stack.h"


template <class T>
void MoveDisc(Stack<T>& from, Stack<T>& to) {
	T buf = from.Top();
	from.Pop();
	to.Push(buf);
}

template <class T>
void HanoiTowers(int quant, Stack<T>& src, Stack<T>& dest, Stack<T>& tmp) {
	if (quant == 1) {
		MoveDisc(src, dest);
	}
	else {
		HanoiTowers(quant - 1, src, tmp, dest);
		MoveDisc(src, dest);
		HanoiTowers(quant - 1, tmp, dest, src);
	}
}

template <class T>
void TowersOfHanoi(int quant, Stack<T>& src, Stack<T>& dest) {
	if (quant <= 0) {
		throw std::exception("Index is out of range");
	}
	Stack<T> tmp(1);
	HanoiTowers(quant, src, dest, tmp);
}
