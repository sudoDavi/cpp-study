#include <iostream>

class Point {
private:
	double m_x{};
	double m_y{};
	double m_z{};
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{x}, m_y{y}, m_z{z} {}

	// Returns equivalent negative Point
	Point operator-() const;
	// Returns equivalent poisitive Point
	Point operator+() const;
	// Returns true if point is at the origin
	bool operator!() const;
	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
	return out;
}

Point Point::operator-() const {
	return Point(-m_x, -m_y, -m_z);
}

Point Point::operator+() const {
	return Point(+m_x, +m_y, +m_z);
}

bool Point::operator!() const {
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main() {
	Point np{ -5.0, 0.0, 1.0 };
	// Test the positive operator
	std::cout << +np << '\n';
	// Test the negative operator
	std::cout << -np << '\n';

	return 0;
}


