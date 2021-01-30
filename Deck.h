#ifndef CARD_DECK_H
#define CARD_DECK_H

#include "Card.h"

class Deck
{
public:
    Deck(); // this is the constructor
    bool empty(); //returns true if deck has no cards
    void shuffle(); // puts cards in random order
    Card getCardAt(int index);// gets the Card at the given index
    Card dealCard(); // returns the next card in the deck
    friend ostream& operator<<(ostream& out, const Deck& deck); // prints all the cards to the console
private:
    Card deck[52];// this is your final deck of cards
    const int DECK_SIZE = 52;// this is the size of your deck
    int cardIndex; //marks the index of the next card in the deck
};

#endif //CARD_DECK_H
