#ifndef CARD_TABLE_H
#define CARD_TABLE_H

#include "Player.h"
#include "Deck.h"

class Table : public sf::Drawable
{
public:
    Table();

    void postSmallBlind();
    void postBigBlind();
    void dealOneCard();
    void betUntilUsersTurnOrAllBetsEqual();     // returns true if all bets equal, false if users turn
    bool allBetsEqual();
    void updateMaxBet();
    void playUserAction(Constants::Action action);
    void updateTurn();
    void setCardSlots(int numSlots, sf::Vector2f position, sf::Vector2f size, int padding);
    bool isUsersTurn() const;
    void dealOneCommunityCard();
    void updateAllPlayersIterated();
    void resetAllPlayersIterated();
    bool getAllPlayersIterated();
    void displayCards();
    void calculateScores();
    int getWinner();
    int getTotalBetAmount();
    bool checkGameOver();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    int getValidPlayerIndex(int i) const;

    sf::Vector2f positions[6];
    int dealer;
    const int user = 4;
    int turn;
private:
    Player players[6];
    bool playerHasGone[6] = {false};
    CardSlot cardSlots[5];
    Deck deck;
    int maxBet = 2;
    const int numPlayers = 6;
    int smallBlind = 1;
    int cardSlotIndex = 0;
    bool allPlayersIterated = false;
};


#endif //CARD_TABLE_H
