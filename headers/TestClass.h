#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "Deck.h"
#include "WarPlayer.h"
#include "MacaoPlayer.h"
#include <iostream>
#include <cassert>
#include <vector>

/// A class for testing the functionality of Rank, Suit, Card, Deck, and circular dealing.
class TestClass {
public:
    /// Runs all the tests.
    void runTests() {
        testRank();
        testSuit();
        testCard();
        testDeck();
        testWarCircularDealing();
        testMacaoCircularDealing();
        std::cout << "All tests passed successfully!" << std::endl;
    }

private:
    /// Test the functionality of the Rank class.
    void testRank() {
        std::cout << "Testing Rank..." << std::endl;

        Rank rank1(2); // Two
        Rank rank2(14); // Ace

        assert(rank1.get_value() == 2);
        assert(rank2.get_value() == 14);

        assert(rank1 < rank2);
        assert(rank2 > rank1);
        assert(!(rank1 == rank2));

        std::cout << "Rank tests passed!" << std::endl;
    }

    /// Test the functionality of the Suit class.
    void testSuit() {
        std::cout << "Testing Suit..." << std::endl;

        Suit suit1(1); // Hearts
        Suit suit2(4); // Spades

        assert(suit1.get_value() == 1);
        assert(suit2.get_value() == 4);

        assert(suit1 < suit2);
        assert(suit2 > suit1);
        assert(!(suit1 == suit2));

        std::cout << "Suit tests passed!" << std::endl;
    }

    /// Test the functionality of the Card class.
    void testCard() {
        std::cout << "Testing Card..." << std::endl;

        Rank rank1(2); // Two
        Suit suit1(1); // Hearts
        Card card1(rank1, suit1);

        Rank rank2(14); // Ace
        Suit suit2(4); // Spades
        Card card2(rank2, suit2);

        assert(card1.to_string() == "Two of Hearts");
        assert(card2.to_string() == "Ace of Spades");

        assert(card1 < card2);
        assert(card2 > card1);
        assert(!(card1 == card2));

        std::cout << "Card tests passed!" << std::endl;
    }

    /// Test the functionality of the Deck class.
    void testDeck() {
        std::cout << "Testing Deck..." << std::endl;

        Deck deck; // Utilizare directă a clasei Deck
        assert(deck.getCards().size() == 52); // Verify the deck contains 52 cards.

        // Test shuffle
        deck.shuffle();
        std::vector<Card> shuffledCards = deck.getCards();

        // Test removeCard
        Card removedCard = deck.removeCard();
        assert(deck.getCards().size() == 51); // Deck should have one less card.

        // Test collectCards
        deck.collectCards({removedCard});
        assert(deck.getCards().size() == 52); // Deck should be back to 52 cards.

        // Test sort
        deck.sort();
        std::vector<Card> sortedCards = deck.getCards();
        assert(sortedCards.front().to_string() == "Two of Hearts"); // First card should be "Two of Hearts"
        assert(sortedCards.back().to_string() == "Ace of Spades");  // Last card should be "Ace of Spades"

        std::cout << "Deck tests passed!" << std::endl;
    }

    /// Test circular dealing for War game.
    void testWarCircularDealing() {
        Deck mainDeck; // Utilizare directă a clasei Deck
        mainDeck.shuffle();

        WarPlayer player1("Player1");
        WarPlayer player2("Player2");
        WarPlayer player3("Player3");
        WarPlayer player4("Player4");
        WarPlayer player5("Player5");

        std::vector<WarPlayer> players = {player1, player2, player3, player4, player5};

        // Verificare: Fiecare jucător începe cu 0 cărți.
        for (const auto& player : players) {
            assert(player.cardsCount() == 0 && "Player's deck should be empty at initialization.");
        }

        WarPlayer::dealCardsCircular(mainDeck, players);

        // Verificare: Deck-ul principal este gol după distribuire.
        assert(mainDeck.isEmpty());
        std::cout << "War Circular Dealing passed!" << std::endl;
    }

    /// Test circular dealing for Macao game.
    void testMacaoCircularDealing() {
        std::cout << "Testing Macao Circular Dealing..." << std::endl;

        Deck mainDeck; // Utilizare directă a clasei Deck
        mainDeck.shuffle();

        MacaoPlayer player1("Player1");
        MacaoPlayer player2("Player2");
        MacaoPlayer player3("Player3");
        MacaoPlayer player4("Player4");

        std::vector<MacaoPlayer> players = {player1, player2, player3, player4};

        // Verificare: Fiecare jucător începe cu 0 cărți.
        for (const auto& player : players) {
            assert(player.cardsCount() == 0 && "Player's deck should be empty at initialization.");
        }

        // Distribuire circulară: fiecare jucător primește 5 cărți
        MacaoPlayer::dealCardsCircular(mainDeck, players, 5);

        // Verificare: Fiecare jucător primește exact 5 cărți.
        for (const auto& player : players) {
            assert(player.cardsCount() == 5);
            std::cout << player.getName() << " has 5 cards." << std::endl;
        }

        // Verificare: Deck-ul principal are restul cărților
        int remainingCards = mainDeck.getCards().size();
        std::cout << "Remaining cards in deck: " << remainingCards << std::endl;
        assert(remainingCards == 52 - (5 * players.size()));

        std::cout << "Macao Circular Dealing passed!" << std::endl;
    }
};

#endif // TESTCLASS_H
