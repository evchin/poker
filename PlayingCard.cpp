#include "PlayingCard.h"

string suitPaths[4] = {"images/heart.png", "images/spade.png", "images/diamond.png", "images/club.png"};
string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

sf::Font PlayingCard::font = sf::Font();
sf::Texture PlayingCard::suitTextures[4];
bool PlayingCard::metaLoaded = false;

PlayingCard::PlayingCard()
{

}

PlayingCard::PlayingCard(Suit s, Rank r) : Card(s, r)
{
    if (!metaLoaded) setupTexturesAndFonts();
    setupCard(s, r);
}

PlayingCard::PlayingCard(Suit s, Rank r, sf::Vector2f size, sf::Vector2f position, sf::Vector2f suitScale, sf::Vector2f padding, int charSize)
: Card(s, r), CARD_SIZE(size), CARD_POSITION(position), SUIT_SCALE(suitScale), PADDING(padding), CHAR_SIZE(charSize)
{
    if (!metaLoaded) setupTexturesAndFonts();
    setupCard(s, r);
}

void PlayingCard::setupTexturesAndFonts()
{
    for (int i = 0; i < 4; i++)
        suitTextures[i].loadFromFile(*(suitPaths + i));
    if (!PlayingCard::font.loadFromFile("arial.ttf")) cout << "Error loading font file." << endl;
    metaLoaded = true;
}

void PlayingCard::setupCard(Suit s, Rank r)
{
    cardBackground.setSize(CARD_SIZE);
    cardBackground.setFillColor(sf::Color::White);
    updatePosition();

    suitSprite.setTexture(*(suitTextures + s));
    suitSprite.setScale(SUIT_SCALE);

    sf::Text text(*(ranks + r), PlayingCard::font);
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

void PlayingCard::bounce()
{
    if (!velocitySet)
    {
        velocity = getVelocity();
        velocitySet = true;
    }

    CARD_POSITION.x += velocity.x;
    CARD_POSITION.y += velocity.y;

    if (CARD_POSITION.x + CARD_SIZE.x > WINDOW_SIZE.x)
    {
        CARD_POSITION.x = WINDOW_SIZE.x - CARD_SIZE.x;
        velocity.x = 0-velocity.x;
    }
    else if (CARD_POSITION.x < 0)
    {
        CARD_POSITION.x = 0;
        velocity.x = 0-velocity.x;
    }

    if (CARD_POSITION.y + CARD_SIZE.y > WINDOW_SIZE.y)
    {
        CARD_POSITION.y = WINDOW_SIZE.y - CARD_SIZE.y;
        velocity.y = 0-velocity.y;
    }
    else if (CARD_POSITION.y < 0)
    {
        CARD_POSITION.y = 0;
        velocity.y = 0-velocity.y;
    }

    updatePosition();
}

sf::Vector2i PlayingCard::getVelocity()
{
    srand(time(0));
    sf::Vector2i velocity = {rand() % MAX_VELOCITY.x, rand() % MAX_VELOCITY.y};
    return velocity;
}

void PlayingCard::updatePosition()
{
    cardBackground.setPosition(CARD_POSITION);
    sf::FloatRect cardBounds = cardBackground.getGlobalBounds();
    sf::FloatRect suitBounds = suitSprite.getGlobalBounds();
    suitSprite.setPosition({cardBounds.left + cardBounds.width / 2 - suitBounds.width / 2, cardBounds.top + cardBounds.height / 2 - suitBounds.height / 2});
    upperRank.setPosition({cardBounds.left + PADDING.x, cardBounds.top + PADDING.y});
    lowerRank.setPosition({cardBounds.left + cardBounds.width - PADDING.x, cardBounds.top + cardBounds.height - PADDING.y});
}