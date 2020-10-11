#include <iostream>



int main() {
/* NAIVE WAY
	char ch{'A'};
	int chCount{0};

	while (chCount < 26) {
		std::cout << static_cast<char>(ch + chCount) << " is " << std::hex << static_cast<int>(ch + chCount) << ' ';
		++chCount;
		if (chCount % 4 == 0)
			std::cout << '\n';
	}
	std::cout << '\n';

	return 0;
*/
	char ch{ 'a' };

	while (ch <= 'z') {
		std::cout << ch << " is " << std::hex << static_cast<int>(ch) << "H ";
		if (ch % 4 == 0)
			std::cout << '\n';

		++ch;
	}
	std::cout << '\n';

	return 0;
}
