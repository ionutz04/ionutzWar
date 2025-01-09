#ifndef WARGAME_H
#define WARGAME_H

#include "Deck.h"
#include "WarPlayer.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

class WarGame {
public:
    WarGame(int numPlayers) {
        if (numPlayers < 2) {
            throw std::invalid_argument("War game requires at least 2 players!");
        }

        Deck mainDeck;
        mainDeck.shuffle();

        for (int i = 0; i < numPlayers; ++i) {
            players_.emplace_back("Player" + std::to_string(i + 1));
        }

        WarPlayer::dealCardsCircular(mainDeck, players_);
    }

    explicit WarGame(const std::vector<WarPlayer>& players) : players_(players) {
        if (players_.size() < 2) {
            throw std::invalid_argument("War game requires at least 2 players!");
        }
    }

    const std::vector<WarPlayer> &getPlayers() const {
        return players_;
    }

    void playGame() {
        std::cout << "Welcome to the War Game Simulation!\n";
        std::cout << "====================================\n\n";

        int round = 1;
        while (playersStillInGame() > 1) {
            std::cout << "Round " << round << ":\n";
            playRound();
            ++round;
            ++moveCount_;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        announceWinner();
    }
    std::vector<WarPlayer> players_;
    int moveCount_ = 0;

    void playRound() {
        std::vector<Card> cardsInPlay;
        std::vector<WarPlayer*> roundWinners;
        Card* highestCard = nullptr;

        int playerNumber = 1;

        // Each player plays one card
        for (auto& player : players_) {
            if (player.hasCards()) {
                Card card = player.playCard();
                std::cout << "Player " << playerNumber << " plays: " << card.to_string() << "\n";
                cardsInPlay.push_back(card);

                if (!highestCard || card.getRank().get_value() > highestCard->getRank().get_value()) {
                    highestCard = &card;
                    roundWinners.clear();
                    roundWinners.push_back(&player);
                } else if (card.getRank().get_value() == highestCard->getRank().get_value()) {
                    roundWinners.push_back(&player);
                }

                ++playerNumber;
            }
        }

        if (roundWinners.size() > 1) {
            std::cout << "\nWAR! Players with tied cards:\n";
            for (const auto& winner : roundWinners) {
                std::cout << " - " << winner->getName() << " with " << highestCard->to_string() << "\n";
            }
            warScenario(roundWinners, *highestCard, cardsInPlay);
        } else {
            std::cout << "\n" << roundWinners[0]->getName() << " wins the round with: " << highestCard->to_string() << "\n";
            roundWinners[0]->collectCards(cardsInPlay);
        }

        displayPlayerStatus();
    }

    void warScenario(std::vector<WarPlayer*>& playersInWar, const Card& tieCard, std::vector<Card>& cardsInPlay) {
        int numWarCards = tieCard.getRank().get_value();

        for (auto& player : playersInWar) {
            std::cout << "\n" << player->getName() << " must put down up to " << numWarCards << " cards for WAR!\n";

            std::vector<Card> warCards;
            for (int i = 0; i < numWarCards; ++i) {
                if (player->hasCards()) {
                    Card warCard = player->playCard();
                    warCards.push_back(warCard);
                    std::cout << " - " << player->getName() << " puts down: " << warCard.to_string() << "\n";
                } else {
                    std::cout << " - " << player->getName() << " has no more cards!\n";
                    break;
                }
            }
            cardsInPlay.insert(cardsInPlay.end(), warCards.begin(), warCards.end());
        }

        determineWarWinner(playersInWar, cardsInPlay);
    }

    void determineWarWinner(std::vector<WarPlayer*>& playersInWar, std::vector<Card>& cardsInPlay) {
        Card* highestWarCard = nullptr;
        WarPlayer* warWinner = nullptr;

        for (auto& player : playersInWar) {
            if (player->hasCards()) {
                Card lastCard = player->playCard();
                std::cout << player->getName() << " plays final WAR card: " << lastCard.to_string() << "\n";

                if (!highestWarCard || lastCard.getRank().get_value() > highestWarCard->getRank().get_value()) {
                    highestWarCard = &lastCard;
                    warWinner = player;
                }
            }
        }

        if (warWinner) {
            std::cout << "\n" << warWinner->getName() << " wins the WAR with: " << highestWarCard->to_string() << "\n";
            warWinner->collectCards(cardsInPlay);
        } else {
            std::cout << "No winner for this WAR! Cards remain in the pot.\n";
        }
    }

    int playersStillInGame() const {
        return std::count_if(players_.begin(), players_.end(), [](const WarPlayer& player) {
            return player.hasCards();
        });
    }

    void announceWinner() const {
        for (const auto& player : players_) {
            if (player.hasCards()) {
                std::cout << player.getName() << " is the winner of the game!\n";
                std::cout << "The game finished in " << moveCount_ << " moves.\n";
                break;
            }
        }
    }

    void displayPlayerStatus() const {
        for (const auto& player : players_) {
            std::cout << player.getName() << " has " << player.cardsCount() << " cards.\n";
        }
        std::cout << "\n";
    }
};

#endif // WARGAME_H