#include "CardHandScorer.h"

CardHandScorer::CardHandScorer(){}

PokerScore CardHandScorer::scorePokerHand(CardHand hand)
{
    PokerScore score;

    int sameRanks = sameRank(hand);
    int sameSuits = sameSuit(hand);
    int consecutives = consecutive(hand);

    if (royalFlush(hand)) score += PokerScore::ROYAL_FLUSH;
    if (consecutives == 5 && sameSuits == 5) score += PokerScore::STRAIGHT_FLUSH;
    if (sameRanks == 4) score += PokerScore::FOUR_OF_A_KIND;
    if (fullHouse(hand)) score += PokerScore::FULL_HOUSE;
    if (sameSuits == 5) score += PokerScore::FLUSH;
    if (consecutives == 5) score += PokerScore::STRAIGHT;
    if (sameRanks >= 3) score += PokerScore::THREE_OF_A_KIND;
    if (twoPair(hand)) score += PokerScore::TWO_PAIR;
    if (sameRanks >= 2) score += PokerScore::ONE_PAIR;
    score += PokerScore::HIGH_CARD;

    score.setHighCard(calculateHighCard(hand));
    score.setOfficialScore(calculateOfficialScore(score));

    return score;
}

int CardHandScorer::calculateOfficialScore(PokerScore score)
{
    vector<PokerScore::Score> scores = score.getScores();
    int max = scores[0];
    for (int i = 0; i < scores.size(); i++)
        if (max < scores[i]) max = scores[i];
    return max;
}

int CardHandScorer::calculateHighCard(CardHand hand)
{
    int max = 0;
    vector<PlayingCard> cards = hand.getHand();
    for (int i = 0; i < cards.size(); i++)
        if (cards[i].getRank() > max) max = cards[i].getRank();
    return max;
}

bool CardHandScorer::royalFlush(CardHand h)
{
    if (sameSuit(h) < 5) return false;
    int* ranks = h.getRanks();
    return ranks[0] != 0 && ranks[9] != 0 && ranks[10] != 0 && ranks[11] != 0 && ranks[12] != 0;
}

bool CardHandScorer::fullHouse(CardHand h)
{
    bool three, two = false;
    int* ranks = h.getRanks();
    for (int i = 0; i < 13; i++)
    {
        if (ranks[i] >= 3) three = true;
        if (ranks[i] >= 2) two = true;
    }
    return three && two;
}

bool CardHandScorer::twoPair(CardHand h)
{
    int count = 0;
    int* ranks = h.getRanks();
    for (int i = 0; i < 13; i++)
        if (ranks[i] >= 2) count++;
    return count >= 2;
}

int CardHandScorer::sameRank(CardHand h)
{
    return getMax(h.getRanks(), 13);
}

int CardHandScorer::sameSuit(CardHand h)
{
    return getMax(h.getSuits(), 4);
}

int CardHandScorer::consecutive(CardHand h)
{
    int max = 0;
    int length = 0;
    int* ranks = h.getRanks();
    for (int i = 0; i < 13; i++)
    {
        while (ranks[i] != 0)
        {
            length++;
            if (length >= 13)
            {
                if (length > max) return length;
                return max;
            }
            i++;
        }
        if (length > max) max = length;
        length = 0;
    }
    return max;
}

int CardHandScorer::getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}