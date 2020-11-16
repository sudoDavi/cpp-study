#include <iostream>

class Fraction {
private:
	int m_numerator{};
	int m_denominator{};
public:
	Fraction(int numerator = 0, int denomitator = 1) : m_numerator{numerator}, m_denominator{denomitator} {
		reduce();
	}
	void print() {
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	// a is numerator b is denominator
	int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}

	void reduce() {
		if (m_numerator != 0 && m_denominator != 0) {
			int gcd{ Fraction::gcd(m_numerator, m_denominator) };
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const int right);
	friend Fraction operator*(const int left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const Fraction& right);
	friend Fraction operator/(const int left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const int right);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
	out << fraction.m_numerator << '/' << fraction.m_denominator;

	return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
	in >> fraction.m_numerator;

	// Ignore the /, so the user can input something like 1/2
	in.ignore(32767, '/');

	in >> fraction.m_denominator;

	fraction.reduce();

	return in;
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	return Fraction{ left.m_numerator * right.m_denominator, left.m_denominator * right.m_numerator };
}

Fraction operator/(const int left, const Fraction& right) {
	return Fraction{ right.m_numerator * 1, right.m_denominator * left };
}

Fraction operator/(const Fraction& left, const int right) {
	return Fraction{ left.m_numerator * 1, left.m_denominator * right };
}

Fraction operator*(const Fraction& left, const Fraction& right) {
	return Fraction{ left.m_numerator * right.m_numerator, left.m_denominator * right.m_denominator };
}

Fraction operator*(const Fraction& left, const int right) {
	return Fraction{ left.m_numerator * right, left.m_denominator };
}

Fraction operator*(const int left, const Fraction& right) {
	return Fraction{ right.m_numerator * left, right.m_denominator };
}

int main() {
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " / " << f2 << " is " << f1 / f2 << '\n';

	return 0;
}
