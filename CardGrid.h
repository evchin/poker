#ifndef CARD_CARDGRID_H
#define CARD_CARDGRID_H

#include "PlayingCard.h"

class CardGrid : public sf::Drawable, sf::Transformable
{
public:
    CardGrid();
    CardGrid(const CardGrid& a);
    ~CardGrid();
    CardGrid(int rows, int cols);
    void setUpCard(int row, int col, Suit suit, Rank rank);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    PlayingCard** grid;
    int rows;
    int cols;
};


#endif //CARD_CARDGRID_H
