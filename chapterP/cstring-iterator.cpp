#include <iostream>

void printCString(const char* start) {
	while (*start != '\0') {
		std::cout << *start;
		++start;
	}
}

int main() {
	printCString("Hello, world!\n");
	return 0;
}
