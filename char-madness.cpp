#include <iostream>
#include <cstdlib>

int main() {
	char c{ 'U' };
	// int i{ 0x44 };
	// Testing how cout behaves with a char* when it has 100 random values after it
	// for cout to print, since in linux the program has no access to adjacent memory
	int array[100]{};

	for (int index{ 0 }; index < 100; ++index) {
		array[index] = std::rand();
	}
	// char *charPtr{ &c };
	std::cout << "Printing &c: " << &c << '\n';
	// std::cout << "Printing &i: " << &i << '\n';
	// Just doing this so the compiler doesn't complain
	std::cout << array << '\n';
	// std::cout << "Printing charPtr, which has &c as a value: " << charPtr << '\n';

	return 0;
}
