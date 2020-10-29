#include <iostream>

int readNumber() {
	int input{};
	std::cout << "Please enter a number:";
	std::cin >> input;
	return input;
}

void writeAnswer(int ans) {
	std::cout << "The sum is: " << ans << '\n';
}

int main() {
	int x{readNumber()};
	x = x + readNumber();
	writeAnswer(x);

	return 0;
}
