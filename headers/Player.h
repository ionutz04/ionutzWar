//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>

class Player {
public:
    virtual void takeTurn() = 0;
    //virtual bool isHuman() const = 0;

    virtual ~Player() = default;
};
class HumanPlayer : public Player {
public:
    void takeTurn() override {
        std::cout << "Human player's turn.\n";
        // Implement player actions here
    }

//    bool isHuman() const override {
//        return true;
//    }
};
class Bot : public Player {
public:
    void takeTurn() override {
        std::cout << "Bot's turn.\n";
        // Implement bot decision-making logic here
    }

//    bool isHuman() const override {
//        return false;
//    }
};

#endif //OOP_PLAYER_H
