#ifndef CARD_CARD_H
#define CARD_CARD_H


#include <iostream>
using namespace std;

class Card
{
public:
    enum Suit {HEART, SPADE, DIAMOND, CLUB};
    enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Card();
    Card(Suit s, Rank r);
    void setSuit(Suit suit);
    void setRank(Rank rank);
    string getSuit();
    string getRank();
    friend ostream& operator<<(ostream& out, const Card& card);

private:
    Suit suit;
    Rank rank;
};

#endif //CARD_CARD_H
