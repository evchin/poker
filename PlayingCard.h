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

        void setupTexturesAndFonts();
        void setupCard(Suit s, Rank r);
        void bounce();
        void updatePosition();
        sf::Vector2i getVelocity();

        sf::Vector2f WINDOW_SIZE = {1920, 1080};
        sf::Vector2f CARD_SIZE = {700, 1000};
        sf::Vector2f CARD_POSITION = {WINDOW_SIZE.x/2 - CARD_SIZE.x/2, WINDOW_SIZE.y/2 - CARD_SIZE.y/2};
        sf::Vector2f SUIT_SCALE = {0.1, 0.1};
        sf::Vector2f PADDING = {40, 20};
        sf::Vector2i MAX_VELOCITY = {10, 10};
        int CHAR_SIZE = 100;

    private:
        static sf::Font font;
        static sf::Texture suitTextures[4];
        static bool metaLoaded;
        sf::RectangleShape cardBackground;
        sf::Text upperRank;
        sf::Text lowerRank;
        sf::Sprite suitSprite;
        sf::Vector2i velocity;
        bool velocitySet = false;
};

#endif //CARD_PLAYINGCARD_H