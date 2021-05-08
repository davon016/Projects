#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

Card::Card(int number, Suit color)
: num(number), Color(color)
{

}

Card::~Card()
{

}

int Card::number()const
{
    return num;
}

Suit Card::color()const
{
    return Color;
}

void Card::setWildColor(Suit color)
{
    if(Color == WILD)
        Color = color;
}

void Card::resetWildColor()
{
    if(num == WildCard || num == DrawFour )
        
        Color = WILD;
}

bool Card::operator<(const Card& rhs)const
{
	return ((int)Color*1000 + num) < ((int)rhs.Color*1000 + rhs.num);
}

bool Card::validPlay(const Card* toPlay)const
{
		return ((toPlay->Color) & (Color)) || (toPlay->num == num) ||
			     toPlay->num == WildCard || toPlay->num == DrawFour;
}

ostream& operator<<(ostream& os, Card crd)
{
    switch(crd.num)
	{
	case WILD:
		os << "WLD";
		break;
	case DrawFour:
		os << "DR4";
		break;
	case DrawTwo:
		os << "DR2";
		break;
	case Skip:
		os << "SKP";
		break;
	case Reverse:
		os << "REV";
		break;
	default:
		os << "  " << crd.num;
	};
	
	return os;
}