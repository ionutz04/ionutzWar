//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "Card.h"
#include "clearScreen.h"
class Renderer {
public:
    [[maybe_unused]]
    void displayCard(const Card& card) {
        card.display();
        std::cout << " ";
    }

    [[maybe_unused]]
    void showMessage(const std::string& message) {
        std::cout << message << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    [[maybe_unused]]
    void clearAndRedraw(const std::vector<Card>& cards) {
        clearScreen();
        for (const auto& card : cards) {
            displayCard(card);
        }
    }
};



#endif //OOP_RENDERER_H
