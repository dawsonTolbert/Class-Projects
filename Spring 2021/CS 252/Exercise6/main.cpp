//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include <string>

#include "Deck.h"
#include "UnoDeck.h"
#include "BlackjackHand.h"

using namespace std;

void printDeck(Deck);
void printUnoDeck(UnoDeck);
void blackjackHand();

int main()
{
    cout << "Hello World!" << endl;

    Deck myDeck(true);

    myDeck.shuffle();

    //Dealing a card
    Card demo = myDeck.deal();
    cout << demo.toString() << endl;
    cout << "--------------------------" << endl;

    printDeck(myDeck);

    cout << "--------------------------" << endl;
    cout << "---------Uno Deck---------" << endl;
    cout << "--------------------------" << endl;

    UnoDeck myUnoDeck(true);

    myUnoDeck.shuffle();

    //Dealing a card
    UnoCard unoDemo = myUnoDeck.deal();
    cout << unoDemo.toString() << endl;
    cout << "--------------------------" << endl;

    printUnoDeck(myUnoDeck);

    cout << "--------------------------" << endl;

    blackjackHand();

    return 0;
}

void printDeck(Deck deck){
    for(int i = 0; i < deck.size(); i++){
        cout << deck.getCardAt(i).toString() << endl;
    }
}

void printUnoDeck(UnoDeck deck){
    for(int i = 0; i < deck.size(); i++){
        cout << deck.getCardAt(i).toString() << endl;
    }
}

void blackjackHand(){
    Deck blackjackDeck(false);
    BlackjackHand hand1;
    BlackjackHand hand2;
    BlackjackHand hand3;

    blackjackDeck.shuffle();

    hand1.addCard(blackjackDeck.getCardAt(0));
    hand2.addCard(blackjackDeck.getCardAt(7));
    hand3.addCard(blackjackDeck.getCardAt(14));

    for(int i = 1; i < 7; i++){
        hand1.addCard(blackjackDeck.getCardAt(i));
        hand2.addCard(blackjackDeck.getCardAt(i*2));
        hand3.addCard(blackjackDeck.getCardAt(i*3));
    }

    for(int i = 0; i < hand1.getSize(); i++){
        cout << hand1.getCardAt(i).toString() << endl;
    }
    cout << "Hand 1 scores: " << hand1.scoreHand()  << endl;

    cout << "--------------------------" << endl;

    for(int i = 0; i < hand2.getSize(); i++){
        cout << hand2.getCardAt(i).toString() << endl;
    }
    cout << "Hand 2 scores: " << hand2.scoreHand()  << endl;

    cout << "--------------------------" << endl;

    for(int i = 0; i < hand3.getSize(); i++){
        cout << hand3.getCardAt(i).toString() << endl;
    }
    cout << "Hand 3 scores: " << hand3.scoreHand()  << endl;
}
