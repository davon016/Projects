#ifndef CARD_H
#define CARD_H
#include <ostream>

using namespace std;

const int DrawTwo = 10;
const int Skip = 11;
const int Reverse = 12;
const int MaxCard = 12;

const int WildCard = 13;
const int DrawFour = 14;

enum Suit
    {
       Default = 0, RED, BLUE, GREEN, YELLOW, WILD = RED|BLUE|GREEN|YELLOW 
};
    
class Card
{
public:
    Card(int number, Suit Color);
	~Card(void);

	int number()const;
	Suit color()const;
	void setWildColor(Suit color);
	void resetWildColor();

        bool validPlay(const Card* toPlay)const;
	friend ostream& operator<<(ostream& os, Card crd);

	bool operator<(const Card& rhs)const;
        
private:
    int num;
    Suit Color;
    
};

ostream& operator<<(ostream& os, Card crd);
#endif /* CARD_H */

