#include <array>
#include <iostream>
#include <algorithm>
#include <string>

struct Student {
	std::string name{};
	int points{};
};

int main() {
	const std::array<Student, 8> students{
	{	{ "Albert", 3 },
		{ "Ben", 5 },
		{ "Christine", 2 },
		{ "Dan", 8 },
		{ "Enchilada", 4 },
		{ "Francis", 1 },
		{ "Greg", 3 },
		{ "Hagrid", 5 }	}
	};

	// Returns true if the first student has a lower point count than the second
	auto greaterStudent{ [](const Student& first, const Student& second) {
		return first.points < second.points;
	} };

	// max_element() returns an iterator to the largest element in the array
	// So we access it using the defered access operator
	std::cout << (std::max_element(students.begin(), students.end(), greaterStudent))->name << " is the best student\n";

	return 0;
}
