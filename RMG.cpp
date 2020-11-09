// RMG - Random Monster Generator
#include <string>

enum class MonsterType {
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

class Monster {
private:
	MonsterType m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hp{};
public:
	Monster(
		MonsterType type = MonsterType::ZOMBIE, const std::string& name = "Zombie", const std::string& roar = "EEEEEEERR", int hp = 10
	) : m_type{type}, m_name{name}, m_roar{roar}, m_hp{hp} {}
};
