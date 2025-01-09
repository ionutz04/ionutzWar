#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
#include "Card.h"
class Deck {
public:
    Deck(bool initializeEmpty = false) {
        if (!initializeEmpty) {
            for (int suit = 1; suit <= 4; ++suit) { // Suit: Hearts, Diamonds, Clubs, Spades
                for (int rank = 2; rank <= 14; ++rank) { // Rank: Two -> Ace
                    cards_.emplace_back(Rank(rank), Suit(suit));
                }
            }
        } else {
            std::cout << "Deck initialized empty." << std::endl;
        }
    }
    /// Shuffles the deck randomly using a modern random number generator.
    void shuffle() {
        std::random_device rd; // Random device for entropy
        std::mt19937 gen(rd()); // Mersenne Twister engine seeded with entropy
        std::shuffle(cards_.begin(), cards_.end(), gen); // Shuffle using the engine
    }

    /// Removes the top card from the deck and returns it.
    /// @throws std::out_of_range if the deck is empty.
    Card removeCard() {
        if (!cards_.empty()) {
            Card topCard = cards_.front(); // Get the top card
            cards_.erase(cards_.begin()); // Remove it from the deck
            return topCard;
        }
        throw std::out_of_range("Deck is empty!");
    }

    /// Adds a list of new cards to the deck.
    /// @param newCards A vector of cards to be added to the deck.
    void collectCards(const std::vector<Card>& newCards) {
        cards_.insert(cards_.end(), newCards.begin(), newCards.end());
    }

    /// Sorts the deck in ascending order based on rank and suit.
    void sort() {
        std::sort(cards_.begin(), cards_.end(), [](const Card& a, const Card& b) {
            return a < b;
        });
    }

    /// Returns the current list of cards in the deck.
    const std::vector<Card>& getCards() const {
        return cards_;
    }

    /// Checks if the deck is empty.
    bool isEmpty() const {
        return cards_.empty();
    }
private:
    std::vector<Card> cards_;
};

#endif // DECK_H
