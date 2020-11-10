// RMG - Random Monster Generator
#include <string>
#include <string_view>
#include <array>
#include <iostream>
#include <cstddef> // for std::size_t

class Monster {
// Nested types
public:
	enum class Type {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,

		MAX_MONSTER_TYPES
	};

// Member variables
private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hp{};

// Member functions
public:
	Monster(
		Type type = Type::ZOMBIE, const std::string& name = "Zombie", const std::string& roar = "EEEEEEERR", int hp = 10
	) : m_type{type}, m_name{name}, m_roar{roar}, m_hp{hp} {}

	std::string_view getTypeString() const {
		static constexpr std::array typeStrings{ "dragon", "goblin", "ogre", "orc", "skeleton", "troll", "vampire", "zombie" };
		return typeStrings[static_cast<std::size_t>(m_type)];
	}

	void print() const {
		std::cout << m_name << " the " << getTypeString() << " has " << m_hp << " hit points and says " << m_roar << '\n';
	}
};

class MonsterGenerator {
public:
	static Monster generateMonster() {
		return Monster{ Monster::Type::SKELETON, "Bones", "*rattle*", 4 };
	}
};

int main() {
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
