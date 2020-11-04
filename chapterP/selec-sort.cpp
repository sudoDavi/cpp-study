#include <iostream>
#include <utility>
#include <iterator>

void printArray(const int array[], int arrayLenght) {
	for (int i{ 0 }; i < arrayLenght; ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';
}
int main() {
	int array[]{ 10, 40, 70, 30, 50 };
	constexpr int lenght{ static_cast<int>(std::size(array)) };

	printArray(array, lenght);

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex{ 0 }; startIndex < lenght; ++startIndex) {
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex{ startIndex };

		// Then look for a smaller/bigger element in the rest of the array
		for (int currentIndex{ startIndex + 1 }; currentIndex < lenght; ++currentIndex) {
			// If we found it then remember its position
			if (array[currentIndex] > array[smallestIndex])
				smallestIndex = currentIndex;
		}
		// Then swap
		std::swap(array[startIndex], array[smallestIndex]);
	}

	printArray(array, lenght);

	return 0;
}
