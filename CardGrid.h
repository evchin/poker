#ifndef CARD_CARDGRID_H
#define CARD_CARDGRID_H

#include "PlayingCard.h"
#include <time.h>
#include <stdlib.h>

class CardGrid : public sf::Drawable, sf::Transformable
{
public:
    CardGrid();
    CardGrid(int rows, int cols);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    PlayingCard** grid;
    int rows;
    int cols;
};


#endif //CARD_CARDGRID_H
