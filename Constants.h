#ifndef CARD_CONSTANTS_H
#define CARD_CONSTANTS_H

#include <iostream>
using namespace std;

enum Suit {HEART, SPADE, DIAMOND, CLUB};
enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

struct Constants
{
    static string suitStrings[4];
    static string rankStrings[13];
};

#endif //CARD_CONSTANTS_H