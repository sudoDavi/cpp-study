#include <iostream>

void doNothing(int&) {}

int main() {
	int x; // Defined an integer, but did not initialize it

	doNothing(x);

	std::cout << x << '\n'; // Throw random data at the terminal;

	return 0;
}
