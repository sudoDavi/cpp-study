#include <iostream>
#include <iterator>

constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

int askInteger() {
	bool repeat{ false };
	do {
		std::cout << "Please enter a value between 1 and 9: ";
		int input{};
		std::cin >> input;

		// Checking to see if extraction failed
		if (std::cin.fail() || (input < 1) || (input > 9)) {
			// if so, fix it and repeat input
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			repeat = true;
		}
		else {
			std::cin.clear();
			return input;
		}
	}while (repeat);

	// just here so compiler doesn't complain
	return 1;
}

int main() {
	int arraySize{ std::size(array) };
	
	int userInput{ askInteger() };
	
	for (int i = 0; i < arraySize; ++i) {
		std::cout << array[i];
		if (userInput == array[i])
			std::cout << " Your input is at index: " << i << '\n';
		else
			std::cout << '\n';
	}

	return 0;
}
