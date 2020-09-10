#include <iostream>

int printDecrementOne(int x, int pow){
	std::cout << '1';
	return (x - pow);
}

int printDecrementBit(int x, int pow){
	if (x >= pow)
		return printDecrementOne(x, pow);

	std::cout << '0';
	return x;
}

int main(){
	std::cout << "Enter a number between 0 and 255: ";
	int input{};
	std::cin >> input;

	input = printDecrementBit(input, 128);
	input = printDecrementBit(input, 64);
	input = printDecrementBit(input, 32);
	input = printDecrementBit(input, 16);

	std::cout << "'";

	input = printDecrementBit(input, 8);
	input = printDecrementBit(input, 4);
	input = printDecrementBit(input, 2);
	input = printDecrementBit(input, 1);

	std::cout << '\n';

	return 0;
}
