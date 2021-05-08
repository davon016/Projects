#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Deck.h"
#include<cstdlib>

using namespace std;

//referenced using gamedev.net

Deck::Deck()
{
	card.reserve(110);
	for(int i = 0; i <= MaxCard; i++)
	{
		card.push_back( new Card(i, RED) );
		card.push_back( new Card(i, GREEN) );
		card.push_back( new Card(i, BLUE) );
		card.push_back( new Card(i, YELLOW) );
		if(i != 0)
		{
			card.push_back( new Card(i, RED) );
			card.push_back( new Card(i, GREEN) );
			card.push_back( new Card(i, BLUE) );
			card.push_back( new Card(i, YELLOW) );
		}
	}
	for(int i = 0; i < 4; i++)
	{
		card.push_back( new Card(WildCard, WILD) );
		card.push_back( new Card(DrawFour, WILD) );
	}
}

Deck::~Deck(void)
{
	while(!card.empty())
	{
		delete card.back();
		card.pop_back();
	}
}

int Deck::size()const
{
    return card.size();
}
Card* Deck::deal()
{
	if(card.empty())
		return NULL;
	Card* ret = card.back();
	card.pop_back();
	return ret;
}

//Randomly shuffling deck using algorithm
void Deck::shuffle()
{
    random_shuffle(card.begin(), card.end());

}

void Deck::print()
{
	for(int i = 0; i < card.size(); i++)
	{
		cout << (card*) << ' ' <<endl; //wont compile for me, not sure why.
		if( (i+1) % 10 == 0 )
			cout << '\n';
	}
	cout << endl;
}

void Deck::Updates(list<Card*> cards)
{
	card.insert(card.begin(), cards.begin(), cards.end());
}


