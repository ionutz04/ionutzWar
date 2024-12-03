//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
///@Player will be used as a abstract class for every type of player: human and bot
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
    ///function which will be implemented in Macao and War because this has an interface purpose
    [[maybe_unused]]void takeTurn() override {
        std::cout << "Human player's turn.\n";
        // Implement player actions here
    }

    // cppcheck-suppress unusedFunction
    [[maybe_unused]]bool isHuman() const override {
        return true;
    }
};
///Has the same capabilities as Human, but this one will have a different game logic.
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
