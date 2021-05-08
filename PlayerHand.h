#ifndef PLAYERHAND_H
#define PLAYERHAND_H
#include "Player.h"
#include "Card.h"
#include <string>
#include <vector>

class PlayerHand :
        public Player
{
    public:
        PlayerHand(string name);
        virtual ~PlayerHand();
        
        int HandSize()const;
        void UpdateCard(Card* crd);
        void DeletePlayer();
        
        virtual Card* RenderPlayer(const Card* lastcard, bool takeback = true) = 0;
        
        protected:
            vector <Card*> Hand;
};
#endif /* PLAYERHAND_H */

