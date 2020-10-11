#include <iostream>

int main() {
	char asciiChar{ 0x21 };

	while (asciiChar >= 0) {
		std::cout << asciiChar << " is " << std::hex << static_cast<int>(asciiChar) << "H ";
		if (asciiChar % 4 == 0)
			std::cout << '\n';

		++asciiChar;
	}
	std::cout << '\n';

	return 0;
}
