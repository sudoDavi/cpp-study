#include <iostream>

void swap(int& a, int&b ) {
	int placeholder{ a };
	a = b;
	b = placeholder;
}

int main() {
	int first{ 20 };
	int second{ 560 };

	std::cout << "First has value: " << first << '\n';
	std::cout << "Second has value: " << second << '\n';
	std::cout << "Calling swap\n";
	swap(first, second);
	std::cout << "After swap\n";
	std::cout << "First has value: " << first << '\n';
	std::cout << "Second has value: " << second << '\n';

	return 0;	
}
