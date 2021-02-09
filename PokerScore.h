#ifndef CARD_POKERSCORE_H
#define CARD_POKERSCORE_H

#include "CardHand.h"

class PokerScore
{
public:
    PokerScore();
    enum Score{
        HIGH_CARD,          // highest card in the player’s hand
        ONE_PAIR,           // two cards of the same rank
        TWO_PAIR,           // two cards of the same rank along with another two cards of the same rank
        THREE_OF_A_KIND,    // three cards of the same rank
        STRAIGHT,           // five cards in consecutive ranking
        FLUSH,              // five cards of the same suit
        FULL_HOUSE,         // three cards of the same rank along with two cards of the same rank
        FOUR_OF_A_KIND,     // four cards of the same ranking
        STRAIGHT_FLUSH,     // five cards of the same suit and consecutive ranking
        ROYAL_FLUSH         // A, K, Q, J, 10, all the same suit.
    };
    string scoreStrings[10] = {"High Card", "One Pair", "Two Pair", "Three of a Kind", "Straight",
                               "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};

    vector<Score> getScores();
    void setOfficialScore(int a);
    void setHighCard(int a);
    int getOfficialScore();
    int getHighCard();

    int size();
    void operator+=(const Score& score);
    friend bool operator==(const PokerScore& p, Score score);
    friend ostream& operator<<(ostream& out, const PokerScore& score);
    Score& operator[](unsigned int index);

private:
    vector<Score> scores = {};
    int officialScore = 0;
    int highCard = 0;
};

#endif //CARD_POKERSCORE_H