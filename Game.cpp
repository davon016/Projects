#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <list>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"

Game::Game(): forward(true)
{
    deck = new Deck;
    srand((unsigned int)time(NULL));
}

Game::~Game()
{
    while(!pile.empty())
    {        
        delete pile.back();
        pile.pop_back();
    }
    delete Deck;
    while(!players.empty())
    {
        delete players.pop_back();
        players.pop_back();
    }
}

void Game::addPlayers()
{
    cout << "How Many Players?" << endl;
    cin>>players;
    
    players.push_back(new Player2(players));
    switch(players.push_back(new Player2()) == 2)
    {
        case 1:
        players.push_back( new Computer() );
	players.push_back( new Computer() );
	players.push_back( new Computer() );
        break;

    }
    
    


pos = players.begin();
}

void Game::playRound()
{
    dealHands();
    
    string winner = "";
    
    while(winner.empty())
    {
        Player* UpdatePlayer = (*pos);
        Card* Played;
        bool takeback = true;
        
        while(true)
        {
            Played = UpdatePlayer->RenderPlayer(pile.back(), takeback);
            
            if(Played == NULL)
            {
                int numCards = 0;
                Card* drawn;
                do
                {
                    numCards++;
                    drawn = safeDeal();
                    UpdatePlayer->UpdateCard(drawn);
                }
                while(!pile.back()->validPlay(drawn) );
                
                cout << UpdatePlayer->name()<<" drew " << numCards << " cards" << endl;
                takeback = false;
                Played = UpdatePlayer->RenderPlayer(pile.back(), takeback);
            }
            
            if(pile.back()->validPlay(Played))
                break;
            else
            {
               UpdatePlayer->UpdateCard(Played);
                cout << "Last Move was invalid." << endl;
            }
        }
        
        pile.back()->resetWildColor();
        pile.push_back(Played);
        cout << UpdatePlayer->name() << "Played a " << *Played << endl;
        
        switch(Played->number())
        {
            case Skip: advance(); break;
            case Reverse: reverse(); break;
            case DrawTwo: 
                 advance();
                 drawCards(*pos, 2);break;
            case DrawFour: advance();
            drawCards(*pos, 4);break;
           }
        if(UpdatePlayer->HandSize()==0)
            winner = UpdatePlayer->name();
        else if(UpdatePlayer->HandSize()==1)
            cout << UpdatePlayer->name() << " says UNO!"<< endl;
        else 
            cout << UpdatePlayer->name()<< " has " << UpdatePlayer->HandSize() "cards left " << endl;
        //next player
        advance();
        cout << endl;
    }
     
    cout << winner << "Has Won!! " << endl;
    
    //clean
    while(!pile.empty())
    {
        delete pile.back();
        pile.pop_back();
    }
    for(PlayerList::iterator it = players.begin(); it != players.end(); it++)
        it*->DeletePlayer();
}
void Game::dealHands()
 {
     assert(pile.empty());
     
     //new deck
     delete deck;
     deck = new Deck();
     deck ->shuffle();
     
     //deal
     for (PlayerList ::iterator it = players.begin(); it != players.end(); it++)
     {
         drawCards(*it, 7);
     }
     //first card
     pile.push_back(deck->deal());
}

Card* Game::safeDeal()
{
    if(deck->size() == 0)
    {
        Card* top = pile.back();
        pile.pop_back();
        deck->Updates(pile);
        deck->shuffle();
        pile.clear();
        pile.push_back(top);
    }
    return deck -> deal();
}
void Game::drawCards(Player* pl, int numCards)
{
    for(int i = 0; i< numCards; i++)
        pl->UpdateCard(safeDeal());
}

void Game::advance()
{
    if(forward)
    {
        pos++;
        if(pos == players.end())
            pos = players.begin();
    }
    else
    {
        if(pos == players.begin())
            pos = players.end();
        pos--;
    }
}

void Game::reverse()
{
    forward = !forward;
}








    