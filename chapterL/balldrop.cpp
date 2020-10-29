#include "balldrop-constants.h"

#include <iostream>
#include <cmath>

double calcInstantHeight(float &timePassed, const double initialHeight, bool &isOnGround) {
	double falledDistance{ Constants::Gravity * ((timePassed * timePassed)/ 2.0) };
	const double instantHeight{ initialHeight - falledDistance };

	if (instantHeight > 0.0)
		return instantHeight;
	else {
		float groundTime{ std::sqrt(static_cast<float>(initialHeight * 2.0) / static_cast<float>(Constants::Gravity)) };
		timePassed = groundTime;
		isOnGround = true;
		return 0.0;
	}
}

void printInstant(const double instantHeight, const float instantTime, const bool dropFinished) {
	if (!dropFinished || instantHeight > 0.0)
		std::cout << "The ball is at: " << instantHeight << " meters, with " << instantTime << " seconds passed.\n";
	else
		std::cout << "The ball is on the ground at " << instantTime << " seconds passed.\n";
}

double getTowerHeight() {
	while(true) {
		std::cout << "Enter the height of the tower in meters: ";
		double height{};
		std::cin >> height;

		if (std::cin.fail() || height < 0.0) { // has failed to get the value?
			// yes, so fix it
			std::cin.clear();
			std::cin.ignore(Constants::IgnoreSize, '\n');
			std::cout << "Sorry, that input was invalid, try again! ";
		}
		else {
			// Remove characters that shouldn't be there
			std::cin.ignore(Constants::IgnoreSize, '\n');

			return height;
		}
	}
}

int main() {
	// Naive algorith, that doesn't try to find the exact time
	/*
	std::cout << "Enter the height of the tower in meters: ";
	const double height{};
	std::cin >> height;

	int seconds{ 0 };
	double currHeight{ height };
	
	do {
		currHeight = calcInstantHeight(seconds, height);
		printInstant(currHeight, seconds);
		++seconds;
	}while (currHeight > 0.0);
	*/

	double initialHeight{ getTowerHeight() };

	// In seconds
	float time{ 0.0f };
	// Amount in seconds to wich calculate the fall with
	const float timeStep{ 0.1f };
	// Ball's instant height
	double instantHeight{};
	// Has the drop finished?
	bool finished{ false };
	
	do {
		instantHeight = calcInstantHeight(time, initialHeight, finished);
		printInstant(instantHeight, time, finished);
		time += timeStep;
	}while (!finished);

	std::cout << '\n';

	return 0;
}
