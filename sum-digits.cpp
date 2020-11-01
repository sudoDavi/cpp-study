#include <iostream>

int sumDigits(int number) {
	// Base case to terminate the recursion
	if (number <= 0)
		return 0;

	return (sumDigits(number / 10)) + number % 10;
}

int main() {
	std::cout << "Sum of the digits of 93427: " << sumDigits(93427) << '\n';
	return 0;
}
