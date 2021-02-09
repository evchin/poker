#ifndef CARD_DECK_H
#define CARD_DECK_H

#include "PlayingCard.h"
#include "Stack.h"

class Deck
{
public:
    Deck();
    void shuffle();
    PlayingCard dealCard();

private:
    Stack<PlayingCard> stack;
    PlayingCard deck[52];
    const int DECK_SIZE = 52;
};

#endif //CARD_DECK_H