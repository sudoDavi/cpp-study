#include <iostream>

int main() {
	std::cout << "Enter an integer: ";
	int first{};
	std::cin >> first;
	
	std::cout << "Enter another integer: ";
	int second{};
	std::cin >> second;

	std::cout << first << " + " << second << " is " << first + second << ".\n";
	std::cout << first << " - " << second << " is " << first - second << ".\n";
	return 0;
}
