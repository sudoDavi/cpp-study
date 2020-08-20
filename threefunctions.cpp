#include "io.h"

int main() {
	int first{ readNumber() };
	int second{ readNumber() };
	writeAnswer(first + second);
	return 0;
}
