#include <cstdlib>
#include <iostream>
#include <vector>
#include<algorithm>
#include <functional>
#include <map>
#include <functional>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerHand.h"

using namespace std;

Player::Player(string name):
Name(name)
{

}

Player::~Player()
{
}

string Player::name()const
{
	return Name;
}

int PlayerHand::HandSize() const
{
    return Hand.size();
}
//adds cards to hand
void PlayerHand::UpdateCard(Card* crd)
{
	Hand.push_back(crd);
}
// returns card to play or null if player draws a card
void PlayerHand::DeletePlayer()
{
	while(!Hand.empty())
	{
		delete Hand.back();
		Hand.pop_back();
	}
}

//2nd player version implementation
char Player2::ID = 'A';

Player2::Player2(): PlayerHand(string("Player") + ID++),DisplayAdds(false)
{

}

Player2::Player2(string name):PlayerHand(name),DisplayAdds(false)
{

}

Player2::~Player2()
{

}

void Player2::printHand(bool numbers)
{
    if(numbers)
    {
        for(int i =1; i <= Hand.size(); i++)
        {
            if(i < 10)
                cout << " " << i;
            else
                cout << " " << i;
            cout << '';
        }
        cout << endl;
    }
    for(vector<Card*>::iterator it = Hand.begin(); it != Hand.end(); it++)
		cout << *(*it) << ' ';
	cout << endl;
}

bool compare(const Card* a, const Card* b)
{
    return (*a) < (*b);
}

void Player2::sortHand()
{
    sort(Hand.begin(), Hand.end(), compare);
}

void Player2::Display(string msg) const
{
    cout << msg << endl;
}

Card* Player2::RenderPlayer(const Card* lastCard, bool takeback)
{
    cout << name << ": your turn" << endl;
    sortHand();
    printHand(true);
    Card *ret = NULL;
    int num = -1;
    
    while(!ret)
	{
		while( num < 0 || num > Hand.size_type() )
		{
			cout << "Enter the number corresponding to the card you want to play or 0 to draw cards until you find one that will play: ";
			cout << "<" << *lastCard << "> ";
			while( !(cin >> num) )
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please enter a number from 0 to " << Hand.size_type() << ": ";
			}
			if(num == 0 && takeback)
				return NULL;
			--num;
		}
		ret = Hand[num];
	}
	if(ret->color() == WILD)
	{
		int colNum = -1;
		Suit color = Default;
		while(color == Default)
		{	
			cout << "Select which color you'd like your wild to be: " << std::endl;
			cout << "1: Red  2: Green  3: Yellow  4: Blue" << std::endl;
			cout << "Your choice: ";
			while( !(cin >> colNum) )
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please try again: ";
			}
			switch(colNum)
			{
			case 1: color = RED; break;
			case 2: color = GREEN; break;
			case 3: color = YELLOW; break;
			case 4: color = BLUE; break;
			default: color = Default;
			}
		}
		ret->setWildColor(color);
	}
	Hand.erase(Hand.begin() + num);
	return ret;
}

PlayerID::PlayerID(string Name, int Age) : mName(Name), age(Age) 
{

}

string PlayerID::getName() const
{
    return mName;
}

int PlayerID::getAge() const
{
  return age;
}

char Computer:: ID = 'A';

Computer::Computer(void):
PlayerHand(string("AIPlayer") + ID++)
{
}

Computer::Computer(string name):
PlayerHand(name)
{
}

Computer::~Computer(void)
{
}

bool isColor(Card* crd, Suit col)
{
	return crd->color() == col;
}

void Computer::displayMessage(string msg)const
{
}

Card* Computer::playCard(const Card* lastCard, bool takeback)
{
	//Get Playable cards
	vector<Card*> playable = vectorIf(Hand.begin(), Hand.end(), bind(&Card::validPlay, &lastCard, placeholders::_1));

	if( playable.size() == 0 )
		return NULL;

	//Find most common color
	SuitCounts counts = countBySuit(playable.begin(), playable.end());
	Suit col = highestCount<Suit>(counts.begin(), counts.end());

	//list all playable cards of that color
	playable = vectorIf(playable.begin(), playable.end(), bind(isColor, placeholders::_1, col));
	//choose a random one
	Card* ret = playable[rand() % playable.size()];
	//if it's wild, pick a color
	if(ret->color() == WILD)
	{
		counts = countBySuit(Hand.begin(), Hand.end());
		counts[WILD] = 0;
		col = highestCount<Suit>(counts.begin(), counts.end());
		if(col == WILD)
		{
			Suit colors[] = {RED, GREEN, BLUE, YELLOW};
			col = colors[ rand()%4 ];
		}
		ret->setWildColor(col);
	}
	//remove from hand
        //Use of "find" non-mutating algorithm
	Hand.erase(find(Hand.begin(), Hand.end(), ret) );
	return ret;
}

template<class InputIterator>
SuitCounts Computer::countBySuit(InputIterator first, InputIterator last)
{
	SuitCounts counts;
	for(InputIterator it = first; it != last; it++)
	{
		++counts[ (*it)->color() ];
	}
	return counts;
}

template<class InputIterator, class Predicate>
vector<Card*> Computer::vectorIf( InputIterator first, InputIterator last, Predicate pred )
{
	vector<Card*> cards;
	while(first != last)
	{
		if( pred(*first) )
			cards.push_back(*first);
		++first;
	}
	return cards;
}

template<class T, class InputIterator>
T Computer::highestCount(InputIterator first, InputIterator last)
{
	T ret;
	int highest = -1;
	while(first != last)
	{
		if(first->second > highest)
		{
			highest = first->second;
			ret = first->first;
		}
		first++;
	}
	return ret;
}









