#include "PokerScore.h"

PokerScore::PokerScore()
{
    scores = {};
}

int PokerScore::size()
{
    return scores.size();
}
void PokerScore::operator +=(const Score& score)
{
    scores.push_back(score);
}
bool operator==(const PokerScore& p, PokerScore::Score score)
{
    for (int i = 0; i < p.scores.size(); i++)
        if (p.scores[i] == score) return true;
    return false;
}
ostream& operator<<(ostream& out, const PokerScore& score)
{
    out << "Score: " << score.scoreStrings[score.scores[0]];
    for (int i = 1; i < score.scores.size(); i++)
        out << ", " << score.scoreStrings[score.scores[i]];
    return out;
}
PokerScore::Score& PokerScore::operator[](unsigned int index)
{
    return scores[index];
}