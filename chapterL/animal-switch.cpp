#include <iostream>
#include <string>

enum class Animal {
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH,	
};

std::string getAnimalName(Animal animal) {
	switch (animal) {
		case Animal::PIG:
			return "Pig";
		case Animal::CHICKEN:
			return "Chicken";
		case Animal::GOAT:
			return "Goat";
		case Animal::CAT:
			return "Cat";
		case Animal::DOG:
			return "Dog";
		case Animal::OSTRICH:
			return "Ostrich";
		default:
			return "Not an Animal";
	}
}

void printNumberOfLegs(Animal animal) {
	std::cout << "A " << getAnimalName(animal) << " has ";
	switch (animal) {
		case Animal::PIG:
			std::cout << '4';
			break;
		case Animal::CHICKEN:
			std::cout << '2';
			break;
		case Animal::GOAT:
			std::cout << '4';
			break;
		case Animal::CAT:
			std::cout << '4';
			break;
		case Animal::DOG:
			std::cout << '4';
			break;
		case Animal::OSTRICH:
			std::cout << '0';
			break;
		default:
			std::cout << "Not an animal";
			break;
	}

	std::cout << " legs\n";
}

int main() {
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);

	return 0;
}
