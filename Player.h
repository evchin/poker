#ifndef CARD_PLAYER_H
#define CARD_PLAYER_H

#include<windows.h>
#include "Constants.h"
#include "CardHandScorer.h"
#include "PokerScore.h"
#include "CardSlot.h"

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    Player(sf::Vector2f position);
    Player(sf::Vector2f position, bool user);

    void placeBet(int amount);
    void deal(PlayingCard card);
    bool hasFolded();
    int getBet();
    CardHand getHand();
    void conductAIAction(Constants::Action validActions[3], int maxBet);
    void callFunction(Constants::Action action, int maxBet);
    void resetActionDisplay();
    void setShowSlots(bool b);
    void calculateScore(CardSlot communityCards[5]);
    PokerScore getScore();

    void bet(int maxBet);
    void raise(int maxBet);
    void check();
    void call(int maxBet);
    void fold();

    void toggleDealer();
    void toggleUser();
    sf::Vector2f getAvatarPosition();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    CardHand hand;
    PokerScore score;
    int money;
    int betAmount;
    bool user = false;
    bool dealer = false;
    bool folded = false;
    bool displayAction = false;
    bool showSlots = false;

    sf::Vector2f position;
    sf::Sprite avatar;
    sf::Sprite dealerChip;
    sf::Text betDisplay;
    sf::Text moneyDisplay;
    sf::Text actionDisplay;
    CardSlot slots[2];

    int slot = 0;

    void setUpSprites();
    void setUpText();
    void setUpSlots();
    void updateText();
};

#endif //CARD_PLAYER_H
