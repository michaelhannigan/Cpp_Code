#include <iostream>

#include <ctime>

#include <cstdlib>

#include <string>

using namespace std;

int main()

{

  const int NUMBER_OF_CARDS = 52;

  int deck[NUMBER_OF_CARDS];

  string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

  string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",

    "10", "Jack", "Queen", "King"};

 

  // Initialize cards

  for (int i = 0; i < NUMBER_OF_CARDS; i++)
        deck[i] = i;



// use a for loop to shuffle. I recommend using an index randomly. You can use your own algorithm to  

//shuffle the cards. 

  // your code to shuffle the cards; 
   int deckSize = sizeof(deck)/sizeof(deck[0]);
    srand(time(0));
    for(int i = 0; i<NUMBER_OF_CARDS; i++){
        int shuffleNum = rand()%NUMBER_OF_CARDS;
        deck[i] = deck[shuffleNum];
    }



  // Display the first four cards
  
  for(int i = 0; i<4; i++){
      int rankNum = deck[i] % 13;
      string rank = ranks[rankNum];
      
      int suitNum = deck[i]/13;
      string suit = suits[suitNum];
      
      cout<<rank<< " of " << suit << endl;
  }



 

 

 

}

