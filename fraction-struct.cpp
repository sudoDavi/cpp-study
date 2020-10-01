#include <iostream>

struct Fraction {
	int numerator;
	int denominator;
};

double multiplyResolve(Fraction f1, Fraction f2) {
	return static_cast<double>(f1.numerator * f2.numerator) / static_cast<double>(f1.denominator * f2.denominator);
}

int main() {
	Fraction a;
	std::cout << "Enter the numerator: ";
	std::cin >> a.numerator;
	std::cout << "Enter the denominator: ";
	std::cin >> a.denominator;

	Fraction b;
	std::cout << "Enter the numerator: ";
	std::cin >> b.numerator;
	std::cout << "Enter the denominator: ";
	std::cin >> b.denominator;

	std::cout << "Both fractions multiplied = " << multiplyResolve(a, b) << '\n';

	return 0;
}
