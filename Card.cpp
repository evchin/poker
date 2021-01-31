#include "Card.h"

Card::Card() : suit(HEART), rank(ACE) {}

Card::Card(Suit s, Rank r)
{
    suit = s;
    rank = r;
}

Card::Card(const Card& c)
{
    suit = c.suit;
    rank = c.rank;
}

void Card::setSuit(Suit suit)
{
    this->suit = suit;
}
void Card::setRank(Rank rank)
{
    this->rank = rank;
}
Suit Card::getSuit()
{
    return suit;
}
Rank Card::getRank()
{
    return rank;
}
ostream& operator<<(ostream& outs, const Card& card)
{
    outs << Constants::rankStrings[card.rank] << " of ";
    outs << Constants::suitStrings[card.suit] << "s";
    return outs;
}