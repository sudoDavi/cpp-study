#include <iostream>
#include <string>
#include <algorithm>

class MyString {
private:
	std::string m_data{};
public:
	MyString(const std::string& string) : m_data{string} {}

	std::string operator()(std::string::size_type index, std::string::size_type lenght) const;
};

std::string MyString::operator()(std::string::size_type index, std::string::size_type lenght) const {
	return m_data.substr(index, lenght);
}

int main() {
	MyString string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n';

	return 0;
}
