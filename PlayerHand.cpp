#include "PlayerHand.h"

PlayerHand::PlayerHand(string name):
Player(name)
{

}

PlayerHand::~PlayerHand()
{
    DeletePlayer();
}

int PlayerHand::HandSize() const
{
    return Hand.size;
}

void PlayerHand::UpdateCard(Card* crd)
{
    Hand.push_back(crd);
}

void PlayerHand::DeletePlayer()
{
    while(!Hand.empty())
    {
        delete Hand.back();
        Hand.pop_back();
    }
}

