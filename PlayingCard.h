#ifndef CARD_PLAYINGCARD_H
#define CARD_PLAYINGCARD_H

#include "Card.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace std;

class PlayingCard : public Card, public sf::Drawable, public sf::Transformable
{
    public:
        PlayingCard();
        PlayingCard(Suit s, Rank r);
        PlayingCard(Suit s, Rank r, sf::Vector2f size, sf::Vector2f position, sf::Vector2f suitScale, sf::Vector2f padding, int charSize);
        virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

        void setupTextures();
        void setupCard(Suit s, Rank r);
        void updatePosition();

        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f position);

        sf::Vector2f CARD_SIZE = {175, 250};
        sf::Vector2f SUIT_SCALE = {0.2, 0.2};
        sf::Vector2f PADDING = {20, 10};
        int CHAR_SIZE = 50;

    private:
        static sf::Texture suitTextures[4];
        static bool metaLoaded;
        sf::RectangleShape cardBackground;
        sf::Text upperRank;
        sf::Text lowerRank;
        sf::Sprite suitSprite;
};

#endif //CARD_PLAYINGCARD_H