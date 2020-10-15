#include "Deck.h"
#include <iostream>

using namespace std;

Deck::Deck(){
    
  top = 0;
  Card deck[52];
  deck[0] = Card ('A', 'S');
  deck[1] = Card ('2', 'S');
  deck[2] = Card ('3', 'S');
  deck[3] = Card ('4', 'S');
  deck[4] = Card ('5', 'S');
  deck[5] = Card ('6', 'S');
  deck[6] = Card ('7', 'S');
  deck[7] = Card ('8', 'S');
  deck[8] = Card ('9', 'S');
  deck[9] = Card ('T', 'S');
  deck[10] = Card ('J', 'S');
  deck[11] = Card ('Q', 'S');
  deck[12] = Card ('K', 'S');
  deck[13] = Card ('A', 'H');
  deck[14] = Card ('2', 'H');
  deck[15] = Card ('3', 'H');
  deck[16] = Card ('4', 'H');
  deck[17] = Card ('5', 'H');
  deck[18] = Card ('6', 'H');
  deck[19] = Card ('7', 'H');
  deck[20] = Card ('8', 'H');
  deck[21] = Card ('9', 'H');
  deck[22] = Card ('T', 'H');
  deck[23] = Card ('J', 'H');
  deck[24] = Card ('Q', 'H');
  deck[25] = Card ('K', 'H');
  deck[26] = Card ('A', 'D');
  deck[27] = Card ('2', 'D');
  deck[28] = Card ('3', 'D');
  deck[29] = Card ('4', 'D');
  deck[30] = Card ('5', 'D');
  deck[31] = Card ('6', 'D');
  deck[32] = Card ('7', 'D');
  deck[33] = Card ('8', 'D');
  deck[34] = Card ('9', 'D');
  deck[35] = Card ('T', 'D');
  deck[36] = Card ('J', 'D');
  deck[37] = Card ('Q', 'D');
  deck[38] = Card ('K', 'D');
  deck[39] = Card ('A', 'C');
  deck[40] = Card ('2', 'C');
  deck[41] = Card ('3', 'C');
  deck[42] = Card ('4', 'C');
  deck[43] = Card ('5', 'C');
  deck[44] = Card ('6', 'C');
  deck[45] = Card ('7', 'C');
  deck[46] = Card ('8', 'C');
  deck[47] = Card ('9', 'C');
  deck[48] = Card ('T', 'C');
  deck[49] = Card ('J', 'C');
  deck[50] = Card ('Q', 'C');
  deck[51] = Card ('K', 'C');
}

void Deck::refreshDeck(){
  top = 0;
  deck[0] = Card ('A', 'S');
  deck[1] = Card ('2', 'S');
  deck[2] = Card ('3', 'S');
  deck[3] = Card ('4', 'S');
  deck[4] = Card ('5', 'S');
  deck[5] = Card ('6', 'S');
  deck[6] = Card ('7', 'S');
  deck[7] = Card ('8', 'S');
  deck[8] = Card ('9', 'S');
  deck[9] = Card ('T', 'S');
  deck[10] = Card ('J', 'S');
  deck[11] = Card ('Q', 'S');
  deck[12] = Card ('K', 'S');
  deck[13] = Card ('A', 'H');
  deck[14] = Card ('2', 'H');
  deck[15] = Card ('3', 'H');
  deck[16] = Card ('4', 'H');
  deck[17] = Card ('5', 'H');
  deck[18] = Card ('6', 'H');
  deck[19] = Card ('7', 'H');
  deck[20] = Card ('8', 'H');
  deck[21] = Card ('9', 'H');
  deck[22] = Card ('T', 'H');
  deck[23] = Card ('J', 'H');
  deck[24] = Card ('Q', 'H');
  deck[25] = Card ('K', 'H');
  deck[26] = Card ('A', 'D');
  deck[27] = Card ('2', 'D');
  deck[28] = Card ('3', 'D');
  deck[29] = Card ('4', 'D');
  deck[30] = Card ('5', 'D');
  deck[31] = Card ('6', 'D');
  deck[32] = Card ('7', 'D');
  deck[33] = Card ('8', 'D');
  deck[34] = Card ('9', 'D');
  deck[35] = Card ('T', 'D');
  deck[36] = Card ('J', 'D');
  deck[37] = Card ('Q', 'D');
  deck[38] = Card ('K', 'D');
  deck[39] = Card ('A', 'C');
  deck[40] = Card ('2', 'C');
  deck[41] = Card ('3', 'C');
  deck[42] = Card ('4', 'C');
  deck[43] = Card ('5', 'C');
  deck[44] = Card ('6', 'C');
  deck[45] = Card ('7', 'C');
  deck[46] = Card ('8', 'C');
  deck[47] = Card ('9', 'C');
  deck[48] = Card ('T', 'C');
  deck[49] = Card ('J', 'C');
  deck[50] = Card ('Q', 'C');
  deck[51] = Card ('K', 'C');
}

Card Deck::deal(){
    if(top<52){
        top ++;
        return deck[top-1];
    }
    else{
        Card empty;
        empty = Card();
        return empty;
    }
}

void Deck::shuffle(){
    int deckSize = sizeof(deck)/sizeof(deck[0]);
    srand(time(0));
    for(int i = 0; i<deckSize; i++){
        int shuffleNum = rand()%deckSize;
        deck[i] = deck[shuffleNum];
    }
}

bool Deck::cardsLeft(){
    if(52-top == 0){
        return false;
    }else{
        return true;
    }
}

void Deck::showDeck(){
    int deckSize = sizeof(deck)/sizeof(deck[0]);
    
    for(int i = 0; i<deckSize; i++){
        cout << deck[i].showCard();
        if(i<51){
            cout<<",";
        }
        if(i == 12|| i==25||i==38||i==51){
            cout<< "\n" << endl;
        }
        
    }
}

    

