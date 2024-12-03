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

    // cppcheck-suppress unusedFunction
    ///this function will initilize the war game, for example, how many players will be human, and how many will be bots
    [[maybe_unused]]void initializeGame() override {
        std::cout << "Starting War game with " << humanPlayers << " human players and " << botPlayers << " bots...\n";

        for (int i = 0; i < humanPlayers; ++i) {
            players.push_back(std::make_unique<HumanPlayer>());
        }
        for (int i = 0; i < botPlayers; ++i) {
            players.push_back(std::make_unique<Bot>());
        }

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
    ///his function will stop the war game when a winner is found
    [[maybe_unused]]bool isGameOver() override {
        // Implement War-specific game-over condition
        return false; // Placeholder
    }

    // cppcheck-suppress unusedFunction
    ///This function will be append in the @isGameOver function in order to display the winner
    [[maybe_unused]]void displayWinner() override {
        std::cout << "War: Displaying winner...\n";
        // Implement display logic here
    }
};
