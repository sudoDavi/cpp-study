#include <iostream>
#include <string_view>
#include <string>

int main() {
	constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string findName;
	std::getline(std::cin, findName);

	// for each loop example
	for (auto name : names) {
		if (name == findName) {
			std::cout << findName << " was found.\n";
			return 0;
		}
	}

	std::cout << findName << " was not found.\n";

	return 0;
}
