#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
//#include "PlayingCard.h"
//#include "CardGrid.h"

#include <cstdlib>
#include <ctime>

PokerScore analyze();

int main()
{
    srand(time(nullptr));

    int scores[10] = {0};
    for (int i = 0; i < 1000; i++)
    {
        PokerScore s = analyze();
        for (int j = 0; j < s.size(); j++)
            scores[s[j]]++;
    }

    string scoreStrings[10] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush",
                               "Straight", "Three of a Kind", "Two Pair", "One Pair", "High Card"};

    for (int i = 0; i < 10; i++)
        cout << scoreStrings[i] << ": " << scores[i] << endl;

//// SFML STUFF

//    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Card Demo");
//    window.setFramerateLimit(60);
//
//    CardGrid grid(3, 5);
//    PlayingCard card(Card::HEART, Card::ACE);
//    sf::Vector2f size = {150, 215};
//    sf::Vector2f position = {0, 0};
//    sf::Vector2f suitScale = {0.2, 0.2};
//    sf::Vector2f padding = {20, 10};
//    int charSize = 25;
//
//    PlayingCard card(HEART, ACE, size, position, suitScale, padding, charSize);
//
//    while(window.isOpen())
//    {
//        sf::Event event;
//        while(window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed) window.close();
//        }
//        window.clear();
//        card.bounce();
//        window.draw(card);
//        window.display();
//    }
}

PokerScore analyze()
{
    Deck deck;
    CardHand hands[5];

    deck.shuffle();
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            hands[j].addCard(deck.dealCard());

    int index = rand() % 5;
    return CardHandScorer::scorePokerHand(hands[index]);
}