#include "PlayingCard.h"
//#include "CardGrid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Card Demo");
    window.setFramerateLimit(60);

//    CardGrid grid(3, 5);
//    PlayingCard card(Card::HEART, Card::ACE);
    sf::Vector2f size = {150, 215};
    sf::Vector2f position = {0, 0};
    sf::Vector2f suitScale = {0.2, 0.2};
    sf::Vector2f padding = {20, 10};
    int charSize = 25;

    PlayingCard card(Card::HEART, Card::ACE, size, position, suitScale, padding, charSize);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        card.bounce();
        window.draw(card);
        window.display();
    }
}