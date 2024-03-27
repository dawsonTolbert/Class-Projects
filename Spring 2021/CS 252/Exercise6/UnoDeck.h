//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef UNODECK_H
#define UNODECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "UnoCard.h"

class UnoDeck{
private:
    std::vector<UnoCard> deck;

public:
    UnoDeck(){
    }

    UnoDeck(bool draw4){
        if(draw4 == true){
            deck.reserve(56);
            deck.push_back(UnoCard(0,0));
            deck.push_back(UnoCard(0,0));
            deck.push_back(UnoCard(0,0));
            deck.push_back(UnoCard(0,0));
        }
        else{
            deck.reserve(52);
        }

        deck.push_back(UnoCard(0,1));
        deck.push_back(UnoCard(0,1));
        deck.push_back(UnoCard(0,1));
        deck.push_back(UnoCard(0,1));

        for(int i = 1; i <= 4; i++){
            for(int j = 2; j <= 14; j++){
                deck.push_back(UnoCard(i,j));
            }
        }
    }

    int size(){
        return deck.size();
    }

    UnoCard getCardAt(int i){
        if(i < 0 or i > deck.size()){
            throw std::invalid_argument("Invalid position");
        }
        return deck.at(i);
    }

    UnoCard deal(){
        UnoCard temp = deck.back();
        deck.pop_back();
        return temp;
    }

    void shuffle(){
        std::mt19937 ran( time ( nullptr ) );

        std::shuffle(deck.begin(), deck.end(), ran);
    }
};

#endif // UNODECK_H
