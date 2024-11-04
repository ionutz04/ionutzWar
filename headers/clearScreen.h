//
// Created by ionut on 11/4/2024.
//

#ifndef OOP_CLEARSCREEN_H
#define OOP_CLEARSCREEN_H

#endif //OOP_CLEARSCREEN_H
#include <iostream>
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
