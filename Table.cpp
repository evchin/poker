#include "Table.h"

Table::Table()
{
    deck.shuffle();

    sf::Vector2f size = {175, 250};
    sf::Vector2f position = {Constants::windowSize.x / 4, Constants::windowSize.y / 2.2f - size.y / 2};
    int padding = 20;
    setCardSlots(5, position, size, padding);

    players[0] = Player({50, 50});
    players[1] = Player({Constants::windowSize.x / 2 - 75, 50});
    players[2] = Player({Constants::windowSize.x - 200, 50});
    players[3] = Player({Constants::windowSize.x - 200, Constants::windowSize.y - 250});
    players[4] = Player({Constants::windowSize.x / 2 - 75, Constants::windowSize.y / 2}, true);
    players[5] = Player({50, Constants::windowSize.y - 250});

    for (int i = 0; i < numPlayers; i++)
        positions[i] = players[i].getAvatarPosition();

    players[0].toggleDealer();
    dealer = 0;
    turn = 3;
}

void Table::postSmallBlind()
{
    players[getValidPlayerIndex(dealer + 1)].placeBet(smallBlind);
}

void Table::postBigBlind()
{
    players[getValidPlayerIndex(dealer + 2)].placeBet(smallBlind * 2);
}

void Table::playUserAction(Constants::Action action)
{
    players[turn].callFunction(action, maxBet);
    playerHasGone[turn] = true;
    updateAllPlayersIterated();
    updateMaxBet();
    updateTurn();
}

void Table::betUntilUsersTurnOrAllBetsEqual()
{
    while (user != turn && (!allBetsEqual() || !allPlayersIterated))
    {
        if (players[turn].getBet() == maxBet) players[turn].conductAIAction(Constants::actionsWhenBetsEqual, maxBet);
        else players[turn].conductAIAction(Constants::actionsWhenBetsDiffer, maxBet);
        playerHasGone[turn] = true;
        updateAllPlayersIterated();
        updateMaxBet();
        updateTurn();
    }
}

bool Table::getAllPlayersIterated()
{
    return allPlayersIterated;
}

void Table::displayCards()
{
    for (int i = 0; i < numPlayers; i++)
        players[i].setShowSlots(true);
}

void Table::updateAllPlayersIterated()
{
    for (int i = 0; i < numPlayers; i++)
        if (!playerHasGone[i]) return;
    allPlayersIterated = true;
}

void Table::resetAllPlayersIterated()
{
    allPlayersIterated = false;
    for (int i = 0; i < numPlayers; i++)
    {
        playerHasGone[i] = false;
        if (players[i].hasFolded()) playerHasGone[i] = true;
    }
}

void Table::updateTurn()
{
    turn = getValidPlayerIndex(turn + 1);
    while (players[turn].hasFolded())
        turn = getValidPlayerIndex(turn + 1);
}

void Table::updateMaxBet()
{
    for (int i = 0; i < numPlayers; i++)
        if (maxBet < players[i].getBet()) maxBet = players[i].getBet();
}

bool Table::allBetsEqual()
{
    for (int i = 0; i < numPlayers; i++)
    {
        if (!players[i].hasFolded())
            if (players[i].getBet() != maxBet)
                return false;
    }
    return true;
}

void Table::dealOneCard()
{
    for (int i = 0; i < numPlayers; i++)
        players[i].deal(deck.dealCard());
}

void Table::dealOneCommunityCard()
{
    cardSlots[cardSlotIndex++].fill(deck.dealCard());
}

int Table::getValidPlayerIndex(int i) const
{
    while (i < 0) i += numPlayers;
    return i % numPlayers;
}

bool Table::isUsersTurn() const
{
    return turn == user;
}

void Table::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for (int i = 0; i < numPlayers; i++)
        window.draw(players[i]);

    for (int i = 0; i < 5; i++)
        window.draw(cardSlots[i]);
}

void Table::setCardSlots(int numSlots, sf::Vector2f position, sf::Vector2f size, int padding)
{
    for (int i = 0; i < numSlots; i++)
    {
        CardSlot slot(position, size);
        cardSlots[i] = slot;
        position.x += size.x + padding;
    }
}

void Table::calculateScores()
{
    for (int i = 0; i < numPlayers; i++)
        players[i].calculateScore(cardSlots);
}

int Table::getWinner()
{
    int officialScores[6] = {0};
    int max = -1;
    int maxIndex = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        officialScores[i] = players[i].getScore().getOfficialScore();
        if (officialScores[i] > max)
        {
            max = officialScores[i];
            maxIndex = i;
        }
    }

    int sameScores[6] = {0};
    int sameScoresSize = 0;
    for (int i = 0; i < numPlayers; i++)
        if (officialScores[i] == max) sameScores[sameScoresSize++] = i;

    if (sameScoresSize > 1)
    {
        int playerWithGreatestScore = -1;
        for (int i = 0; i < sameScoresSize; i++)
        {
            if (players[sameScores[i]].getScore().getHighCard() > players[playerWithGreatestScore].getScore().getHighCard())
                playerWithGreatestScore = sameScores[i];
        }
        return playerWithGreatestScore;
    }
    return maxIndex;
}

bool Table::checkGameOver()
{
    int numFolded = 0;
    for (int i = 0; i < numPlayers; i++)
        if (players[i].hasFolded()) numFolded++;
    return numFolded >= 5;
}

int Table::getTotalBetAmount()
{
    int amount = 0;
    for (int i = 0; i < numPlayers; i++)
        amount += players[i].getBet();
    return amount;
}