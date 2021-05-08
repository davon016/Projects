#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include <list>

typedef list<Player*> PlayerList;

class Game
{
public:
	Game();
	~Game();
      
	void addPlayers();
	void playRound();

private:
	Deck* deck;
	PlayerList players;
	list<Card*> pile;

	PlayerList::iterator pos;
	bool forward;

	void dealHands();
	Card* safeDeal();
	void drawCards(Player* pl, int numCards);
	void advance();
	void reverse();
};
#endif /* GAME_H */

