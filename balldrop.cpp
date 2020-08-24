#include "balldrop-constants.h"

#include <iostream>

void printHeight(int time, const double initial_height) {
	const double height{initial_height - (gravity * ((time*time)/2.0))};

	if (height <= 0 ) {
		std::cout << "At " << time << " seconds, the ball is on the ground\n" ;
		return;
	}

	std::cout << "At " << time << " seconds, the ball is at height: " << height << " meters\n";
}

int main() {
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;
	printHeight(0, height);
	printHeight(1, height);
	printHeight(2, height);
	printHeight(3, height);
	printHeight(4, height);
	printHeight(5, height);

	std::cout << '\n';

	return 0;
}
