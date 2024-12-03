//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_DECK_H
#define OOP_DECK_H

#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include "Card.h"

class Deck {
public:
    Deck() {
        for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
            for (int rank = Card::Two; rank <= Card::Ace; ++rank) {
                cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
            }
        }
    }

    // cppcheck-suppress unusedFunction
    [[maybe_unused]] void shuffle() {
        auto rng = std::default_random_engine{ std::random_device{}() };
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    // cppcheck-suppress unusedFunction
    [[maybe_unused]] Card draw() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

private:
    std::vector<Card> cards;
};

#endif // OOP_DECK_H
