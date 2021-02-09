#include "Screen.h"

Screen::Screen(){}

void Screen::setMenu()
{
    setBackground("images/splash-screen.jpg");
    setTitle("POKER");

    int charSize = 100;
    sf::Vector2f position = {Constants::windowSize.x / 1.3f, Constants::windowSize.y / 2};
    addButton("play", charSize, position, Constants::green);
    addButton("quit", charSize, {position.x, position.y + charSize * 2}, Constants::red);
}

void Screen::setSplashScreen()
{
    setBackground("images/splash-screen.jpg");
    setTitle("POKER");

    int charSize = 50;
    addText("evelyn chin", charSize);
    addText("cs 03A", charSize);
    addText("crn: 11703", charSize);
    addText("winter 2021", charSize);
}

string Screen::getButtonClicked(sf::Vector2i coords)
{
    int size = buttons.size();
    for (int i = 0; i < size; i++)
    {
        Button b = buttons.getAt(i);
        if (b.clicked(coords))
            return b.getName();
    }
    return "none";
}

void Screen::setBackground(string fileName)
{
    background.setPosition(0, 0);
    backgroundTexture.loadFromFile(fileName);
    background.setTexture(&backgroundTexture);
    background.setSize(Constants::windowSize);
}

void Screen::setTitle(string _title)
{
    title.setString(_title);
    title.setFont(Constants::font);
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(150);
    sf::FloatRect bounds = title.getLocalBounds();
    title.setPosition(Constants::windowSize.x / 5 - bounds.width/2,
                      Constants::windowSize.y / 5 - bounds.height/2);
}

void Screen::addText(string text, int charSize)
{
    sf::Vector2f position;
    if (textboxes.empty())
        position = {Constants::windowSize.x / 1.5f, Constants::windowSize.y / 1.5f};
    else
    {
        sf::FloatRect prevBounds = textboxes.getTail().getGlobalBounds();
        int padding = 25;
        position = {prevBounds.left, prevBounds.top + prevBounds.height / 2 + padding};
    }
    addText(text, charSize, position);
}

void Screen::addText(string text, int charSize, sf::Vector2f position)
{
    sf::Text textbox(text, Constants::font, charSize);
    textbox.setPosition(position);
    textbox.setLetterSpacing(3);
    textboxes.append(textbox);
}

void Screen::addButton(string text, int charSize, sf::Vector2f position, sf::Color color)
{
    Button btn(text, position, charSize, color);
    buttons.append(btn);
}

void Screen::addButton(string text, int charSize, sf::Vector2f position, sf::Color color, int padding)
{
    Button btn(text, position, charSize, color, padding);
    buttons.append(btn);
}

void Screen::drawAllButButtons(sf::RenderTarget &window) const
{
    window.draw(background);
    window.draw(title);

    int textboxesSize = textboxes.size();
    for (int i = 0; i < textboxesSize; i++)
        window.draw(textboxes.getAt(i));
}

void Screen::drawButtons(sf::RenderTarget &window) const
{
    int buttonsSize = buttons.size();
    for (int i = 0; i < buttonsSize; i++)
        window.draw(buttons.getAt(i));
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    drawAllButButtons(window);
    drawButtons(window);
}