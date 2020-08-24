#include <iostream>

double getValue() {
	std::cout << "Enter a double value: ";
	double input{};
	std::cin >> input;
	return input;
}

char getOp() {
	std::cout << "Enter one of the following: +, - , *, or /: ";
	char input{};
	std::cin >> input;
	return input;
}

int main() {
	const double first{ getValue() };
	const double second{ getValue() };
	const char operation{ getOp() };

	// Can use a switch case here, but I don't want to, because I haven't seen that part yet
	if ( operation == '+')
		std::cout << first << " + " << second << " is " << first + second;
	else if (operation == '-')
		std::cout << first << " - " << second << " is " << first - second;
	else if (operation == '*')
		std::cout << first << " * " << second << " is " << first * second;
	else if (operation == '/')
		std::cout << first << " / " << second << " is " << first / second;
	else
		return 1;

	std::cout << '\n';

	return 0;
}
