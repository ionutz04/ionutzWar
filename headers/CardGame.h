//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_CARDGAME_H
#define OOP_CARDGAME_H
#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"

class CardGame {
public:
    CardGame(int humans, int bots) : humanPlayers(humans), botPlayers(bots) {}

    [[maybe_unused]]virtual void initializeGame() = 0;
    [[maybe_unused]]virtual void playTurn() = 0;
    [[maybe_unused]]virtual bool isGameOver() = 0;
    [[maybe_unused]]virtual void displayWinner() = 0;

    [[maybe_unused]]virtual ~CardGame() = default;

protected:
    int humanPlayers;
    int botPlayers;
    std::vector<std::unique_ptr<Player>> players;
};



#endif //OOP_CARDGAME_H
