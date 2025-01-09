#ifndef SUIT_H
#define SUIT_H

#include <stdexcept>

/// The Suit class represents the suit of a playing card (e.g., Hearts, Spades).
class Suit {
public:
    /// Constructor: Validates and sets the suit value.
    /// @param suit The numerical value representing the suit (1 for Hearts, 4 for Spades).
    explicit Suit(int suit) {
        if (!is_valid_suit(suit)) {
            throw std::invalid_argument("Suit not correct!");
        }
        suit_ = static_cast<suits>(suit);
    }

    /// Returns the numerical value of the suit.
    int get_value() const { return static_cast<int>(suit_); }

    /// Equality operator to compare two suits.
    bool operator==(const Suit& other) const { return suit_ == other.suit_; }

    /// Less-than operator to compare two suits.
    bool operator<(const Suit& other) const { return suit_ < other.suit_; }

    /// Greater-than operator to compare two suits.
    bool operator>(const Suit& other) const { return suit_ > other.suit_; }

private:
    /// Enumeration of possible suits for a card.
    enum suits {
        Hearts = 1,
        Diamonds = 2,
        Clubs = 3,
        Spades = 4
    };

    suits suit_; // The suit of the card.

    /// Validates if a given suit is within the allowed range.
    static bool is_valid_suit(int suit) {
        return suit >= Hearts && suit <= Spades;
    }
};

#endif // SUIT_H
