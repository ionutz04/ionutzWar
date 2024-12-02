//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_CARD_H
#define OOP_CARD_H
#include <string>
#include <iostream>

class Card {
public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };
    enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

    Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

//    void display() const {
//        std::string rankStr = rankToString();
//        std::string suitStr = suitToString();
//        std::cout << "[" << rankStr << " of " << suitStr << "]";
//    }

private:
    Rank rank;
    Suit suit;

    std::string rankToString() const {
        switch (rank) {
            case Two: return "2";
            case Three: return "3";
            case Four: return "4";
            case Five: return "5";
            case Six: return "6";
            case Seven: return "7";
            case Eight: return "8";
            case Nine: return "9";
            case Ten: return "10";
            case Jack: return "Jack";
            case Queen: return "Queen";
            case King: return "King";
            case Ace: return "Ace";
            default: return "";
        }
    }

    std::string suitToString() const {
        switch (suit) {
            case Hearts: return "♥";
            case Diamonds: return "♦";
            case Clubs: return "♣";
            case Spades: return "♠";
            default: return "";
        }
    }
};



#endif //OOP_CARD_H
