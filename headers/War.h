//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_WAR_H
#define OOP_WAR_H

#endif //OOP_WAR_H
#include <iostream>
#include "Card.h"
#include "CardGame.h"
class War : public CardGame {
public:
    War(int humans, int bots) : CardGame(humans, bots) {}

    void initializeGame() override {
        std::cout << "Starting War game with " << humanPlayers << " human players and " << botPlayers << " bots...\n";

        for (int i = 0; i < humanPlayers; ++i) {
            players.push_back(std::make_unique<HumanPlayer>());
        }
        for (int i = 0; i < botPlayers; ++i) {
            players.push_back(std::make_unique<AIPlayer>());
        }

        // Additional setup as required
    }

    void playTurn() override {
        for (auto& player : players) {
            player->takeTurn();
            if (isGameOver()) break;
        }
    }

    bool isGameOver() override {
        // Implement War-specific game-over condition
        return false; // Placeholder
    }

    void displayWinner() override {
        std::cout << "War: Displaying winner...\n";
        // Implement display logic here
    }
};
