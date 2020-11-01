#include <iostream>

int factorial(int N) {
	// Some base cases
	if (N == 1 || N == 0)
		return 1;

	return factorial(N - 1) * N;
}

int main() {
	// Print the seven first factorials
	for (int i{ 0 }; i < 7; ++i) {
		std::cout << factorial(i) << '\n';
	}

	return 0;
}
