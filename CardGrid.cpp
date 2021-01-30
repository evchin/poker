#include "CardGrid.h"

CardGrid::CardGrid(){}
CardGrid::CardGrid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    srand(time(0));
    grid = new PlayingCard*[rows];

    sf::Vector2f cardSize, windowSize, padding, suitScale;
    windowSize = {1920, 1080};
    padding = {20, 20};
    suitScale = {0.2, 0.2};
    int charSize = 50;

    cardSize.y = windowSize.y / rows - padding.y * (rows + 1);
    cardSize.x = 0.7 * cardSize.y;

    for (int i = 0; i < rows; i++)
    {
        *(grid + i) = new PlayingCard[cols];
        for (int j = 0; j < cols; j++)
        {
            int suit = rand() % 4;
            int rank = rand() % 13;
            sf::Vector2f position;
            position.x = padding.x + (cardSize.x * j) + padding.x * j;
            position.y = padding.y + (cardSize.y * i) + padding.y * i;
            *(*(grid + i) + j) = PlayingCard(Card::Suit(suit), Card::Rank(rank), cardSize, position, suitScale, padding, charSize);
        }
    }
}
void CardGrid::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            window.draw((*(*(grid + i) + j)));
        }
    }
}