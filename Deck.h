#ifndef DECK_H
#define DECK_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Card.h"
#include <list>

using namespace std;

class Deck
{
public:
    Deck();
    ~Deck();
    
    int size() const;
    Card* deal();
    void shuffle();
    void print();
    void Updates( list<Card*> card);
    

    
private:
    vector <Card*> card;
};

#endif /* DECK_H */

