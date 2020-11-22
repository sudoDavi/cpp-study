#include <iostream>
#include <cstdint>

class FixedPoint2 {
private:
	std::int16_t m_nonDecimal{};
	std::int8_t m_decimal{};
public:
	FixedPoint2(std::int16_t nonDecimal = 0, std::int8_t decimal = 0) : m_nonDecimal{nonDecimal}, m_decimal{decimal} {
		// If any of the parts of the number are negative, make every part be negative
		if (m_nonDecimal < 0 || m_decimal < 0) {
			if (m_nonDecimal > 0)
				m_nonDecimal = -m_nonDecimal;
			if (m_decimal > 0) 
				m_decimal = -m_decimal;
		}
	}

	operator double() const { return static_cast<double>(m_nonDecimal) + (m_decimal / 100.0); }	
	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& number);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& number) {
	out << static_cast<double>(number);
	return out;
}

int main() {
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	return 0;
}
