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

    // cppcheck-suppress unusedFunction
    ///this function will initilize the macao game, for example, how many players will be human, and how many will be bots
    [[maybe_unused]]void initializeGame() override {
        std::cout << "Starting Macao game with " << humanPlayers << " human players and " << botPlayers << " bots...\n";

        for (int i = 0; i < humanPlayers; ++i) {
            players.push_back(std::make_unique<HumanPlayer>());///< [in]here will setup the human players
        }

        for (int i = 0; i < botPlayers; ++i) {
            players.push_back(std::make_unique<Bot>());///< [in]here will setup the human players
        }
        ///here will see how many instances are needed for bots

        // Additional setup as required
    }

    // cppcheck-suppress unusedFunction
    ///This function will run the steps that the player needs to follow in the game
    [[maybe_unused]]void playTurn() override {
        for (auto& player : players) {
            player->takeTurn();
            if (isGameOver()) break;
        }
    }

    // cppcheck-suppress unusedFunction
    ///This function will stop the macao game when a winner is found
    [[maybe_unused]]bool isGameOver() override {
        // Implement Macao-specific game-over condition
        return false; // Placeholder
    }

    // cppcheck-suppress unusedFunction
    ///This function will be append in the @isGameOver function in order to display the winner
    [[maybe_unused]]void displayWinner() override {
        std::cout << "Macao: Displaying winner...\n";
        // Implement display logic here
    }
};
