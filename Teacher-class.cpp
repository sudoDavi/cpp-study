#include <iostream>
#include <functional> // for std::reference_wrapper
#include <string>
#include <vector>

class Teacher {
private:
	std::string m_name{};
public:
	Teacher(const std::string& name) : m_name{name} {}

	const std::string& getName() const { return m_name; }
};

class Department {
public:
	using vector_type = std::vector<std::reference_wrapper<const Teacher>>;
private:
	 vector_type m_teachers{};
public:
	vector_type& add(const Teacher& teacher) {
		m_teachers.push_back(teacher);
		return m_teachers;
	}

	friend std::ostream& operator<<(std::ostream& out, const Department& department) {
		out << "Department: ";
		for (const auto teacherRef : department.m_teachers)
			out << teacherRef.get().getName() << ' ';
		out << std::endl;

		return out;
	}
};

int main() {
	Teacher t1{ "Bob" };
	Teacher t2{ "Frank" };
	Teacher t3{ "Beth" };

	{
		Department department{};

		department.add(t1);
		department.add(t2);
		department.add(t3);

		std::cout << department;
	} // department goes out of scope here and is destroyed

	std::cout << t1.getName() << " still exists!\n";
	std::cout << t2.getName() << " still exists!\n";
	std::cout << t3.getName() << " still exists!\n";

	return 0;
}
