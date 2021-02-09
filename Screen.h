#ifndef CARD_SCREEN_H
#define CARD_SCREEN_H

#include "Button.h"
#include "Constants.h"
#include "DoublyLinkedList.h"
#include "CardSlot.h"

class Screen : public sf::Drawable, public sf::Transformable
{
public:
    Screen();

    void setSplashScreen();
    void setMenu();

    string getButtonClicked(sf::Vector2i coords);
    void setBackground(string fileName);
    void setTitle(string _title);
    void addText(string text, int charSize);
    void addText(string text, int charSize, sf::Vector2f position);
    void addButton(string text, int charSize, sf::Vector2f position, sf::Color color);
    void addButton(string text, int charSize, sf::Vector2f position, sf::Color color, int padding);
    void drawAllButButtons(sf::RenderTarget &window) const;
    void drawButtons(sf::RenderTarget &window) const;
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Text title;

    DoublyLinkedList<sf::Text> textboxes;
    DoublyLinkedList<Button> buttons;
};


#endif //CARD_SCREEN_H
