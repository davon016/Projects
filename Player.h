#ifndef PLAYER_H
#define PLAYER_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "PlayerHand.h"
#include "Card.h"
#include "Deck.h"

using namespace std;

typedef map<Suit,int> SuitCount;

class Player
{
public:
   Player(string name);
   virtual ~Player();
   
   string name();
   virtual int HandSize()const = 0;

   //actions
   virtual void UpdateCard(Card* crd) = 0; //AddCards
   void DeletePlayer() = 0;
   
   //returns card to play if player draws
   virtual Card* RenderPlayer(const Card* lastcard, bool takeback = true) = 0;
    
protected:
    string Name;
    
};

//2nd version of player class
class Player2 : public PlayerHand
{
public:
    Player2();
    Player2(string name);
    virtual ~Player2();
    
    virtual Card* RenderPlayer(const Card* lastCard, bool takeback = true);
    void Display(string msg)const;
    
protected:
    static char ID;
    bool DisplayAdd;
    
    void sortHand();
    void printHand(bool numbers = false);
    void DisplayAdds(bool YorN);
    };
    
    class PlayerID{
private:
    string mName;
    int age;

public:
    PlayerID(string, int);
    string getName() const;
    int getAge() const;

};

typedef map<Suit,int> SuitCounts;

class Computer :
	public PlayerHand
{
public:
	Computer(void);
	COmputer(string name);
	virtual ~Computer(void);

	void displayMessage(string)const;

	virtual Card* playCard(const Card* lastCard, bool takeback = true);

protected:
    //iterate automatically through game 
	template<class InputIterator>
	SuitCounts countBySuit( InputIterator first, InputIterator last );
	template<class T, class InputIterator>
	T highestCount( InputIterator first, InputIterator last);
	template<class InputIterator, class Predicate>
	vector<Card*> vectorIf( InputIterator first, InputIterator last, Predicate pred );

private:
	static char ID;
};

#endif /* PLAYER_H */

