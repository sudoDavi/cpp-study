#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct StudentGrade {
	std::string name{};
	char grade{};
};

class GradeMap {
private:
	std::vector<StudentGrade> m_map{};
public:
	char& operator[](const std::string& index);
};

// Returns a reference to the grade of the student which has a name equal to index
// if no one is found, a new student is added to the vector with the same name
// and then a reference to that's student grade is returned
char& GradeMap::operator[](const std::string& index) {
	auto found{ std::find_if(m_map.begin(), m_map.end(),
		[index](const auto& grade) { return grade.name == index; }) };

	if (found != m_map.end())
		return found->grade;

	m_map.push_back({index});

	return m_map.back().grade;
}

int main() {
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
