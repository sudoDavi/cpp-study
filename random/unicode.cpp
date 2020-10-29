#include <iostream>
#include <string>

int main() {
	std::cout << "Unicode test: " << "\u0414" << '\n';
	// Test for unicode input
	std::cout << "Input a unicode character like \u0414, with the input method you prefer: ";
	std::string unicodeInput;
	std::cin >> unicodeInput;
	std::cout << "You entered " << unicodeInput << '\n';

	return 0;
}
