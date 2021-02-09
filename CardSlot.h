#ifndef CARD_CARDSLOT_H
#define CARD_CARDSLOT_H

#include "PlayingCard.h"

class CardSlot : public sf::Drawable, public sf::Transformable
{
public:
    CardSlot();
    CardSlot(sf::Vector2f position, sf::Vector2f size);
    PlayingCard getCard();
    void fill(PlayingCard card);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    PlayingCard card;
    sf::RectangleShape slot;
    bool filled = false;
};

#endif //CARD_CARDSLOT_H