// Average class, no pun intended 🤭
#include <iostream>
#include <cstdint>

class Average {
private:
	std::int_least32_t m_sum{};
	std::int_least8_t m_numberCount{};
public:
	Average(std::int_least32_t sum = 0, std::int_least8_t numberCount = 0) : m_sum{sum}, m_numberCount{numberCount} {}

	friend std::ostream& operator<<(std::ostream& out, const Average& average);

	Average& operator+=(const int number) {
		m_sum += number;
		++m_numberCount;

		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const Average& average) {
	out << static_cast<double>(average.m_sum) / average.m_numberCount;
	return out;
}

int main() {
	Average avg{};

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10;
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
