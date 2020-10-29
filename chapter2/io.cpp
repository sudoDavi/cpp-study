#include "io.h"

#include <iostream>

int readNumber() {
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;
	return input;
}

void writeAnswer(int asw) {
	std::cout << "The addition of the inputs equals: " << asw << '\n';
}
