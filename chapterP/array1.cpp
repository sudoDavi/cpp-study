#include <iostream>
namespace Indexes {
	enum Animals {
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		TOTAL_SIZE,
	};
}

int main() {
	// Comented out to avoid compiler error.
	// double temps[365]{ };

	int numberOfLegs[Indexes::Animals::TOTAL_SIZE]{ 2, 4, 4, 4, 2, 0};

	std::cout << "An elephant has " << numberOfLegs[Indexes::Animals::ELEPHANT] << " legs.\n";

	return 0;
}
