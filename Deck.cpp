#include "Deck.h"

Deck::Deck()
{
    PlayingCard temp[52];
    int index = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            temp[index++] = PlayingCard(Suit(i), Rank(j));

    for (int i = 0; i < DECK_SIZE; i++)
        stack.push(temp[i]);
}

void Deck::shuffle()
{
    PlayingCard temp[52];
    int order[52] = {NULL};
    stack.clear();

    int index = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            temp[index++] = PlayingCard(Suit(i), Rank(j));

    for (int i = 0; i < DECK_SIZE; i++)
    {
        int index;
        do
        {
           index = rand() % 52;
        } while (order[index] != NULL);
        order[index] = i;
    }

    for (int i = 0; i < DECK_SIZE; i++)
        stack.push(temp[order[i]]);
}

PlayingCard Deck::dealCard()
{
    PlayingCard c = stack.pop();
    if (stack.empty())
        shuffle();
    return c;
}