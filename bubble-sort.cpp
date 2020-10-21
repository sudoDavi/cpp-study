#include <iostream>
#include <iterator>
#include <utility>

void printArray(const int array[], const int arrayLenght) {
	for (int i = 0; i < arrayLenght; ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';
}

int main() {
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int lenght{ static_cast<int>(std::size(array)) };

	printArray(array, lenght);

	// Start with a for loop for the iterations in the array with a range of lenght - 1 because
	// we don't need to check the last element
	for (int iteration{ 0 }; iteration < lenght - 1 ; ++iteration) {
		bool didSwap{ false };
		// So on each iteration we check each position on the array to see it is bigger than its next neighboor
		// but we can also eliminate the end of the array, as that gets sorted on each iteration
		for (int currentIndex{ 0 }; currentIndex < lenght - iteration; ++currentIndex) {
			if (array[currentIndex] > array[currentIndex + 1]) {
				// If so we swap them
				std::swap(array[currentIndex], array[currentIndex + 1]);
				didSwap = true;
			}
		}
		// If we didn't swap anything in this iteration
		// it means the array is already sorted
		if (!didSwap) {
			// Add one to convert from 0 based to 1 based counting
			std::cout << "Finished early with " << iteration + 1 << " iterations\n";
			break;
		}
	}

	printArray(array, lenght);

	return 0;
}
