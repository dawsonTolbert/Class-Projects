#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "Card.h"

class Deck{

private:
    std::vector<Card> deck;

public:
    //generate an empty deck
    Deck(){
    }

    /*
        generate a standard deck of cards
        if joker is true, then include two jokers
        if joker is false, do not include joker cards
    */

    Deck(bool joker){
        if(joker == true){
            deck.reserve(54);
            deck.push_back(Card(0,0));
            deck.push_back(Card(0,0));
        }
        else{
            deck.reserve(52);
        }

        //Add standard cards
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 13; j++){
                deck.push_back(Card(i,j));
            }
        }
    }

    int size(){
        return deck.size();
    }

    Card getCardAt(int i){
        if(i < 0 or i > deck.size()){
            throw std::invalid_argument("Invalid position");
        }
        return deck.at(i);
    }

    Card deal(){
        Card temp = deck.back();
        deck.pop_back();
        return temp;
    }

    void shuffle(){
        std::mt19937 ran( time ( nullptr ) );

        std::shuffle(deck.begin(), deck.end(), ran);
    }
};

#endif // DECK_H
