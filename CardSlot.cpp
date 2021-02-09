#include "CardSlot.h"

CardSlot::CardSlot() : CardSlot({0, 0}, {70, 100}) {}

CardSlot::CardSlot(sf::Vector2f position, sf::Vector2f size)
{
    slot.setPosition(position);
    slot.setSize(size);
    slot.setFillColor(Constants::navy);
}

PlayingCard CardSlot::getCard()
{
    return card;
}

void CardSlot::fill(PlayingCard card)
{
    filled = true;
    this->card = card;
    this->card.setPosition(slot.getPosition());
}

void CardSlot::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(slot);
    if (filled) window.draw(card);
}