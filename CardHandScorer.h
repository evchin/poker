#ifndef CARD_CARDHANDSCORER_H
#define CARD_CARDHANDSCORER_H

#include "PokerScore.h"

class CardHandScorer
{
public:
    CardHandScorer();
    static PokerScore scorePokerHand(CardHand hand);
    static int calculateOfficialScore(PokerScore score);
    static int calculateHighCard(CardHand hand);
private:
    static bool royalFlush(CardHand h);          // returns true if royal flush
    static bool fullHouse(CardHand h);           // returns true if full house
    static bool twoPair(CardHand h);             // returns true if hand has two pairs

    static int sameRank(CardHand h);             // returns highest number of cards with same rank
    static int sameSuit(CardHand h);             // returns highest number of cards with same suit
    static int consecutive(CardHand h);          // returns highest number of consecutive ranking

    static int getMax(int arr[], int size);      // returns maximum number in array of length size
};

#endif //CARD_CARDHANDSCORER_H
