#include <iostream>
#include <array>
#include <cassert>

class Stack {
using member_type = int;
static constexpr int stackSize{ 10 };
using stack_type = std::array<member_type, stackSize>;
using size_type = stack_type::size_type;

private:
 	stack_type m_stack{};
	size_type m_size{ 0 };
public:
	void reset() {
		m_size = 0;
	}

	void print() {
		std::cout << "( ";
		
		for (size_type index{ 0 }; index < m_size; ++index)
			std::cout << m_stack[index] << ' ';

		std::cout << ")\n";
	}

	bool push(int value) {
		// To prevent stack overflow we exit if the new m_size is bigger than the stack size
		if (m_size == m_stack.size()) {
			return false;
		}

		// The index of our value is at m_size - 1, since the size of the stack is always
		// bigger by one than the stack index
		m_stack[m_size++] = value;

		return true;
	}

	member_type pop() {
		assert(m_size > 0 && "Trying to pop a empty stack");
		// m_size is always +1 from the current last index of the stack
		// so we can use a postfix decrement operator here to return the value
		// we just popped and then decrement the size
		return 	m_stack[m_size--];
	}
};

int main() {
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
