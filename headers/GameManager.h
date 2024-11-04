//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#endif //OOP_GAMEMANAGER_H
#include <iostream>
#include <memory>
#include "Macao.h"
#include "War.h"

class GameManager {
public:
    void startGame() {
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

    int displayMenu() {
        std::cout << "Select a game:\n1. Macao\n2. War\nChoice: ";
        int choice;
        std::cin >> choice;
        return choice;
    }
};
