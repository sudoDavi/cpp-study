#include <iostream>
#include <array>
#include <cstddef> // for std::size_t
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937
#include <ctime> // for std::time

namespace Random {
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

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

int main() {
	auto deck{ createDeck() };
	std::cout << "Deck created.\n";
	printDeck(deck);
	std::cout << "Shuffling deck.\n";
	shuffleDeck(deck);
	printDeck(deck);

	index_type random{ Random::Get(0, 51) };
	std::cout << "Card: ";
	printCard(deck[random]);
	std::cout << " Has value: " << getCardValue(deck[random]) << '\n';
	
	return 0;
}
