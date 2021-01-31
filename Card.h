#ifndef CARD_CARD_H
#define CARD_CARD_H

#include "Constants.h"

class Card
{
public:
    Card();
    Card(Suit s, Rank r);
    Card(const Card& c);

    void setSuit(Suit suit);
    void setRank(Rank rank);
    Suit getSuit();
    Rank getRank();

    friend ostream& operator<<(ostream& outs, const Card& card);

private:
    Suit suit;
    Rank rank;
};

#endif //CARD_CARD_H
