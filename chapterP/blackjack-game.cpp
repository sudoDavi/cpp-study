#include <iostream>
#include <array>
#include <cstddef> // for std::size_t
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <string>

namespace GameConfig {
	// Set at what score the dealer stands
	constexpr int dealerStandAt{ 17 };
	// Set the maximum score a player can have without busting
	constexpr int maximumScore{ 21 };
	// Set the number of decks, i.e 1 means a normal 52 sized deck, 2 means two normal 52 sized decks, etc...
	constexpr int numberOfDecks{ 1 };
	// Set the number of cards in a deck, currently the game only supports 52 cards per deck without accounting
	// for the numberOfDecks multiplier
	constexpr int deckSize{ 52 };
}

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

enum class MatchOutcome {
	LOST,
	WON,
	TIE,

	TOTAL_OUTCOMES
};

struct Card {
	CardSuits suit{};
	CardRanks rank{};
};

struct Player {
	int score{};
	int aceCounter{};
};

char classifyRank(CardRanks rank) {
	constexpr std::array rankTable {
		'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
	};

	return rankTable[static_cast<std::size_t>(rank)];
}

char classifySuit(CardSuits suit) {
	constexpr std::array suitTable{ 'C', 'D', 'H', 'S' };

	return suitTable[static_cast<std::size_t>(suit)];
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
using deck_type = std::array<Card, GameConfig::deckSize * GameConfig::numberOfDecks>;
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
	index_type card_index{ 0 };
	// Create equally sized decks as long as deck_index is smaller than GameConfig::numberOfDecks
	for (int deck_index{ 0 }; deck_index < GameConfig::numberOfDecks; ++deck_index)
		// Iterate over all possible cards and create the deck
		for (int suit{ 0 }; suit < static_cast<int>(CardSuits::TOTAL_SUITS); ++suit) {
			for (int rank{ 0 }; rank < static_cast<int>(CardRanks::TOTAL_RANKS); ++rank) {
				// Assign the deck and then increment the index
				deck[card_index++] = { static_cast<CardSuits>(suit), static_cast<CardRanks>(rank) };
			}
		}
	return deck;
}

void shuffleDeck(deck_type& deck) {
	std::shuffle(deck.begin(), deck.end(), Random::mersenne);
}

Card getNewCard(const deck_type& deck) {
	// Get cards from the top of the deck, instead of randomly accessing the deck
	static index_type cardIndex{ 0 };
	// Check if the index++ will overflow the deck next time the function is called
	if ((cardIndex + 1) > GameConfig::deckSize)
		cardIndex = 0;

	// This is the new Card, storing it's value is not in the scope of this function
	return deck[cardIndex++];
}

bool hitOrStand() {
	// We will repeat this loop until the player has given a valid input
	while(true) {
		std::cout << "Do you hit or stand ? ";
		std::string answer{};
		std::cin >> answer;

		if (answer.find("hit") != std::string::npos)
			return true;
		else if (answer.find("stand") != std::string::npos)
			return false;
		// Something has gone wrong or input is invalid
		// Fix cin just in case
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

// Adds the score of card to player(dealer or player), handling the aces as well
void addScore(const Card& card, Player& player) {
	player.score += getCardValue(card);
	if (card.rank == CardRanks::ACE)
		++player.aceCounter;
	while (player.aceCounter && (player.score > 21)) {
		// If the player.score(dealer or player) is above the maximum
		// make it so the ACE they have is equal to a one, while they still have aces
		player.score -= 10;
		--player.aceCounter;
	}
	
}

// Deal the dealer's initial cards and return their value
void dealDealerInitial(Card& dealtCard, Player& dealer) {
	std::cout << "Dealer has: ";
	printCard(dealtCard);
	// addScore() to dealer, so their cards are handled correctly
	addScore(dealtCard, dealer);
	std::cout << "\nWhich amounts to: " << dealer.score << '\n';
}

// Deal the player's initial cards
void dealPlayerInitial(const deck_type& deck, Card& dealtCard, Player& player) {
	// Give the player its first card
	dealtCard = getNewCard(deck);
	std::cout << "You have: ";
	printCard(dealtCard);
	// Spacing to format the text
	std::cout << ' ';
	// AddScore() to player, so their cards are handled correctly
	addScore(dealtCard, player);
	
	// Give the player a new card and sum to his total value
	dealtCard = getNewCard(deck);
	// Add the new card to the player's score
	addScore(dealtCard, player);
	printCard(dealtCard);
	// Inform player's current value
	std::cout << "\nWhich amounts to: " << player.score << '\n';
}

MatchOutcome playBlackjack(const deck_type& deck) {
	// Initialize the dealtCard, which will be the first card in the deck
	Card dealtCard{ getNewCard(deck) };

	// Deal the Dealer's initial Cards, modifying his struct and dealtCard
	Player dealer{};
	dealDealerInitial(dealtCard, dealer);

	// Deal player initial cards, this modifies dealtCard and the player
	Player player{};
	dealPlayerInitial(deck, dealtCard, player);

	// If hitOrStand returns true, the player wants another card, otherwise jump to the dealer
	while (hitOrStand()) {
		// Draw another card and show it to the player
		dealtCard = getNewCard(deck);
		addScore(dealtCard, player);
		std::cout << "You got a: ";
		printCard(dealtCard);
		std::cout << "\nYour score is: " << player.score << '\n';
		// If the player went over 21, he automatically looses
		if (player.score > GameConfig::maximumScore)
			return MatchOutcome::LOST;
	}

	// Time for the dealer to draw
	// He draws until his score is bigger or equal to GameConfig::dealerStandAt
	while (dealer.score < GameConfig::dealerStandAt) {
		// Draw cards for the dealer
		dealtCard = getNewCard(deck);
		addScore(dealtCard, dealer);
		std::cout << "Dealer got a : ";
		printCard(dealtCard);
		std::cout << "\nDealer is at : " << dealer.score << '\n';

		// We can return true here because the player will already have lost via the hitOrStand() if he went over 21
		// and so the player WINS!!
		if (dealer.score > GameConfig::maximumScore)
			return MatchOutcome::WON;
	}

	// If the player has a higher value than the dealer, the player wins
	// otherwise, their score is equal, since neither of them went over 21
	// or the player chickened out and the dealer got a higher value
	if (player.score > dealer.score)
		return MatchOutcome::WON;
	else if (player.score < dealer.score)
		return MatchOutcome::LOST;
	else
		return MatchOutcome::TIE;
}

std::string manageOutcome(MatchOutcome outcome) {
	constexpr std::array outcomes{ "Dealer wins!!", "Player wins!!", "It's a tie!!" };
	return outcomes[static_cast<std::size_t>(outcome)];
}

int main() {
	auto deck{ createDeck() };
	std::cout << "Deck created.\n";
	printDeck(deck);
	std::cout << "Shuffling deck.\n";
	shuffleDeck(deck);

	std::cout << manageOutcome(playBlackjack(deck));

	std::cout << '\n';
	
	return 0;
}
