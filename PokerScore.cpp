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
    out << endl;
    out << "High Card: " << score.highCard << endl;
    out << "Official Score: " << score.officialScore << endl;
    return out;
}
PokerScore::Score& PokerScore::operator[](unsigned int index)
{
    return scores[index];
}
void PokerScore::setOfficialScore(int a)
{
    officialScore = a;
}
void PokerScore::setHighCard(int a)
{
    highCard = a;
}
int PokerScore::getOfficialScore()
{
    return officialScore;
}
int PokerScore::getHighCard()
{
    return highCard;
}
vector<PokerScore::Score> PokerScore::getScores()
{
    return scores;
}