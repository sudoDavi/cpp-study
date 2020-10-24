#include <iostream>
#include <iterator>

int* find(int *begin, int *end, int value) {
	// Iterate over the array searching for value
	// if it finds any instance of it, return it immediatly
	for (int *indexPtr{ begin }; indexPtr < end; ++indexPtr)
		if (*indexPtr == value)
			return indexPtr;
	// Just so compiler doesn't complain of no return value
	return end;
}

int main() {
	int arr[]{ 2, 5, 4, 10, 8, 20, 16, 20, 40 };

	// Search for the first element with a value of 20
	// Deliberatly using two different synthaxes just to show it is possible
	int *found{ find(arr, arr + std::size(arr), 20) };

	if (found != std::end(arr))
		std::cout << "Value " << *found << " found at index: " << static_cast<int>(found - arr) << '\n';

	return 0;
}
