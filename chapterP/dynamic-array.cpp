#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

size_t getNameCount() {
	bool repeat{ false };
	do {
		std::cout << "Enter how many names you would like to input: ";
		size_t input;
		std::cin >> input;
		
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			repeat = true;
		} else {
			std::cin.ignore(32767, '\n');
			return input;
		}
	} while (repeat);
	// If it ever reaches 0, god help us
	return 0;
}

// Had to change the functions so they receive the lenght of the array
// otherwise it didn't print properly
void inputNames(std::string *array, size_t lenght) {
	for (size_t index{ 0 }; index < lenght; ++index) {
		// Add 1 so it counts the names properly
		std::cout << "Enter name #" << index + 1 << ": ";
		std::getline(std::cin, array[index]);
	}
}

void printList(std::string *array, size_t lenght) {
	for (size_t index{ 0 }; index < lenght; ++index) {
		// Add 1 to count... you know the deal
		std::cout << "Name #" << index + 1 << ": " + array[index] + '\n';
	}
}

int main() {
	size_t nameCount{ getNameCount() };

	std::string *nameList{ new std::string[nameCount]{} };

	inputNames(nameList, nameCount);
	std::sort(nameList, nameList + nameCount);

	std::cout << "Here is your sorted list:\n";
	printList(nameList, nameCount);

	// Forgot this one on the first run
	// shame on me
	delete[] nameList;

	return 0;
}
