#include "Player.h"

Player::Player() : Player({0, 0}) {}

Player::Player(sf::Vector2f position) : Player(position, false) {}

Player::Player(sf::Vector2f position, bool user)
{
    this->user = user;
    this->position = position;
    money = 100;
    betAmount = 0;
    setUpSprites();
    setUpText();
    setUpSlots();
}

void Player::toggleDealer()
{
    dealer = !dealer;
}

void Player::toggleUser()
{
    user = !user;
}

bool Player::hasFolded()
{
    return folded;
}

int Player::getBet()
{
    return betAmount;
}

void Player::placeBet(int amount)
{
    if (amount > money) return;
    money -= amount;
    betAmount += amount;
    updateText();
}

void Player::deal(PlayingCard card)
{
    hand.addCard(card);
    slots[slot++].fill(card);
}

void Player::resetActionDisplay()
{
    displayAction = false;
    actionDisplay.setString("");
}

void Player::conductAIAction(Constants::Action validActions[3], int maxBet)
{
    int i = rand() % 100;
    if (i < 5) callFunction(validActions[0], maxBet);
    else if (i < 80) callFunction(validActions[1], maxBet);
    else callFunction(validActions[2], maxBet);
}

// TODO: note limited raise and bet
void Player::callFunction(Constants::Action action, int maxBet)
{
    displayAction = true;
    switch(action)
    {
        case Constants::BET: bet(maxBet); break;
        case Constants::RAISE: raise(maxBet); break;
        case Constants::CHECK: check(); break;
        case Constants::CALL: call(maxBet); break;
        case Constants::FOLD: fold(); break;
        default: break;
    }
    updateText();
}

void Player::bet(int maxBet)
{
    actionDisplay.setString("bet");
    if (money + betAmount < maxBet)
        fold();
    else if (money + betAmount == maxBet)
        check();
    else
    {
        int contribution = maxBet - betAmount + 1;
        money -= contribution;
        betAmount += contribution;
    }
}
void Player::raise(int maxBet)
{
    actionDisplay.setString("raise");
    if (money + betAmount < maxBet)
        fold();
    else if (money + betAmount == maxBet)
        check();
    else
    {
        int contribution = maxBet - betAmount + 1;
        money -= contribution;
        betAmount += contribution;
    }
}
void Player::check()
{
    actionDisplay.setString("check");
}
void Player::call(int maxBet)
{
    actionDisplay.setString("call");
    if (money + betAmount < maxBet)
        fold();
    else if (money + betAmount == maxBet)
    {
        money = 0;
        betAmount = maxBet;
    }
    else
    {
        int contribution = maxBet - betAmount;
        money -= contribution;
        betAmount += contribution;
    }
}
void Player::fold()
{
    actionDisplay.setString("fold");
    folded = true;
}

CardHand Player::getHand()
{
    return hand;
}

void Player::setShowSlots(bool b)
{
    showSlots = b;
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if (user)
    {
         window.draw(moneyDisplay);
         for (int i = 0; i < 2; i++)
             window.draw(slots[i]);
    }
    else
    {
        window.draw(avatar);
        if (displayAction) window.draw(actionDisplay);
        if (dealer) window.draw(dealerChip);
    }
    window.draw(betDisplay);
    if (showSlots && !folded)
        for (int i = 0; i < 2; i++)
            window.draw(slots[i]);
}

void Player::setUpSprites()
{
    avatar.setTexture(Constants::avatarTexture);
    dealerChip.setTexture(Constants::dealerChipTexture);
    avatar.setPosition(position);
    dealerChip.setPosition({position.x + 100, position.y + 100});
    avatar.setScale({0.6, 0.6});
    dealerChip.setScale({0.1, 0.1});
}

void Player::setUpSlots()
{
    int padding = 20;
    sf::Vector2f size = {175, 250};
    sf::Vector2f position = {Constants::windowSize.x / 2 - size.x - padding, Constants::windowSize.y - size.y - padding};

    if (user)
    {
        for (int i = 0; i < 2; i++)
        {
            CardSlot slot(position, size);
            slots[i] = slot;
            position.x += size.x + padding;
        }
    }
    else
    {
        position = getAvatarPosition();
        if (Constants::windowSize.x < position.x + 2 * size.x + 2 * padding) position.x = Constants::windowSize.x - 2 * size.x - 4 * padding;
        if (Constants::windowSize.y < position.y + size.y + 2 * padding) position.y = Constants::windowSize.y - size.y - 2 * padding;
        for (int i = 0; i < 2; i++)
        {
            CardSlot slot(position, size);
            slots[i] = slot;
            position.x += size.x + padding;
        }
    }
}

void Player::setUpText()
{
    moneyDisplay.setFont(Constants::font);
    moneyDisplay.setString("money: $ " + to_string(money));
    moneyDisplay.setPosition({Constants::windowSize.x / 1.6f, Constants::windowSize.y - 100});
    moneyDisplay.setCharacterSize(40);

    actionDisplay.setFont(Constants::font);
    actionDisplay.setCharacterSize(40);
    actionDisplay.setFillColor(Constants::white);

    betDisplay.setFont(Constants::font);
    betDisplay.setString("bet: $" + to_string(betAmount));
    betDisplay.setCharacterSize(40);

    int padding = 30;
    sf::FloatRect avatarBounds = avatar.getGlobalBounds();
    betDisplay.setPosition({avatarBounds.left, avatarBounds.top + avatarBounds.height + padding});
    actionDisplay.setPosition({avatarBounds.left, avatarBounds.top});
}

void Player::updateText()
{
    moneyDisplay.setString("money: $ " + to_string(money));
    betDisplay.setString("bet: $" + to_string(betAmount));
}

sf::Vector2f Player::getAvatarPosition()
{
    return position;
}

void Player::calculateScore(CardSlot communityCards[5])
{
    CardHand temp(hand);
    if (folded)
    {
        score.setOfficialScore(0);
        score.setHighCard(0);
    }
    else
    {
        for (int i = 0; i < 5; i++)
            temp.addCard(communityCards[i].getCard());
        score = CardHandScorer::scorePokerHand(temp);
    }
}

PokerScore Player::getScore()
{
    return score;
}