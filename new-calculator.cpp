#include <iostream>
#include <functional>

int getInteger() {
	while (true) {
		std::cout << "Enter an integer: ";
		int returnInt{};
		std::cin >> returnInt;

		if (!std::cin.fail())
			return returnInt;

		// If the function gets to this point
		// it means the user has done something wrong
		// so we fix it
		std::cout << "Invalid input\n";
		
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

bool validateOperation(char operation) {
	switch (operation) {
		case '+':
		case '-':
		case '/':
		case '*':
			return true;
		default :
			return false;
	}
}

char getOperation() {
	while (true) {
		std::cout << "Enter the operation (+, -, / or *): ";
		char returnChar{};
		std::cin >> returnChar;

		if (!std::cin.fail() && validateOperation(returnChar))
			return returnChar;

		// If the function gets to this point
		// it means the user has done something wrong
		// so we fix it
		std::cout << "Invalid input\n";

		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

inline int add(int first, int second) {
	return (first + second);
}

inline int subtract(int first, int second) {
	return (first - second);
}

inline int divide(int first, int second) {
	return (first / second);
}

inline int multiply(int first, int second) {
	return (first * second);
}

using arithmeticFcn = std::function<int(int, int)>;

arithmeticFcn getArithmeticFunction(char operation) {
	switch (operation) {
		default: // Default operation will be add
		case '+':
			return add;
		case '-':
			return subtract;
		case '/':
			return divide;
		case '*':
			return multiply;
	}
}

int main() {
	int first{ getInteger() };
	int second{ getInteger() };
	char operation{ getOperation() };
	// Get a pointer to the correct function to calculate what the user wants
	arithmeticFcn calculate{ getArithmeticFunction(operation) };

	std::cout << "That equals: " << calculate(first, second) << '\n';

	return 0;
}
