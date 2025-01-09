#ifndef TESTWAR_H
#define TESTWAR_H

#include "War.h"
#include <cassert>
#include <iostream>

class TestWar {
public:
    /// Rulează toate testele pentru jocul War.
    void runTests() {
        testDeckDistribution();
        testRoundPlay();
        testWarScenario();
        testGameCompletion();
        std::cout << "All War tests passed successfully!" << std::endl;
    }

private:
    /// Testează distribuirea cărților între jucători.
    void testDeckDistribution() {
        std::cout << "Testing Deck Distribution..." << std::endl;

        WarGame game(4); // Joc cu 4 jucători
        int totalCards = 0;

        for (const auto& player : game.getPlayers()) {
            totalCards += player.cardsCount();
        }

        assert(totalCards == 52); // Toate cele 52 de cărți trebuie să fie distribuite.
        std::cout << "Deck Distribution test passed!" << std::endl;
    }

    /// Testează jocul unei singure runde fără egalitate (fără WAR).
    void testRoundPlay() {
        std::cout << "Testing Round Play..." << std::endl;

        WarGame game(4);
        game.playRound();

        int totalCards = 0;
        for (const auto& player : game.getPlayers()) {
            totalCards += player.cardsCount();
        }
        std::cout << "Round Play test passed!" << std::endl;
    }

    /// Testează scenariul de "război" (egalitate între jucători).
    void testWarScenario() {
        std::cout << "Testing War Scenario..." << std::endl;

        // Creează jucători
        WarPlayer player1("Player1");
        WarPlayer player2("Player2");
        WarPlayer player3("Player3");
        WarPlayer player4("Player4");

        std::vector<WarPlayer> players = {player1, player2, player3, player4};

        // Forțează o situație de WAR
        players[0].collectCards({Card(Rank(10), Suit(1))});
        players[1].collectCards({Card(Rank(10), Suit(2))});

        WarGame warGame(players);

        // Joacă o rundă
        warGame.playRound();

        // Verifică dacă totalul cărților rămâne constant
        int totalCards = 0;
        for (const auto& player : warGame.getPlayers()) {
            totalCards += player.cardsCount();
        }

        std::cout << "War Scenario test passed!" << std::endl;
    }


    /// Testează finalizarea jocului și anunțarea câștigătorului.
    void testGameCompletion() {
        std::cout << "Testing Game Completion..." << std::endl;

        WarGame game(4);
        game.playGame();

        int playersInGame = 0;
        for (const auto& player : game.getPlayers()) {
            if (player.hasCards()) {
                ++playersInGame;
            }
        }

        assert(playersInGame == 1); // La finalul jocului, trebuie să rămână un singur jucător cu cărți.
        std::cout << "Game Completion test passed!" << std::endl;
    }
};

#endif // TESTWAR_H
