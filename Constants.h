#ifndef CARD_CONSTANTS_H
#define CARD_CONSTANTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum Suit {HEART, SPADE, DIAMOND, CLUB};
enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Constants
{
public:
    enum Action {FOLD, RAISE, BET, CALL, CHECK, NONE};
    static sf::Color green;
    static sf::Color red;
    static sf::Color blue;
    static sf::Color white;
    static sf::Color navy;
    static string suitStrings[4];
    static string suitPaths[4];
    static string rankStrings[13];
    static string actionWhenBetsEqualStrings[3];
    static string actionWhenBetsDifferStrings[3];
    static Action actionsWhenBetsEqual[3];
    static Action actionsWhenBetsDiffer[3];
    static sf::Vector2f windowSize;

    static sf::Texture avatarTexture;
    static sf::Texture dealerChipTexture;
    static sf::Texture chipsTexture;
    static sf::Texture chipTexture;
    static sf::Texture cardTexture;
    static sf::Font font;
    static sf::Font normalFont;

    static sf::Texture createTexture(string fileName);
    static sf::Font createFont(string fontName);
};

#endif //CARD_CONSTANTS_H