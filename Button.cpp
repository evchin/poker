#include "Button.h"

Button::Button() {}

Button::Button(string text, sf::Vector2f position, int charSize, sf::Color color) :
        Button(text, position, charSize, color, 30) {}

Button::Button(string text, sf::Vector2f position, int charSize, sf::Color color, int padding)
{
    this->padding = padding;
    name.setFont(Constants::font);
    name.setString(text);
    name.setPosition(position.x + padding, position.y + padding / 2.5f);
    name.setCharacterSize(charSize);
    name.setLetterSpacing(5);

    sf::FloatRect bounds = name.getLocalBounds();
    box.setSize({bounds.width + 2 * padding, bounds.height + 2 * padding});
    box.setPosition(position);
    box.setFillColor(color);
}

void Button::setName(string text)
{
    name.setString(text);
    sf::FloatRect bounds = name.getLocalBounds();
    box.setSize({bounds.width + 2 * padding, bounds.height + 2 * padding});
}

string Button::getName()
{
    return name.getString();
}

bool Button::clicked(sf::Vector2i coords)
{
    return box.getGlobalBounds().contains(coords.x, coords.y);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(box);
    window.draw(name);
}

ostream& operator <<(ostream& outs, const Button& btn)
{
    string a = btn.name.getString();
    outs << a;
    return outs;
}