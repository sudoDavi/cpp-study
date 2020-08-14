#include <iostream>

int add (int a, int b); // Foward declaration of function declared in add.cpp

int main() {
	std::cout << "The sum of 3 and 5 is : " << add(3, 5) << '\n';
	return 0;
}
