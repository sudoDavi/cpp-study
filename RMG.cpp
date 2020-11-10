// RMG - Random Monster Generator
#include <string>
#include <string_view>
#include <array>
#include <iostream>
#include <cstddef> // for std::size_t
#include <ctime> // for std::time()
#include <cstdlib> // for std::rand() and srand()

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

// Assumes srand() has already been called
// Gets a random number from min inclusive up to max inclusive
int getRandomNumber(int min, int max) {
	static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) }; // Is static so we only calculate this value once
	return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

class MonsterGenerator {
public:
	static Monster generateMonster() {
		static constexpr std::array s_names{ "Mortimer", "Guli", "Uptyr", "Bones", "Priot", "Vladimir" };
		static constexpr std::array s_roars{ "*peep*", "*gulp*", "*rattles*", "*pop*", "*quiqui*", "*squeak*" };

		return Monster{ 
			static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::MAX_MONSTER_TYPES) - 1)),
			s_names[static_cast<std::size_t>(getRandomNumber(0 , 5))],
			s_roars[static_cast<std::size_t>(getRandomNumber(0 , 5))],
			getRandomNumber(1, 100)
		};
	}
};

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the RNG with time
	std::rand(); // For compatibility with VSC we're discarding the first number generated

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
