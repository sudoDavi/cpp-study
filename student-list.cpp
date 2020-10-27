#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <functional> // for std::greater
#include <cstddef> // for std::size_t
#include <string>

struct Student {
	std::string firstName{};
	int grade{};
};

std::size_t getListLenght() {
	std::cout << "Enter how many students you'll enter: ";
	std::size_t count{};
	std::cin >> count;
	return count;
}

void getStudentFromUser(Student& student) {
	// Little hack to have the student number when asking the info
	static std::size_t studentCounter{ 1 };
	
	std::cout << "Please enter the student's " << studentCounter << " first name: ";
	std::cin >> student.firstName;
	bool repeat { false };
	do {
		std::cout << "Please enter the student's grade (0-100): ";
		std::cin >> student.grade;

		// User inputed invalid input
		// std::cin.fail() is checked last because of how the || works
		if (student.grade > 100 || student.grade < 0 || std::cin.fail()) {
			repeat = true;

			// Inform the user the input was invalid
			std::cout << "Invalid Input, please try again.\n";
			// Fix std::cin
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
			repeat = false;
	} while (repeat);

	++studentCounter;
}

void printStudent(const Student& student) {
	std::cout << student.firstName << " got a grade of " << student.grade << '\n';
}

bool greaterGrade(const Student& first, const Student& second) {
	return (first.grade > second.grade);
}

int main() {
	// Get the list lenght from the user
	std::size_t listLenght{ getListLenght() };
	// Create a std::vector of empty student structs
	std::vector<Student> studentList(listLenght);

	// Create helper variables so I can type less
	auto begin{ studentList.begin() };
	auto end{ studentList.end() };
	// Fill the student list with data from the user,
	// while checking that is is correct
	std::for_each(begin, end, getStudentFromUser);
	// Sort the list from highest grade to lowest
	std::sort(begin, end, greaterGrade);
	// Finally print out the list
	std::for_each(begin, end, printStudent);

	return 0;
}
