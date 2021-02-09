#ifndef CARD_CARDHAND_H
#define CARD_CARDHAND_H

#include "PlayingCard.h"
#include <vector>

class CardHand
{
public:
    CardHand();
    CardHand(const CardHand& a);

    vector<PlayingCard> getHand();
    int getSize() const;
    int* getRanks();
    int* getSuits();

    void addCard(PlayingCard c);
    void setRanks();
    void setSuits();
    friend ostream& operator<<(ostream& outs, const CardHand& hand);
private:
    vector<PlayingCard> hand;
    int ranks[13] = {0};
    int suits[4] = {0};
};


#endif //CARD_CARDHAND_H
