//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include <iostream>
#include <memory>
#include "Macao.h"
#include "War.h"

class GameManager {
public:
    // cppcheck-suppress unusedFunction
    ///Initialize the the names and the properties of the players.
    [[maybe_unused]] void startGame() {
        int choice = displayMenu();
        int humanPlayers, botPlayers;

        std::cout << "Enter number of human players: ";
        std::cin >> humanPlayers;
        std::cout << "Enter number of bots: ";
        std::cin >> botPlayers;

        if (choice == 1) currentGame = std::make_unique<Macao>(humanPlayers, botPlayers);
        else if (choice == 2) currentGame = std::make_unique<War>(humanPlayers, botPlayers);

        if (currentGame) {
            currentGame->initializeGame();
            while (!currentGame->isGameOver()) {
                currentGame->playTurn();
            }
            currentGame->displayWinner();
        }
    }

private:
    std::unique_ptr<CardGame> currentGame;

    // cppcheck-suppress unusedFunction
    [[maybe_unused]] int displayMenu() {
        std::cout << "Select a game:\n1. Macao\n2. War\nChoice: ";
        int choice;
        std::cin >> choice;
        return choice;
    }
};

#endif // OOP_GAMEMANAGER_H
