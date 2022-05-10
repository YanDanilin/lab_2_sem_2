#include <iostream>

#include "Complex.h"
#include "TowersOfHanoi.h"


int main() {
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}// {0, 1, 2, 3, 4}

	//Sequence<int> *ex = new ArraySequence<int>(5, arr);
	//ex->Print();
	ArraySequence<int> darr{1, 2, 3, 4};
	ArraySequence<int> copy = darr;
	copy.Print();
	//darr.Print();
	//std::cout << "================\n";
	//LinkedListSequence<double> list{5.5, 6.6, 7.7, 8.8};
	//list.Print();

	/*Stack<int> st{0, 1, 2, 3, 4, 5, 6, 7, 8};
	Stack<int> st1{ 6, 9, 12 };
	Stack<int>* res = st.GetSubstack(2, 5);
	res->Print();
	std::cout << "=========\n";
	std::cout << st.Top() << '\n';
	st.Pop();
	std::cout << "After popping:\n";
	st.Print();
	st.Push(111);
	std::cout << "After pushing\n";
	st.Print();
	Stack<double> st2;
	if (st2.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}*/
	
	Complex z(1.1, 2.2);
	Complex x;
	std::cout << z << '\n' << x << '\n';

	//Stack<int> source{3, 2, 1};
	//Stack<int> destination = source;
	/*std::cout << "Before:\n";
	source.Print(1);
	if (source.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "-----------\n";
	destination.Print(1);
	if (destination.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "========================\n";
	
	TowersOfHanoi(source.Size(), source, destination);
	
	std::cout << "After:\n";
	source.Print(1);
	if (source.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "-----------\n";
	destination.Print(1);
	if (destination.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}*/


	return 0;
}