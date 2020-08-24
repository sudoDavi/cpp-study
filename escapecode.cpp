#include <iostream>
#include <limits>

// Waits until the user presses ENTER to get out of the function
// it is the commonly used system("pause"), but it works on any OS
// it also does a new line, since it is waiting for ENTER
void waitInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

int main() {
	std::cout << "This is alert: \a";
	waitInput();
	
	std::cout << "This is backspace:";
	waitInput();
	std::cout << "\b\bca";
	waitInput();

	std::cout << "Formfeed:";
	waitInput();
	std::cout << "This is before formfeed \f This is after";
	waitInput();

	waitInput();
	std::cout << "Carriage return:";
	waitInput();
	std::cout << "I printed this";
	waitInput();
	std::cout << "\b\b\r It returned and printed this";
	waitInput();

	waitInput();
	std::cout << "\vThis text is Vertically tabbed\n";
	std::cout << "\tThis text is Horizontally tabbed\n";
	std::cout << "\v\tThis text is both";
	waitInput();

	waitInput();
	std::cout << "Testing if I can return to a line after a new line char";
	waitInput();
	std::cout << "\b\b\b\b\rI backspaced two times and wrote this text";
	waitInput();
	std::cout << "The remaining characters: \' \" \\ \?(deprecated: \\?)";
	waitInput();

	std::cout << "Printing chars from numbers:\nHere I\'m using \\number, which will convert a char from octal:\n";
	std::cout << "A is 101 in octal: \101\n";
	std::cout << "And here I\'m using \\x to convert a char from hex:\n";
	std::cout << "A is 41 in hex: \x41\n\n";
	std::cout << "Thank you for using this test";
	waitInput();

	return 0;
}
