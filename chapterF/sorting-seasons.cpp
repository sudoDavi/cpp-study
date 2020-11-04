#include <algorithm>
#include <iostream>
#include <string_view>
#include <array>

struct Season {
	std::string_view name{};
	double averageTemp{};
};

int main() {
	// Array of seasons for us to sort
	std::array<Season, 4> seasons{
		{ { "Spring", 285.0 },
		  { "Summer", 296.0 },
		  { "Fall", 288.0 },
		  { "Winter", 263.0 } }
	};

	// Lambda that returns true if the averageTemp of first is LESS THAN second's averageTemp
	auto lessSeasonalTemp{ [](const Season& first, const Season& second) {
		return first.averageTemp < second.averageTemp;
	} };

	// Sort the array in ascending order of temperature
	std::sort(seasons.begin(), seasons.end(), lessSeasonalTemp);

	// Print the array
	for (const auto& season : seasons)
		std::cout << season.name << '\n';

	return 0;
}
