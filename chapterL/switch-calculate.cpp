#include <iostream>

int calculate(int a, int b, char op) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '%':
			return a % b;
		default:
			std::cout << "Invalid operator\n";
			return 0;
	}
}

int main() {
	std::cout << "Enter variable x: ";
	int x{};
	std::cin >> x;
	
	std::cout << "Enter the operation: ";
	char operation{};
	std::cin >> operation;
	
	std::cout << "Enter variable y: ";
	int y{};
	std::cin >> y;

	int result{calculate(x, y, operation)};
	std::cout << "The result is: " << result << '\n';

	return 0;
}
