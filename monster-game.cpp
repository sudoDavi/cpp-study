#include <iostream>
#include <string>

enum class MonsterType{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct Monster {
	std::string name;
	MonsterType type;
	int health;
};

void printMonster(Monster monster) {
	std::string typeName;
	switch (monster.type) {
		case MonsterType::OGRE :
			typeName = "Ogre";
			break;
		case MonsterType::DRAGON :
			typeName = "Dragon";
			break;
		case MonsterType::ORC :
			typeName = "Orc";
			break;
		case MonsterType::GIANT_SPIDER :
			typeName = "Giant Spider";
			break;
		case MonsterType::SLIME :
			typeName = "Slime";
			break;
		default :
			typeName = "Unknown";
			break;
	};

	std::cout << "This " + typeName + " is named " + monster.name + " and has " + std::to_string(monster.health) + " health.\n";
}

int main() {
	Monster lilith{ "Lilith", MonsterType::SLIME, 1000 };
	Monster adam{ "Adam", MonsterType::OGRE, 250 };

	printMonster(lilith);
	printMonster(adam);

	return 0;
}
