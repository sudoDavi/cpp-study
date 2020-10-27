#include <iostream>
#include <array>
#include <numeric> // for std::reduce

enum Items : std::size_t {
	HEALTH_POTION,
	TORCH,
	ARROW,
	MAX_LENGHT,
};

int countTotalItems(const std::array<int, Items::MAX_LENGHT>& inventory) {
	return std::reduce(inventory.begin(), inventory.end());
}

int main() {
	// Start the "player" inventory
	// with 2 potions, 5 torches and 10 arrows
	std::array playerInv{ 2, 5, 10 };
	
	std::cout << "The player has a total of " << countTotalItems(playerInv) << " items.\n";
	std::cout << "And he also has " << playerInv[Items::TORCH] << " torch(es).\n";
	
	return 0;
}
