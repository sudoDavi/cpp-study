#include <iostream>
#include <ctime>
#include <random>

namespace Random {
	// Initialize mersenne twister based on clock
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::uint_fast32_t Get(std::uint_fast32_t min = mersenne.min(), std::uint_fast32_t max = mersenne.max()) {
		std::uniform_int_distribution<std::uint_fast32_t> die{ min, max }; // Create a distribution in any function that needs it
		return die(mersenne);
	}
}

int main() {
	auto random{ Random::Get(0, 500)};
	int counter{ 1 };
	while (random) {
		std::cout << random << ' ';
		random = Random::Get(0, 500);

		if (counter == 10)
			std::cout << '\n';

		++counter;
	}

	std::cout << '\n';
	
	return 0;
}
