
#include <iostream>
#include <string>

int main(){
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin, name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;
	std::cin.ignore(32767, '\n');

	double agePerLetter{ static_cast<float>(age) / name.length() };
	std::cout << "You've lived " << agePerLetter << " years for each letter in your name.\n";

	return 0;
}
