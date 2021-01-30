#include "Card.h"

Card::Card(){}

Card::Card(Suit s, Rank r)
{
    suit = s;
    rank = r;
}

void Card::setSuit(Suit suit)
{
    this->suit = suit;
}
void Card::setRank(Rank rank)
{
    
}
string Card::getSuit();
string Card::getRank();
ostream& operator<<(ostream& out, const Card& card);