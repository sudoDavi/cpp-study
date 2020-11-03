#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <vector>
#include <algorithm> // for std::find
#include <cmath> // for std::abs

namespace Random {
	// Initialize mersenne twister based on clock
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	int Get(int min, int max) {
		std::uniform_int_distribution<> die{ min, max }; // Create a distribution in any function that needs it
		return die(mersenne);
	}
}

namespace Config {
	constexpr int RandomMin{ 2 };
	constexpr int RandomMax{ 4 };
}

using list_type = std::vector<int>;

list_type generateNumbers(int multiplier) {
	std::cout << "Start where? ";
	int start{};
	std::cin >> start;

	std::cout << "How many? ";
	int howMany{};
	std::cin >> howMany;

	list_type numbers;
	// Fill the list with numbers which follow the formula number^2 * multiplier
	// The list is as long as howMany, we just offset it by start
	for (int number{ start }; number < start + howMany; ++number) {
		numbers.push_back((number * number) * multiplier);
	}

	return numbers;
}

void playGame(list_type& numbers, int multiplier) {
	std::cout << "I generated " << numbers.size() << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";
	// While not loosing or winning get the guessed number from the user
	while (true) {
		int guessed{};
		std::cin >> guessed;

		// Search the guessed number in the numbers array
		auto searched{ std::find(numbers.begin(), numbers.end(), guessed) };

		// std::find returns the .end() of the array if it didn't find the searched parameter
		if (searched != numbers.end()) { // If it enters here it means we guessed the number correctly
			// Remove the guessed number from the array
			numbers.erase(searched);

			// If after the erase(), numbers is empty, we've found all numbers and can stop the program
			if (numbers.empty()) {
				std::cout << "Nice! You found all numbers, good job!\n";
				break;
			}
			else { // If not, we still have numbers to guess
				std::cout << "Nice! " << numbers.size() << " number(s) left.\n";
			}
		}
		else { // We guessed the wrong number
			// Find the closest number in the array to the guessed one
			auto closest{ std::min_element(
				numbers.begin(),
				numbers.end(),
				// Lambda declaration to find the closest number
				[guessed](const auto& a, const auto& b) {
					return std::abs(a - guessed) < std::abs(b - guessed);
				})
			};

			// Break the loop because we lost the game
			std::cout << guessed << " is wrong! Try " << *closest << " next time.\n";
			break;
		}
	}
}

int main() {
	int randomMult{ Random::Get(Config::RandomMin, Config::RandomMax) };
	// Generate the numbers using the random integer
	list_type numbers{ generateNumbers(randomMult) };
	// Play the game with the generated numbers and the random number
	playGame(numbers, randomMult);

	return 0;
}
