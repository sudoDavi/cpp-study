#include <iostream>

void printBinary(unsigned int decimal) {
	if (decimal > 1) {
		printBinary(decimal / 2);
	}

	std::cout << decimal % 2;
}

int main() {
	std::cout << "Enter a integer: ";
	int input{};
	std::cin >> input;

	std::cout << "Your number in binary: ";
	printBinary(static_cast<unsigned int>(input));

	std::cout << '\n';

	return 0;
}
