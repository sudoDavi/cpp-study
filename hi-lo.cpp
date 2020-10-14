#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

namespace Random {
	// Initialize mersenne twister based on clock
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	int Get(int min, int max) {
		std::uniform_int_distribution<> die{ min, max }; // Create a distribution in any function that needs it
		return die(mersenne);
	}
}

bool checkCinFail() {
		if (std::cin.fail()) { // has failed to get the value?
			// yes, so fix it
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Sorry, that input was invalid, try again!\n";

			return true;
		}
		else {
			// Remove characters that shouldn't be there
			std::cin.ignore(32767, '\n');

			return false;
		}
}

int getUserGuess(int atemptNum) {
	int guess{};
	bool repeat{ false };
	do {
		std::cout << "Guess #" << atemptNum << ": ";
		std::cin >> guess;

		repeat = checkCinFail();
		
	} while (repeat);

	return guess;
}

bool getPlayAgain() {
	char answer{};
	bool repeat{ false };
	do {
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> answer;

		repeat = checkCinFail();
		if (repeat) // Skip char validation, because the input wasn't a char
			continue;

		if (answer == 'y' || answer == 'Y')
			return true;
		else if (answer == 'n' || answer == 'N')
			return false;
		else
			repeat = true; // If input wasn't y or n, repeat the question
	}while (repeat);

	return false; // Just so the compiler doesn't complain
}

int main() {
	bool playAgain{ false };
	do {
		int randomNumber = Random::Get(1, 100);
		int guess{};
		int	tryNumber{ 1 };

		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		
		do {
			guess = getUserGuess(tryNumber);
			if (guess > randomNumber)
				std::cout << "Your guess is too high.\n";
			else if (guess < randomNumber)
				std::cout << "Your guess is too low.\n";
			else { // Guessed correctly
				std::cout << "Correct! You Win!\n";
				break;
			}

			++tryNumber;
			if (tryNumber > 7) {
				std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
				break;
			}
		}while (true);
		playAgain = getPlayAgain();
	}while (playAgain);

	std::cout << "Thank you for playing.\n";
	return 0;
}

