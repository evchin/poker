#ifndef CARD_CARDHAND_H
#define CARD_CARDHAND_H

#include "Card.h"
#include <vector>

class CardHand
{
public:
    CardHand();
    CardHand(const CardHand& a);

    vector<Card> getHand();
    int getSize();
    int* getRanks();
    int* getSuits();

    void addCard(Card c);
    friend ostream& operator<<(ostream& out, CardHand& hand);
    void setRanks();
    void setSuits();
private:
    vector<Card> hand;
    int ranks[13] = {0};
    int suits[4] = {0};
};


#endif //CARD_CARDHAND_H
