#ifndef CARD_PLAYSCREEN_H
#define CARD_PLAYSCREEN_H

#include "Screen.h"
#include "Table.h"

class PlayScreen : public Screen
{
public:
    PlayScreen();
    void playRound();
    void updateAnimation();
    bool getStateButtonClicked(sf::Vector2i coords);
    Constants::Action getActionButtonClicked(sf::Vector2i coords);
    void setActionButtons();
    void updateActionButtons();
    void conductBettingRound();
    void playUserAction(Constants::Action action);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    Table table;
    Button stateButton;
    Button betRaiseButton;
    Button checkCallButton;
    Button foldButton;
    sf::Text helperText;

    int gameState = 0;
    sf::Sprite chips;
    sf::Sprite chip;
    sf::Sprite card;

    bool playingChipAnimation = false;
    bool playingCardAnimation = false;
    sf::Vector2f chipVelocity;
    sf::Vector2f cardVelocity;
    int animationFrame = 0;
    bool displayStateButton = true;

    void setCardSlots(int numSlots, sf::Vector2f position, sf::Vector2f size, int padding);
    void setPlayScreenButtons();
    void setUpSprites();
    void setUpText();
    void playChipAnimation(sf::Vector2f initial, sf::Vector2f final);
    void playCardAnimation(sf::Vector2f initial, sf::Vector2f final);
    void stopAnimations();
};


#endif //CARD_PLAYSCREEN_H
