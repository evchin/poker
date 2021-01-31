#include "Deck.h"

Deck::Deck()
{
    int index = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            deck[index++] = Card(Suit(i), Rank(j));
    cardIndex = 0;
}
void Deck::shuffle()
{
    Card* temp = new Card[DECK_SIZE];
    int order[52] = {NULL};

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
        temp[order[i]] = deck[i];

    for (int i = 0; i < DECK_SIZE; i++)
        deck[i] = temp[i];

    delete [] temp;
}
Card Deck::getCardAt(int index)
{
    return deck[index];
}
Card Deck::dealCard()
{
    if (cardIndex >= DECK_SIZE)
        cardIndex = 0;
    return deck[cardIndex++];
}
ostream& operator<<(ostream& out, const Deck& deck)
{
    for (int i = 0; i < deck.DECK_SIZE; i++)
        out << i + 1 << ": " << deck.deck[i] << endl;
    return out;
}