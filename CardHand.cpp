#include "CardHand.h"

CardHand::CardHand()
{
    hand = {};
}

CardHand::CardHand(const CardHand& a)
{
    hand = a.hand;
}

vector<PlayingCard> CardHand::getHand()
{
    return hand;
}

int* CardHand::getRanks()
{
    setRanks();
    return ranks;
}

int* CardHand::getSuits()
{
    setSuits();
    return suits;
}

void CardHand::setRanks()
{
    for (int i = 0; i < hand.size(); i++)
        ranks[hand[i].getRank()]++;
}

void CardHand::setSuits()
{
    for (int i = 0; i < hand.size(); i++)
        suits[hand[i].getSuit()]++;
}

int CardHand::getSize() const
{
    return hand.size();
}

void CardHand::addCard(PlayingCard c)
{
    hand.push_back(c);
}

ostream& operator<<(ostream& outs, const CardHand& hand)
{
    for (int i = 0; i < hand.getSize(); i++)
        outs << i + 1 << ": " << hand.hand[i] << endl;
    return outs;
}