#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"

using namespace std;

//stackqueue implementation for player info

void(stack)();
void printStack(stack<PlayerID>);
string printPlayer(const PlayerID&);
void printQueue(queue<PlayerID> players);
void queue();

void stackExample(){
    string *Name;
    stack<PlayerID> playerStack;
    cin>> Name;
    cout << "is the stack empty: " << playerStack.empty() << endl;
    //playerStack.pop();
    Player player1(Name);
    playerStack.push(player1);
    cout << "is the stack empty: " << playerStack.empty() << endl;
    cout << "top: " << printPlayer(playerStack.top()) << endl;
    playerStack.push(*(new Player(Name)));
    playerStack.push(Player(Name));
    playerStack.push(Player(Name));
    playerStack.push(Player(Name));
    cout << "top: " << printPlayer(playerStack.top());
    playerStack.pop();
    cout << "top: " << printPlayer(playerStack.top());
    printStack(playerStack);
    cout << "is the stack empty: " << playerStack.empty() << endl;
    printStack(playerStack);
}

string printPlayer(const PlayerID& player){
    cout << "Name: " << player.getName() << " | Age: " << player.getAge() << endl;
    return "";
}

void printStack(stack<PlayerID> players){
    cout << endl << "stack: " << endl;
    while(!players.empty()){
        printPlayer(players.top());
        players.pop();
    }
    cout << endl;
}

void queue(string **Name)
{
    queue<PlayerID> playerQueue;
    cout << "Enter a name: " << playerQueue.empty() << endl;
    cin >> Name;
    Player player1(NAME);
    playerQueue.push(player1);
    cout << "is the queue empty: " << playerQueue.empty() << endl;
    cout << "front: " << printPlayer(playerQueue.front()) << endl;
    playerQueue.push(Player(Name));
    playerQueue.push(Player(Name));
    playerQueue.push(Player(Name));
    playerQueue.push(Player(Name));
    cout << "front: " << printPlayer(playerQueue.front()) << endl;
    playerQueue.pop();
    cout << "front: " << printPlayer(playerQueue.front()) << endl;
    printQueue(playerQueue);

    cout << "is the queue empty: " << playerQueue.empty() << endl;

    stack<Player> playerStack;
    playerStack.push(Player(Name));
    playerStack.push(Player(Name));
    playerStack.push(Player(Name));
    playerStack.push(Player(Name));
    printStack(playerStack);
}

void printQueue(queue<PlayerID> players){
    cout << endl << "queue: " << endl;
    while(!players.empty()){
        printPlayer(players.front());
        players.pop();
    }
    cout << endl;
}

int main(int argc, char** argv) 
{
    Game game;
    stack();
    queue();
            
    game.addPlayers();
    game.playRound();
    
    cout << "\n\nPRESS ANY KEY TO QUIT" << endl;
    
    
    return 0;
}


