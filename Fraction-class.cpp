#include <iostream>

class Fraction {
private:
	int m_numerator{};
	int m_denominator{};
public:
	Fraction(int numerator = 0, int denomitator = 1) : m_numerator{numerator}, m_denominator{denomitator} {}
	void print() {
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const int right);
	friend Fraction operator*(const int left, const Fraction& right);
};

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
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5 { 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();

	return 0;
}
