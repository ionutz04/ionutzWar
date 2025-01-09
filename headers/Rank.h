#ifndef RANK_H
#define RANK_H

#include <stdexcept>

/// The Rank class represents the rank of a playing card (e.g., Two, Three, Ace).
class Rank {
public:
    /// Constructor: Validates and sets the rank value.
    /// @param rank The numerical value representing the rank (2 for Two, 14 for Ace).
    explicit Rank(int rank) {
        if (!is_valid_rank(rank)) {
            throw std::invalid_argument("Rank not correct!");
        }
        rank_ = static_cast<ranks>(rank);
    }

    /// Returns the numerical value of the rank.
    int get_value() const { return static_cast<int>(rank_); }

    /// Equality operator to compare two ranks.
    bool operator==(const Rank& other) const { return rank_ == other.rank_; }

    /// Less-than operator to compare two ranks.
    bool operator<(const Rank& other) const { return rank_ < other.rank_; }

    /// Greater-than operator to compare two ranks.
    bool operator>(const Rank& other) const { return rank_ > other.rank_; }

private:
    /// Enumeration of possible ranks for a card.
    enum ranks {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };

    ranks rank_; // The rank of the card.

    /// Validates if a given rank is within the allowed range.
    static bool is_valid_rank(int rank) {
        return rank >= Two && rank <= Ace;
    }
};

#endif // RANK_H
