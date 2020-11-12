#include <algorithm> // for std::sort
#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota

namespace Config {
	constexpr int arraySize = 10000;
}

class Timer {
private:
	// using type aliases for convenience
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> m_clock;

public:
	Timer() : m_clock(clock_t::now()) {}

	void reset() {
		m_clock = clock_t::now();
	}

	// Returns the elapsed time since the clock started until the function call in seconds
	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_clock).count();
	}
};

int main() {
	std::array<int, Config::arraySize> array;
	// Fill the array with arraySize to 1
	std::iota(array.rbegin(), array.rend(), 1);

	Timer t;

	// Sort the array in ascending
	std::sort(array.begin(), array.end());

	std::cout << "Time taken to sort: " << t.elapsed() << " seconds\n";

	return 0;
}
