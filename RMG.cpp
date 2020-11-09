// RMG - Random Monster Generator
#include <string>

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
};

int main() {
	Monster skeleton{ Monster::Type::SKELETON, "Bones", "*rattle*", 4 };

	return 0;
}
