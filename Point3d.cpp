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

	bool isEqual(const Point3d& otherP) {
		return (m_x == otherP.m_x && m_y == otherP.m_y && m_z == otherP.m_z);
	}
};

int main() {
	Point3d point1;
	point1.setValues(1, 2, 3);

	Point3d point2;
	point2.setValues(1, 2, 3);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are different\n";

	Point3d point3;
	point3.setValues(4, 2, 0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are different\n";

	return 0;
}
