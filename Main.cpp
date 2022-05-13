#include <iostream>

#include "Student.h"
#include "Complex.h"
#include "TowersOfHanoi.h"
#include <time.h>

int main() {
	int* arr = new int[5];
	for (int i = 0; i < 5; ++i) {
		arr[i] = i;
	}// {0, 1, 2, 3, 4}

	Stack<int> source{5, 4, 3, 2, 1 };
	Stack<int> destination;


	std::cout << "Before:\nSource:\n";
	source.Print(1);
	if (source.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "-----------\nDestination\n";
	destination.Print(1);
	if (destination.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "========================\n";
	

	TowersOfHanoi(source.Size(), source, destination);


	std::cout << "After:\nSource:\n";
	source.Print(1);
	if (source.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}
	std::cout << "-----------\nDestination:\n";
	destination.Print(1);
	if (destination.Empty()) {
		std::cout << "Empty\n";
	}
	else {
		std::cout << "Not empty\n";
	}


	return 0;
}