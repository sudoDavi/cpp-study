#include <iostream>

bool isEven(int x) {
	return !(x % 2);
}

int main() {
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	if (isEven(input))
		std::cout << input << " is even";
	else
		std::cout << input << " is odd";

	std::cout << '\n';

	return 0;
}
