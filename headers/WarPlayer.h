#ifndef WARPLAYER_H
#define WARPLAYER_H

#include "Player.h"

/// Represents a player in the War card game.
class WarPlayer : public Player {
public:
    /// Constructor: Initializes a War player with a name and an empty deck.
    explicit WarPlayer(const std::string& name)
            : Player(name), deck_(true) {} // Deck gol


    bool hasCards() const override {
        return !deck_.isEmpty();
    }

    Card playCard() override {
        if (!hasCards()) {
            throw std::out_of_range("No cards left to play!");
        }
        return deck_.removeCard();
    }

    void collectCards(const std::vector<Card>& cards) override {
        deck_.collectCards(cards);
    }

    int cardsCount() const override {
        return deck_.getCards().size();
    }
    /// Gets the name or nickname of the player.
    /// @return The player's name.
    [[nodiscard]] const std::string& getName() const  {
        return name_;
    }
    /// Distributes all cards from the main deck in a circular manner among players.
    /// @param mainDeck The main deck of cards to be distributed.
    /// @param players The list of players participating in the game.
    static void dealCardsCircular(Deck& mainDeck, std::vector<WarPlayer>& players) {
        size_t currentPlayer = 0;
        while (!mainDeck.isEmpty()) {
            std::cout << "Dealing to " << players[currentPlayer].getName() << ": "
                      << mainDeck.getCards().front().to_string() << std::endl;

            players[currentPlayer].collectCards({mainDeck.removeCard()});

            std::cout << "Deck size: " << mainDeck.getCards().size() << std::endl;
            std::cout << players[currentPlayer].getName() << " now has "
                      << players[currentPlayer].cardsCount() << " cards." << std::endl;

            currentPlayer = (currentPlayer + 1) % players.size();
        }
    }

    const Deck& getDeck() const {
        return deck_;
    }
private:
    Deck deck_; // The deck for this player.
};

#endif // WARPLAYER_H