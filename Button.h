#ifndef CARD_BUTTON_H
#define CARD_BUTTON_H

#include "Constants.h"

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button();
    Button(string text, sf::Vector2f position, int charSize, sf::Color color);
    Button(string text, sf::Vector2f position, int charSize, sf::Color color, int padding);
    bool clicked(sf::Vector2i coords);
    void setName(string text);
    string getName();

    friend ostream& operator <<(ostream& outs, const Button& btn);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
private:
    sf::Text name;
    sf::RectangleShape box;
    int padding = 30;
};

#endif //CARD_BUTTON_H
