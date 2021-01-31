#include "CardGrid.h"

CardGrid::CardGrid() : rows(0), cols(0)
{
    grid = new PlayingCard*[0];
}

CardGrid::CardGrid(const CardGrid& a)
{
    rows = a.rows;
    cols = a.cols;

    for (int i = 0; i < rows; i++)
    {
        *(grid + i) = new PlayingCard[cols];
        for (int j = 0; j < cols; j++)
            setUpCard(i, j, a.grid[i][j].getSuit(), a.grid[i][j].getRank());
    }
}

CardGrid::~CardGrid()
{
    for (int i = 0; i < rows; i++)
        delete [] grid[i];
    delete [] grid;
}

CardGrid::CardGrid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    srand(time(0));
    grid = new PlayingCard*[rows];

    for (int i = 0; i < rows; i++)
    {
        *(grid + i) = new PlayingCard[cols];
        for (int j = 0; j < cols; j++)
            setUpCard(i, j, Suit(rand() % 4), Rank(rand() % 13));
    }
}

void CardGrid::setUpCard(int row, int col, Suit suit, Rank rank)
{
    sf::Vector2f cardSize, windowSize, padding, suitScale;
    windowSize = {1920, 1080};
    padding = {20, 20};
    suitScale = {0.2, 0.2};
    int charSize = 50;

    cardSize.y = windowSize.y / rows - padding.y * (rows + 1);
    cardSize.x = 0.7 * cardSize.y;
    sf::Vector2f position = {padding.x + (cardSize.x * col) + padding.x * col, padding.y + (cardSize.y * row) + padding.y * row};

    *(*(grid + row) + col) = PlayingCard(Suit(suit), Rank(rank), cardSize, position, suitScale, padding, charSize);
}


void CardGrid::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            window.draw((*(*(grid + i) + j)));
}