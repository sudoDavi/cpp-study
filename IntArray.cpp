#include <iostream>
#include <cstddef>
#include <cassert>

class IntArray {
private:
	int *m_data{};
	std::size_t m_size{};
public:	
	IntArray(std::size_t size) : m_size{size} {
		m_data = new int[size];
	}

	IntArray(const IntArray& intArray) : m_size{ intArray.m_size } {
		m_data = new int[m_size];

		for (std::size_t index{}; index < m_size; ++index)
			m_data[index] = intArray[index];
	}

	int operator[](std::size_t index) const {
		assert(index < m_size && "Index out of bounds");
		return m_data[index];
	}
	int& operator[](std::size_t index) {
		assert(index < m_size && "Index out of bounds");
		return m_data[index];
	}
	int operator[](int index) const {
		assert(index >= 0 && static_cast<std::size_t>(index) < m_size && "Index out of bounds");
		return m_data[static_cast<std::size_t>(index)];
	}
	int& operator[](int index) {
		assert(index >= 0 && static_cast<std::size_t>(index) < m_size && "Index out of bounds");
		return m_data[static_cast<std::size_t>(index)];
	}

	IntArray& operator=(const IntArray& intArray) {
		assert(intArray.m_data);

		if (this == &intArray)
			return *this;

		// If the array isn't empty, free the allocated memory
		if (m_data)
			delete[] m_data;
		m_size = intArray.m_size;
		// Goofed up here and forgot to assign a new array
		m_data = new int[m_size];

		for (std::size_t index{}; index < m_size; ++index)
			m_data[index] = intArray[index]; 

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array);

	~IntArray() {
		delete[] m_data;
	}
};

std::ostream& operator<<(std::ostream& out, const IntArray& array) {
	for (std::size_t index{}; index < array.m_size; ++index)
		out << array[index] << ' ';
	return out;
}

IntArray fillArray() {
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a };
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}
