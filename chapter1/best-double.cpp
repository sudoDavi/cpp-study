#include <iostream>

int main() {
	std::cout << "Enter an integer: ";
	int value{ 0 }; // Creates a variable to store user input
	std::cin >> value;
	std::cout << "Double " << value << " is: " << value * 2 << '\n'; // Print to screen the double of the user input
	std::cout << "Triple " << value << " is: " << value * 3 << '\n'; // Print to screen the triple of the user input
	return 0;
}
