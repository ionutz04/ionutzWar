#ifndef MACAOPLAYER_H
#define MACAOPLAYER_H

#include "Player.h"

/// Represents a player in the Macao card game.
class MacaoPlayer : public Player {
public:
    /// Constructor: Initializes a Macao player with a name and an empty deck.
    explicit MacaoPlayer(const std::string& name) : Player(name) , deck_(true) {}

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

    /// Distributes a fixed number of cards to each player in a circular manner.
    /// @param mainDeck The main deck of cards to be distributed.
    /// @param players The list of players participating in the game.
    /// @param cardsPerPlayer The number of cards each player should receive.
    static void dealCardsCircular(Deck& mainDeck, std::vector<MacaoPlayer>& players, int cardsPerPlayer) {
        size_t currentPlayer = 0;
        int cardsDealt = 0;
        int totalCardsToDeal = cardsPerPlayer * players.size();

        while (cardsDealt < totalCardsToDeal && !mainDeck.isEmpty()) {
            std::cout << "Dealing to " << players[currentPlayer].getName() << ": "
                      << mainDeck.getCards().front().to_string() << std::endl;

            players[currentPlayer].collectCards({mainDeck.removeCard()});
            std::cout << "Deck size: " << mainDeck.getCards().size() << std::endl;
            std::cout << players[currentPlayer].getName() << " now has "
                      << players[currentPlayer].cardsCount() << " cards." << std::endl;

            currentPlayer = (currentPlayer + 1) % players.size();
            cardsDealt++;
        }
    }
    const Deck& getDeck() const {
        return deck_;
    }
private:
    Deck deck_; // The deck for this player.
};

#endif // MACAOPLAYER_H