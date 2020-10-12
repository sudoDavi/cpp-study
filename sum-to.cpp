#include <iostream>

int sumTo(int value) {
	int total{};
	for (int i{ 1 }; i <= value; ++i)
		total += i;

	return total;
}

int main() {
	std::cout << "Input the value to sum up to: ";
	int input{};
	std::cin >> input;
	std::cout << "The total summed up to: " << sumTo(input) << '\n';

	return 0;
}
