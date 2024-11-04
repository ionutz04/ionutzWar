//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_MACAO_H
#define OOP_MACAO_H

#endif //OOP_MACAO_H
#include "Card.h"
#include "CardGame.h"
#include <iostream>
class Macao : public CardGame {
public:
    Macao(int humans, int bots) : CardGame(humans, bots) {}

    void initializeGame() override {
        std::cout << "Starting Macao game with " << humanPlayers << " human players and " << botPlayers << " bots...\n";

        for (int i = 0; i < humanPlayers; ++i) {
            players.push_back(std::make_unique<HumanPlayer>());
        }
        for (int i = 0; i < botPlayers; ++i) {
            players.push_back(std::make_unique<Bot>());
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
        // Implement Macao-specific game-over condition
        return false; // Placeholder
    }

    void displayWinner() override {
        std::cout << "Macao: Displaying winner...\n";
        // Implement display logic here
    }
};
