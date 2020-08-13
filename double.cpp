#include <iostream>

// Returns double the value of the parameter
int doubleNumber(int a) {
	return a * 2;
}

int main() {
	std::cout << "Enter an integer: ";
	int value{}; // Creates a variable to store user input
	std::cin >> value;
	std::cout << "Double that number is: " << doubleNumber(value)  << '\n'; // Print to screen the double of the user input
	return 0;
}
