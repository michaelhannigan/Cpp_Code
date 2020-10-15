//  Michael Hannigan
//  Class(CeCS 282-04)
//  Project Name(Prog 1 - Solitare Prime)
//  Due Date(09/09/2020)
//  I certify that this program is my own original work. I did not copy any part of 
//  this program from any other source. I further certify that I typed each and 
//  every line of code in this program.


#include <stdio.h>
#include "Deck.h"
#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    
    for(int i = 2; i<num; i++){
        if(num % i == 0){
            return false;
        }
    }
    
    return true;
}

int main()
{
  int input;
  Deck deck;
  
  cout << "Welcome to Solitare Prime!" << endl;
  cout << "1) New Deck" << endl;
  cout << "2) Display Dec" << endl;
  cout << "3) Shuffle Deck" << endl;
  cout << "4) Play Solitaire Prime" << endl;
  cout << "5) Exit" << endl;
  
  // Input validation
 
  cin >> input;
  while(input!=5){
      
      if(input < 1|| input>5){
      cout<< "That input is not valid please give a valid entry";
        cout << "Welcome to Solitare Prime!" << endl;
        cout << "1) New Deck" << endl;
        cout << "2) Display Dec" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Solitaire Prime" << endl;
        cout << "5) Exit" << endl;
      }
      
        if(input == 1){
            deck.refreshDeck();
            cout << "Welcome to Solitare Prime!" << endl;
            cout << "1) New Deck" << endl;
            cout << "2) Display Dec" << endl;
            cout << "3) Shuffle Deck" << endl;
            cout << "4) Play Solitaire Prime" << endl;
            cout << "5) Exit" << endl;
        }
        
        if(input ==2){
            deck.showDeck();
            cout << "Welcome to Solitare Prime!" << endl;
            cout << "1) New Deck" << endl;
            cout << "2) Display Dec" << endl;
            cout << "3) Shuffle Deck" << endl;
            cout << "4) Play Solitaire Prime" << endl;
            cout << "5) Exit" << endl;
        }
        
        if(input == 3){
            deck.shuffle();
            cout << "Welcome to Solitare Prime!" << endl;
            cout << "1) New Deck" << endl;
            cout << "2) Display Dec" << endl;
            cout << "3) Shuffle Deck" << endl;
            cout << "4) Play Solitaire Prime" << endl;
            cout << "5) Exit" << endl;
        }
      

      if(input == 4){
        int numStacks = 0;
        int sum = 0;
        int finalSum = 0;
        
        while(deck.cardsLeft() == true){

            while((!isPrime(sum))&& (deck.cardsLeft() == true)){

            Card currentCard = deck.deal();

            cout << currentCard.showCard();
            cout<< " ";

            sum += currentCard.getValue();

            }
            
            cout<<"Prime:"<<sum <<endl;
            numStacks ++;
            finalSum = sum;
            sum = 0;
            
        }
        if(isPrime(finalSum)){
            cout<< "Winner in "<< numStacks<< " piles!"<< endl;
        }else{
            cout<<"Loser"<<endl;
        }
            cout << "Welcome to Solitare Prime!" << endl;
            cout << "1) New Deck" << endl;
            cout << "2) Display Dec" << endl;
            cout << "3) Shuffle Deck" << endl;
            cout << "4) Play Solitaire Prime" << endl;
            cout << "5) Exit" << endl;
      }
      
      cin >> input;
  }

}


