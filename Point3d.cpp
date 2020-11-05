#include <iostream>
#include <string>

class Point3d {
private:
	int m_x{};
	int m_y{};
	int m_z{};
public:
	void setValues(int x, int y, int z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print() {
		std::string printable{ '<' + std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_z) + '>'};
		std::cout << printable << '\n';
	}

	// bool isEqual(const Point3d& otherP) {
		// return (m_x == otherP.m_x && m_y == otherP.m_y && m_z == otherP.m_z);
	// }
};

int main() {
	Point3d point;
	point.setValues(1, 2, 3);

	point.print();
	std::cout << '\n';

	return 0;
}
