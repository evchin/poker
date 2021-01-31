#include "CardHand.h"

CardHand::CardHand()
{
    hand = {};
}

CardHand::CardHand(const CardHand& a)
{
    hand = a.hand;
}

vector<Card> CardHand::getHand()
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

int CardHand::getSize()
{
    return hand.size();
}

void CardHand::addCard(Card c)
{
    hand.push_back(c);
}

ostream& operator<<(ostream& out, CardHand& hand)
{
    for (int i = 0; i < hand.getSize(); i++)
        out << i + 1 << ": " << hand.hand[i] << endl;
    return out;
}