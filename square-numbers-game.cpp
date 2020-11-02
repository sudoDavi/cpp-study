#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <vector>
#include <algorithm> // for std::find

namespace Random {
	// Initialize mersenne twister based on clock
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	int Get(int min, int max) {
		std::uniform_int_distribution<> die{ min, max }; // Create a distribution in any function that needs it
		return die(mersenne);
	}
}

void guessNumbers(std::vector<int>& list) {
	while (true) {
		int number{};
		std::cin >> number;

		auto foundNumber{ std::find(list.begin(), list.end(), number) };
	
		if (foundNumber != list.end()) {
			list.erase(foundNumber);
			if (list.empty()) {
				std::cout << "Nice! You found all numbers, good job!\n";
				break;
			}
			std::cout << "Nice! " << list.size() << " number(s) left.\n";
		}
		else {
			std::cout << number << " is wrong! Try " << list.front() << " next time.\n";
			break;
		}
	}
}

int main() {
	std::cout << "Start where? ";
	int startSqrt{};
	std::cin >> startSqrt;

	std::cout << "How many? ";
	int howMany{};
	std::cin >> howMany;
	
	int randomMult{ Random::Get(2, 4) };

	auto generateList { [randomMult](int start, int count) -> std::vector<int> {
		std::vector<int> list;

		for (int number{ start }; number < start + count; ++number) {
			int squareNumber{ number * number };
			list.push_back(squareNumber * randomMult);
		}
		return list;
	} };

	std::vector<int> list{ generateList(startSqrt, howMany) };

	std::cout << "I generated " << list.size() << " square numbers. ";
	std::cout << "Do you know what each number is after multiplying it by " << randomMult << "?\n";
	guessNumbers(list);

	return 0;
}
