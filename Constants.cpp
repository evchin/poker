#include "Constants.h"

sf::Color Constants::green = sf::Color(119, 178, 140);
sf::Color Constants::red = sf::Color(242, 97, 87);
sf::Color Constants::blue = sf::Color(73, 106, 129);
sf::Color Constants::white = sf::Color(223, 217, 226);
sf::Color Constants::navy = sf::Color(43, 58, 103);

string Constants::suitStrings[4] = {"Heart", "Spade", "Diamond", "Club"};
string Constants::suitPaths[4] = {"images/heart.png", "images/spade.png", "images/diamond.png", "images/club.png"};
string Constants::rankStrings[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string Constants::actionWhenBetsEqualStrings[3] = {"bet", "check", "fold"};
string Constants::actionWhenBetsDifferStrings[3] = {"raise", "call", "fold"};
Constants::Action Constants::actionsWhenBetsEqual[3] = {Constants::BET, Constants::CHECK, Constants::FOLD};
Constants::Action Constants::actionsWhenBetsDiffer[3] = {Constants::RAISE, Constants::CALL, Constants::FOLD};
sf::Vector2f Constants::windowSize = {1920, 1080};

sf::Texture Constants::avatarTexture(createTexture("images/avatar.png"));
sf::Texture Constants::dealerChipTexture(createTexture("images/dealer-chip.png"));
sf::Texture Constants::chipTexture(createTexture("images/chip.png"));
sf::Texture Constants::chipsTexture(createTexture("images/chips.png"));
sf::Texture Constants::cardTexture(createTexture("images/card-back.png"));
sf::Font Constants::font(createFont("Andes.ttf"));
sf::Font Constants::normalFont(createFont("OpenSans.ttf"));


sf::Texture Constants::createTexture(string fileName)
{
    sf::Texture texture;
    texture.loadFromFile(fileName);
    return texture;
}

sf::Font Constants::createFont(string fontName)
{
    sf::Font font;
    font.loadFromFile(fontName);
    return font;
}