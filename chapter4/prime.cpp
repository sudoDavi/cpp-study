#include <iostream>

int main() {
	std::cout << "Enter a single digit integer: ";
	int x{};
	std::cin >> x;
	
	// Unoptimized way
	// if (x == 2)
		// std::cout << "The digit is prime";
	// else if (x == 3)
		// std::cout << "The digit is prime";
	// else if (x == 5)
		// std::cout << "The digit is prime";
	// else if (x == 7)
		// std::cout << "The digit is prime";
	// else
		// std::cout << "The digit is not prime";

	// Optimized way
	if (
		x == 2 ||
		x == 3 ||
		x == 5 ||
		x == 7
	)
		std::cout << "The digit is prime";
	else
		std::cout << "The digit is not prime";

	std::cout << '\n';

	return 0;
}
