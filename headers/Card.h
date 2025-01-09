#ifndef CARD_H
#define CARD_H

#include "Rank.h"
#include "Suit.h"
#include <string>

/// The Card class represents a playing card with a specific rank and suit.
class Card {
public:
    /// Constructor: Creates a card with the given rank and suit.
    Card(const Rank& rank, const Suit& suit) : rank_(rank), suit_(suit) {}

    /// Converts the card to a readable string format (e.g., "Ace of Spades").
    std::string to_string() const {
        return rank_to_string(rank_.get_value()) + " of " + suit_to_string(suit_.get_value());
    }

    /// Equality operator to compare two cards (both rank and suit must match).
    bool operator==(const Card& other) const {
        return rank_ == other.rank_ && suit_ == other.suit_;
    }

    /// Less-than operator for comparing cards (based on rank and then suit).
    bool operator<(const Card& other) const {
        return (rank_ < other.rank_) || (rank_ == other.rank_ && suit_ < other.suit_);
    }

    /// Greater-than operator for comparing cards (based on rank and then suit).
    bool operator>(const Card& other) const {
        return (rank_ > other.rank_) || (rank_ == other.rank_ && suit_ > other.suit_);
    }

    [[nodiscard]] const Rank &getRank() const {
        return rank_;
    }

private:
    Rank rank_; // The rank of the card.
    Suit suit_; // The suit of the card.

    /// Converts a numerical rank value to a string representation.
    static std::string rank_to_string(int rank) {
        switch (rank) {
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Jack";
            case 12: return "Queen";
            case 13: return "King";
            case 14: return "Ace";
            default: return "Unknown";
        }
    }

    /// Converts a numerical suit value to a string representation.
    static std::string suit_to_string(int suit) {
        switch (suit) {
            case 1: return "Hearts";
            case 2: return "Diamonds";
            case 3: return "Clubs";
            case 4: return "Spades";
            default: return "Unknown";
        }
    }
};

#endif // CARD_H
