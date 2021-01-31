#ifndef CARD_POKERSCORE_H
#define CARD_POKERSCORE_H

#include "CardHand.h"

class PokerScore
{
public:
    PokerScore();
    enum Score{
        ROYAL_FLUSH,        // A, K, Q, J, 10, all the same suit.
        STRAIGHT_FLUSH,     // five cards of the same suit and consecutive ranking
        FOUR_OF_A_KIND,     // four cards of the same ranking
        FULL_HOUSE,         // three cards of the same rank along with two cards of the same rank
        FLUSH,              // five cards of the same suit
        STRAIGHT,           // five cards in consecutive ranking
        THREE_OF_A_KIND,    // three cards of the same rank
        TWO_PAIR,           // two cards of the same rank along with another two cards of the same rank
        ONE_PAIR,           // two cards of the same rank
        HIGH_CARD           // highest card in the player’s hand
    };
    string scoreStrings[10] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush",
        "Straight", "Three of a Kind", "Two Pair", "One Pair", "High Card"};

    int size();
    void operator+=(const Score& score);
    friend bool operator==(const PokerScore& p, Score score);
    friend ostream& operator<<(ostream& out, const PokerScore& score);
    Score& operator[](unsigned int index);

private:
    vector<Score> scores = {};
};

#endif //CARD_POKERSCORE_H
