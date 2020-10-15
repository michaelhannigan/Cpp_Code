#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

    //const int top = 10;
    //const int num = 52; 

class Deck{
    private:
        int top = 0;
        Card deck[52];
    public:
        Deck();
        void refreshDeck();
        Card deal();
        void shuffle();
        bool cardsLeft();
        void showDeck();
};

  
#endif
