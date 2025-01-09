#include <iostream>
#include "./headers/TestWar.h"
#include "./headers/Card.h"
#include "./headers/TestClass.h"
#include "headers/War.h"
int main() {
    //test for Deck,Card,Players and it's children
//    TestClass tester;
//    tester.runTests();
    //test for War game
//    try {
//        std::cout << "Starting War Game Tests...\n";
//
//        TestWar testWar;
//        testWar.runTests();
//
//        std::cout << "All tests completed successfully!\n";
//    } catch (const std::exception& e) {
//        std::cerr << "An error occurred during testing: " << e.what() << std::endl;
//        return 1;
//    } catch (...) {
//        std::cerr << "An unknown error occurred during testing." << std::endl;
//        return 1;
//    }
    //Final test
    WarGame warGame(5);
    warGame.playGame();
    return 0;
}
