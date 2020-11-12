#include <iostream>
#include <cstdint>

class RGBA {
using color_type = std::uint_fast8_t;
	color_type m_red{ 0 };
	color_type m_green{ 0 };
	color_type m_blue{ 0 };
	color_type m_alpha{ 255 };

public:
	RGBA(color_type red = 0, color_type green = 0, color_type blue = 0, color_type alpha = 255)
		: m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha } {}

	void print() {
		std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green)
			<< " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << '\n';
	}
};

int main() {
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}
