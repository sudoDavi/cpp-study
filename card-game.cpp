#include <iostream>
#include <array>
#include <cstddef> // for std::size_t
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <string>

namespace Random {
	static std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::uint_fast32_t Get(std::uint_fast32_t min = mersenne.min(), std::uint_fast32_t max = mersenne.max()) {
		std::uniform_int_distribution<std::uint_fast32_t> die{ min, max }; // Create a distribution in for function that needs it
		return die(mersenne);
	}
}

enum class CardRanks {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,

	TOTAL_RANKS
};

enum class CardSuits {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,

	TOTAL_SUITS
};

struct Card {
	CardSuits suit{};
	CardRanks rank{};
};
// Make the comparison operator for the Card struct
bool operator==(const Card& first, const Card& second) { return (first.suit == second.suit) && (first.rank == second.rank); }

char classifyRank(CardRanks rank) {
	switch (rank) {
		case CardRanks::ACE :
			return 'A';
		case CardRanks::TWO :
			return '2';
		case CardRanks::THREE :
			return '3';
		case CardRanks::FOUR :
			return '4';
		case CardRanks::FIVE :
			return '5';
		case CardRanks::SIX :
			return '6';
		case CardRanks::SEVEN :
			return '7';
		case CardRanks::EIGHT :
			return '8';
		case CardRanks::NINE :
			return '9';
		case CardRanks::TEN :
			return 'T';
		case CardRanks::JACK :
			return 'J';
		case CardRanks::QUEEN :
			return 'Q';
		case CardRanks::KING :
			return 'K';
		default:
			return 'X';
		}
}

char classifySuit(CardSuits suit) {
	switch (suit) {
		case CardSuits::CLUBS :
			return 'C';
		case CardSuits::DIAMONDS :
			return 'D';
		case CardSuits::HEARTS :
			return 'H';
		case CardSuits::SPADES :
			return 'S';
		default:
			return 'X';
	}
}

void printCard(const Card& card) {
	std::cout << classifyRank(card.rank) << classifySuit(card.suit);
}

int getCardValue(const Card& card) {
	if (card.rank < CardRanks::TEN)
		// Plus two to make the conversion correct
		return static_cast<int>(card.rank) + 2;
	else if (card.rank < CardRanks::ACE)
		return 10;
	else
		return 11;
}

// Creating an alias for to shorten the deck type, we'll be using it multiple times
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

void printDeck(const deck_type& deck ) {
	// Iterate over all cards in the deck calling printCard
	for (const auto& card : deck) {
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

deck_type createDeck() {
	// Create the deck and the index of the array
	deck_type deck;
	index_type index{ 0 };
	// Iterate over all possible cards and create the deck
	for (int suit{ 0 }; suit < static_cast<int>(CardSuits::TOTAL_SUITS); ++suit) {
		for (int rank{ 0 }; rank < static_cast<int>(CardRanks::TOTAL_RANKS); ++rank) {
			deck[index] = { static_cast<CardSuits>(suit), static_cast<CardRanks>(rank) };
			++index;
		}
	}
	return deck;
}

void shuffleDeck(deck_type& deck) {
	std::shuffle(deck.begin(), deck.end(), Random::mersenne);
}

Card getNewCard(const deck_type& deck, Card& previous) {
	Card newCard{ deck[static_cast<index_type>(Random::Get(0, 51))] };
	// If the new card is a repeat of the previous one, select a new card
	// this way we prevent the same card from being dealt twice
	while (newCard == previous)
		newCard = deck[static_cast<index_type>(Random::Get(0, 51))];

	previous = newCard;
	return newCard;
}

bool hitOrStand() {
	bool repeat{ false };
	do {
		std::cout << "Do you hit or stand ? ";
		std::string answer{};
		std::cin >> answer;

		if (answer.find("hit") != std::string::npos)
			return true;
		else if (answer.find("stand") != std::string::npos)
			return false;
		// Something has gone wrong or input is invalid
		else {
			// Fix cin just in case
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			repeat = true;
		}
	}while (repeat);

	// If it ever reaches this point without returning there is
	// something wrong with the compiler, but whatever, let's make g++ happy
	return false;
}

bool playBlackjack(const deck_type& deck) {
	// Get the first card which goes to the dealer
	Card dealtCard{ deck[static_cast<index_type>(Random::Get(0, 51))] };
	
	int dealerValue{ getCardValue(dealtCard) };
	std::cout << "Dealer has: ";
	printCard(dealtCard);
	std::cout << "\nWhich amounts to: " << dealerValue << '\n';

	// Deal player cards
	int playerValue{ getCardValue(getNewCard(deck, dealtCard)) };
	std::cout << "You have: ";
	printCard(dealtCard);
	// Spacing to format the text
	std::cout << ' ';
	// Give the player a new card and sum to his total value
	playerValue += getCardValue(getNewCard(deck, dealtCard));
	printCard(dealtCard);
	// Inform player's current value
	std::cout << "\nWhich amounts to: " << playerValue << '\n';

	// If hitOrStand returns true, the player wants another card, otherwise jump to the dealer
	while (hitOrStand()) {
		// Draw another card and show it to the player
		playerValue += getCardValue(getNewCard(deck, dealtCard));
		std::cout << "You got a: ";
		printCard(dealtCard);
		std::cout << "\nYour score is: " << playerValue << '\n';
		// If the player went over 21, he automatically looses
		if (playerValue > 21)
			return false;
	}

	// Time for the dealer to draw
	// He draws until his score is bigger or equal to 17
	while (dealerValue < 17) {
		// Draw cards for the dealer
		dealerValue += getCardValue(getNewCard(deck, dealtCard));
		std::cout << "Dealer got a : ";
		printCard(dealtCard);
		std::cout << "\nDealer is at : " << dealerValue << '\n';

		// We can return true here because the player will already have lost via the hitOrStand() if he went over 21
		// and so the player WINS!!
		if (dealerValue > 21)
			return true;
	}

	// If the player has a higher value than the dealer, the player wins
	// otherwise, their score is equal, since neither of them went over 21
	// or the player chickened out and the dealer got a higher value
	// **REFACTOR NEEDED** Make a tie possible
	if (playerValue > dealerValue)
		return true;
	else 
		return false;
}


int main() {
	auto deck{ createDeck() };
	std::cout << "Deck created.\n";
	printDeck(deck);
	std::cout << "Shuffling deck.\n";
	shuffleDeck(deck);

	bool won{ playBlackjack(deck) };

	if (won)
		std::cout << "Player wins!!";
	else
		std::cout << "Dealer wins!!";

	std::cout << '\n';
	
	return 0;
}
