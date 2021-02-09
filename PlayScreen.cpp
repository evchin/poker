#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
    setBackground("images/poker-table.jpg");
    setUpText();
    setUpSprites();
    setPlayScreenButtons();
}

// TODO NOTE THAT ACE IS NOT KNOWN AS HIGH CARD YETc
void PlayScreen::playRound()
{
    stopAnimations();
    switch(gameState)
    {
        case 0:
            playChipAnimation(table.positions[table.getValidPlayerIndex(table.dealer + 1)], chips.getPosition());
            table.postSmallBlind();
            stateButton.setName("next");
            helperText.setString("Small blind is posted. \nPress next for big blind.");
            gameState++;
            break;
        case 1:
            playChipAnimation(table.positions[table.getValidPlayerIndex(table.dealer + 2)], chips.getPosition());
            table.postBigBlind();
            helperText.setString("Big blind is posted. \nPress next for the pre-flop.");
            gameState++;
            break;
        case 2:
            table.dealOneCard();
            table.dealOneCard();
            helperText.setString("Pre-flop is dealt. \nPress next for betting.");
            gameState++;
            break;
        case 3:
            conductBettingRound();
            break;
        case 4:
            helperText.setString("Dealing the flop.");
            for (int i = 0; i < 3; i++)
                table.dealOneCommunityCard();
            gameState++;
            break;
        case 5:
            conductBettingRound();
            break;
        case 6:
            helperText.setString("Dealing the turn.");
            table.dealOneCommunityCard();
            gameState++;
            break;
        case 7:
            conductBettingRound();
            break;
        case 8:
            helperText.setString("Dealing the river.");
            table.dealOneCommunityCard();
            gameState++;
            break;
        case 9:
            conductBettingRound();
            break;
        case 10:
            table.displayCards();
            table.calculateScores();
            helperText.setString("The winner is Player " + to_string(table.getWinner()) + "\nwith $" + to_string(table.getTotalBetAmount()));
            stateButton.setName("exit");
            gameState++;
            break;
        default:
            exit(0);
    }
}

void PlayScreen::conductBettingRound()
{
    table.betUntilUsersTurnOrAllBetsEqual();
    if (!table.allBetsEqual() || !table.getAllPlayersIterated())
    {
        updateActionButtons();
        displayStateButton = false;
        helperText.setString("It's your turn.");
    }
    else
    {
        helperText.setString("Betting is complete.\nPress next.");
        displayStateButton = true;
        table.resetAllPlayersIterated();
        gameState++;
    }
    if (table.checkGameOver()) gameState = 10;
}

void PlayScreen::playUserAction(Constants::Action action)
{
    table.playUserAction(action);
    playRound();
}

void PlayScreen::playChipAnimation(sf::Vector2f initial, sf::Vector2f final)
{
    chip.setPosition(initial);
    sf::Vector2f difference = final - initial;
    playingChipAnimation = true;
    chipVelocity = {difference.x * 0.01f, difference.y * 0.01f};
}

void PlayScreen::playCardAnimation(sf::Vector2f initial, sf::Vector2f final)
{
    card.setPosition(initial);
    sf::Vector2f difference = final - initial;
    playingCardAnimation = true;
    cardVelocity = {difference.x * 0.1f, difference.y * 0.1f};
}

bool PlayScreen::getStateButtonClicked(sf::Vector2i coords)
{
    return stateButton.clicked(coords);
}

Constants::Action PlayScreen::getActionButtonClicked(sf::Vector2i coords)
{
    if (table.allBetsEqual())
    {
        if (betRaiseButton.clicked(coords)) return Constants::BET;
        if (checkCallButton.clicked(coords)) return Constants::CHECK;
    }
    else
    {
        if (betRaiseButton.clicked(coords)) return Constants::RAISE;
        if (checkCallButton.clicked(coords)) return Constants::CALL;
    }
    if (foldButton.clicked(coords)) return Constants::FOLD;
    return Constants::NONE;
}

void PlayScreen::updateActionButtons()
{
    if (table.allBetsEqual())
    {
        betRaiseButton.setName(Constants::actionWhenBetsEqualStrings[0]);
        checkCallButton.setName(Constants::actionWhenBetsEqualStrings[1]);
        foldButton.setName(Constants::actionWhenBetsEqualStrings[2]);
    }
    else
    {
        betRaiseButton.setName(Constants::actionWhenBetsDifferStrings[0]);
        checkCallButton.setName(Constants::actionWhenBetsDifferStrings[1]);
        foldButton.setName(Constants::actionWhenBetsDifferStrings[2]);
    }
}

void PlayScreen::setActionButtons()
{
    int charSize = 40;
    sf::Vector2f position = {Constants::windowSize.x / 3.2f, Constants::windowSize.y - 6.25f * charSize};

    Button btn1(Constants::actionWhenBetsEqualStrings[0], position, charSize, Constants::blue, 10);
    betRaiseButton = btn1;
    position.y += 2 * charSize;

    Button btn2(Constants::actionWhenBetsEqualStrings[1], position, charSize, Constants::blue, 10);
    checkCallButton = btn2;
    position.y += 2 * charSize;

    Button btn3(Constants::actionWhenBetsEqualStrings[2], position, charSize, Constants::blue, 10);
    foldButton = btn3;
    position.y += 2 * charSize;
}

void PlayScreen::setPlayScreenButtons()
{
    setActionButtons();
    int charSize = 40;
    sf::Vector2f position = {450, Constants::windowSize.y - 100};
    Button btn("start", position, charSize, Constants::green, 10);
    stateButton = btn;
}

void PlayScreen::setUpSprites()
{
    chips.setTexture(Constants::chipsTexture);
    chip.setTexture(Constants::chipTexture);
    card.setScale(0.5, 0.5);
    card.setTexture(Constants::cardTexture);
    chip.setScale(0.1, 0.1);
    chips.setPosition({Constants::windowSize.x - 300, Constants::windowSize.y / 2.5f});
    chips.setScale(0.1f, 0.1f);
}

void PlayScreen::setUpText()
{
    helperText.setFont(Constants::normalFont);
    helperText.setString("Press start.");
    helperText.setCharacterSize(40);
    helperText.setPosition({50, Constants::windowSize.y / 2.5f});
}

void PlayScreen::updateAnimation()
{
    if (playingChipAnimation)
    {
        chip.move(chipVelocity);
        if (++animationFrame >= 100)
        {
            playingChipAnimation = false;
            animationFrame = 0;
        }
    }
    if (playingCardAnimation)
    {
        card.move(cardVelocity);
        if (++animationFrame >= 10)
        {
            playingCardAnimation = false;
            animationFrame = 0;
        }
    }
}

void PlayScreen::stopAnimations()
{
    playingCardAnimation = false;
    playingChipAnimation = false;
    animationFrame = 0;
}

void PlayScreen::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    Screen::draw(window, state);
    if (table.isUsersTurn() && !displayStateButton)
    {
        window.draw(betRaiseButton);
        window.draw(checkCallButton);
        window.draw(foldButton);
    }

    window.draw(table);
    window.draw(chips);
    window.draw(helperText);

    if (displayStateButton) window.draw(stateButton);
    if (playingChipAnimation) window.draw(chip);
    if (playingCardAnimation) window.draw(card);
}