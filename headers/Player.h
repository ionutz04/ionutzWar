#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include <string>
#include <utility>

/// Abstract class representing a generic player in a card game.
class Player {
public:
    /// Constructor: Initializes a player with a given name.
    /// @param name The name or nickname of the player.
    explicit Player(std::string  name) : name_(std::move(name)) {}

    /// Virtual destructor.
    virtual ~Player() = default;

    /// Checks if the player has any cards left.
    /// @return True if the player's deck is not empty, false otherwise.
    [[nodiscard]] virtual bool hasCards() const = 0;

    /// Plays the top card from the player's deck.
    /// @return The card that was played.
    virtual Card playCard() = 0;

    /// Collects a list of cards and adds them to the player's deck.
    /// @param cards The cards to be added to the player's deck.
    virtual void collectCards(const std::vector<Card>& cards) = 0;

    /// Gets the number of cards the player currently has.
    /// @return The size of the player's deck.
    [[nodiscard]] virtual int cardsCount() const = 0;

    virtual /// Gets the name or nickname of the player.
    /// @return The player's name.
    const std::string& getName() const {
        return name_;
    }

protected:
    std::string name_; // The name or nickname of the player.
};

#endif // PLAYER_H
