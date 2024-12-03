//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>

class Player {
public:
    // cppcheck-suppress unusedFunction
    [[maybe_unused]]virtual void takeTurn() = 0;
    // cppcheck-suppress unusedFunction
    [[maybe_unused]]virtual bool isHuman() const = 0;

    virtual ~Player() = default;
};
class HumanPlayer : public Player {
public:
    // cppcheck-suppress unusedFunction
    [[maybe_unused]]void takeTurn() override {
        std::cout << "Human player's turn.\n";
        // Implement player actions here
    }

    // cppcheck-suppress unusedFunction
    [[maybe_unused]]bool isHuman() const override {
        return true;
    }
};
class Bot : public Player {
public:
    // cppcheck-suppress unusedFunction
    [[maybe_unused]]void takeTurn() override {
        std::cout << "Bot's turn.\n";
        // Implement bot decision-making logic here
    }

    // cppcheck-suppress unusedFunction
    [[maybe_unused]]bool isHuman() const override {
        return false;
    }
};

#endif //OOP_PLAYER_H
