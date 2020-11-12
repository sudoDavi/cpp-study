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

class Card {
public: // Type definitions
	enum class Rank {
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

	enum class Suit {
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES,

		TOTAL_SUITS
	};
private: // Members functions and variables
	Rank m_rank{};
	Suit m_suit{};

	char classifyRank() const {
		static constexpr std::array rankTable {
			'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
		};

		return rankTable[static_cast<std::size_t>(m_rank)];
	}

	char classifySuit() const {
		static constexpr std::array suitTable{ 'C', 'D', 'H', 'S' };

		return suitTable[static_cast<std::size_t>(m_suit)];
	}

public:
	// Public default constructor
	Card(Rank rank = Rank::ACE, Suit suit = Suit::CLUBS) : m_rank{rank}, m_suit{suit} {}

	void print() const {
		std::cout << classifyRank() << classifySuit();
	}

	int value() const {
		if (m_rank < Rank::TEN)
			// Plus two to make the conversion correct
			return static_cast<int>(m_rank) + 2;
		else if (m_rank < Rank::ACE)
			return 10;
		else
			return 11;
	}

	bool isAce() const {
		return m_rank == Rank::ACE;
	}
};

class Deck {
private:
	std::array<Card, GameConfig::deckSize> m_deck{};
	using index_t = std::array<Card, GameConfig::deckSize>::size_type;
	index_t m_cardIndex{ 0 };
public:
	Deck() {
		index_t card_index{ 0 };
		for (int suit{0}; suit < static_cast<int>(Card::Suit::TOTAL_SUITS); ++suit) {
			for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::TOTAL_RANKS); ++rank) {
				// Assign the deck and then increment the index
				m_deck[card_index++] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
			}
		}	
	}

	void print() const {
		// Iterate over all cards in the deck calling printCard
		for (const auto& card : m_deck) {
			card.print();
			std::cout << ' ';
		}
		std::cout << '\n';
	}

	void shuffle() {
		m_cardIndex = 0;
		std::shuffle(m_deck.begin(), m_deck.end(), Random::mersenne);
	}

	const Card& dealCard() {
		return m_deck[m_cardIndex++];
	}
};

class Player {
private:
	std::string m_name{};
	int m_score{};
	int m_aceCounter{};
public:
	Player(const std::string& name = "Player") : m_name{name} {}

	const Card drawCard(Deck& deck) {
		const auto dealtCard{ deck.dealCard() };
		m_score += dealtCard.value();
		if (dealtCard.isAce())
			++m_aceCounter;
		while (m_aceCounter && (m_score > 21)) {
			// If the player.score(dealer or player) is above the maximum
			// make it so the ACE they have is equal to a one, while they still have aces
			m_score -= 10;
			--m_aceCounter;
		}

		return dealtCard;
	}

	int score() const {
		return m_score;
	}

	bool isBust() const {
		return m_score > GameConfig::maximumScore;
	}
};

enum class MatchOutcome {
	LOST,
	WON,
	TIE,

	TOTAL_OUTCOMES
};

class BlackJack {
private: // Member variables and functions
	Deck m_deck{};
	Player m_player{};
	Player m_dealer{"Dealer"};

	// Deal the dealer's initial cards and return their value
	void dealDealerInitial() {
		std::cout << "Dealer has: ";
		m_dealer.drawCard(m_deck).print();
		std::cout << "\nWhich amounts to: " << m_dealer.score() << '\n';
	}

	static bool hitOrStand() {
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

	// Deal the player's initial cards
	void dealPlayerInitial() {
		std::cout << "You have: ";
		// Give the player its first card and print it
		m_player.drawCard(m_deck).print();
		// Spacing to format the text
		std::cout << ' ';
		
		// Give the player a new card and sum to his total score
		m_player.drawCard(m_deck).print();
		// Inform player's current value
		std::cout << "\nWhich amounts to: " << m_player.score() << '\n';
	}

public: // Public member functions
	BlackJack(const Deck& deck = Deck{}) : m_deck{deck} {}

	MatchOutcome play() {
		dealDealerInitial();
		dealPlayerInitial();
		// If hitOrStand returns true, the player wants another card, otherwise jump to the dealer
		while(hitOrStand()) {
			std::cout << "You got a: ";
			// Draw another card and show it to the player
			m_player.drawCard(m_deck).print();
			std::cout << "\nYour score is: " << m_player.score() << '\n';
			// If the player went over 21, he automatically looses
			if (m_player.isBust())
				return MatchOutcome::LOST;		
		}

		// Time for the dealer to draw
		// He draws until his score is bigger or equal to GameConfig::dealerStandAt
		while (m_dealer.score() < GameConfig::dealerStandAt) {
				std::cout << "Dealer got a : ";
				// Draw cards for the dealer
				m_dealer.drawCard(m_deck).print();
				std::cout << "\nDealer is at : " << m_dealer.score() << '\n';
		
				// We can return true here because the player will already have lost via the hitOrStand() if he went over 21
				// and so the player WINS!!
				if (m_dealer.isBust())
					return MatchOutcome::WON;
		}

		// If the player has a higher value than the dealer, the player wins
		// otherwise, their score is equal, since neither of them went over 21
		// or the player chickened out and the dealer got a higher value
		if (m_player.score() > m_dealer.score())
			return MatchOutcome::WON;
		else if (m_player.score() < m_dealer.score())
			return MatchOutcome::LOST;
		else
			return MatchOutcome::TIE;
	}
};
 
const std::string manageOutcome(MatchOutcome outcome) {
	static constexpr std::array outcomes{ "Dealer wins!!", "Player wins!!", "It's a tie!!" };
	return outcomes[static_cast<std::size_t>(outcome)];
}

int main() {
	Deck deck{};
	deck.print();
	deck.shuffle();

	BlackJack game{ deck };
	
	std::cout << manageOutcome(game.play()) << '\n';

	return 0;
}
