#include "PlayingCard.h"

string ranks[13] = {"a", "2", "3", "4", "5", "6", "7", "8", "9", "10", "j", "q", "k"};

sf::Texture PlayingCard::suitTextures[4];
bool PlayingCard::metaLoaded = false;

PlayingCard::PlayingCard(){}

PlayingCard::PlayingCard(Suit s, Rank r) : Card(s, r)
{
    if (!metaLoaded) setupTextures();
    setupCard(s, r);
}

PlayingCard::PlayingCard(Suit s, Rank r, sf::Vector2f size, sf::Vector2f position, sf::Vector2f suitScale, sf::Vector2f padding, int charSize)
: Card(s, r), CARD_SIZE(size), SUIT_SCALE(suitScale), PADDING(padding), CHAR_SIZE(charSize)
{
    if (!metaLoaded) setupTextures();
    setupCard(s, r);
}

void PlayingCard::setupTextures()
{
    for (int i = 0; i < 4; i++)
        suitTextures[i].loadFromFile(*(Constants::suitPaths + i));
    metaLoaded = true;
}

void PlayingCard::setSize(sf::Vector2f size)
{
    cardBackground.setSize(size);
    updatePosition();
}

void PlayingCard::setPosition(sf::Vector2f position)
{
    cardBackground.setPosition(position);
    updatePosition();
}

void PlayingCard::setupCard(Suit s, Rank r)
{
    cardBackground.setSize(CARD_SIZE);
    cardBackground.setFillColor(Constants::white);
    updatePosition();

    suitSprite.setTexture(*(suitTextures + s));
    suitSprite.setScale(SUIT_SCALE);

    sf::Text text(*(ranks + r), Constants::font);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(CHAR_SIZE);
    if (s == HEART || s == DIAMOND) text.setFillColor(sf::Color::Red);
    else text.setFillColor(sf::Color::Black);

    upperRank = text;
    lowerRank = text;
    lowerRank.setRotation(180);
}

void PlayingCard::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(cardBackground);
    window.draw(upperRank);
    window.draw(lowerRank);
    window.draw(suitSprite);
}

void PlayingCard::updatePosition()
{
    sf::FloatRect cardBounds = cardBackground.getGlobalBounds();
    sf::FloatRect suitBounds = suitSprite.getGlobalBounds();
    suitSprite.setPosition({cardBounds.left + cardBounds.width / 2 - suitBounds.width / 2, cardBounds.top + cardBounds.height / 2 - suitBounds.height / 2});
    upperRank.setPosition({cardBounds.left + PADDING.x, cardBounds.top + PADDING.y});
    lowerRank.setPosition({cardBounds.left + cardBounds.width - PADDING.x, cardBounds.top + cardBounds.height - PADDING.y});
}