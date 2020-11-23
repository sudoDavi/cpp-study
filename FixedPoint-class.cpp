#include <iostream>
#include <cstdint>
#include <cmath>

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

	FixedPoint2(double number) :
		m_nonDecimal{ static_cast<std::int16_t>(number) },
		m_decimal{ static_cast<std::int8_t>(std::round((number - static_cast<std::int16_t>(number)) * 100)) }
	{
	}

	operator double() const { return m_nonDecimal + static_cast<double>(m_decimal) / 100; }	
	
	friend bool operator==(const FixedPoint2& first, const FixedPoint2& second) {
		return (first.m_nonDecimal == second.m_nonDecimal && first.m_decimal == second.m_decimal);
	}
	FixedPoint2 operator-() const {
		return FixedPoint2( -m_nonDecimal, -m_decimal);
	}
	
};

FixedPoint2 operator+(const FixedPoint2& first, const FixedPoint2& second) {
	return FixedPoint2(static_cast<double>(first) + static_cast<double>(second));
}

std::istream& operator>>(std::istream& in, FixedPoint2& number) {
	double input{};
	in >> input;
	number = FixedPoint2( input );

	return in;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& number) {
	out << static_cast<double>(number);
	return out;
}

void testAddition() {
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main() {
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number : ";
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}
