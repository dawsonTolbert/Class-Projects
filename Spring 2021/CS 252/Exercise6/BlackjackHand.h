//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef BLACKJACKHAND_H
#define BLACKJACKHAND_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "Card.h"

class BlackjackHand{
private:
    std::vector<Card> deck;

public:
    BlackjackHand(){
    }

    int getSize(){
        return deck.size();
    }

    void addCard(Card card){
        deck.push_back(card);
    }

    Card getCardAt(int i){
        if(i < 0 or i > deck.size()){
            throw std::invalid_argument("Invalid position");
        }
        return deck.at(i);
    }

    int scoreHand(){
        int score = 0;
        int i = 0;
        while(i < 7){
            if(getCardAt(i).rankName() == "King"){
                score = score + 10;
            }
            else if(deck.at(i).rankName() == "Queen"){
                score = score + 10;
            }
            else if(deck.at(i).rankName() == "Jack"){
                score = score + 10;
            }
            else if(deck.at(i).rankName() == "10"){
                score = score + 10;
            }
            else if(deck.at(i).rankName() == "9"){
                score = score + 9;
            }
            else if(deck.at(i).rankName() == "8"){
                score = score + 8;
            }
            else if(deck.at(i).rankName() == "7"){
                score = score + 7;
            }
            else if(deck.at(i).rankName() == "8"){
                score = score + 8;
            }
            else if(deck.at(i).rankName() == "7"){
                score = score + 7;
            }
            else if(deck.at(i).rankName() == "6"){
                score = score + 6;
            }
            else if(deck.at(i).rankName() == "5"){
                score = score + 5;
            }
            else if(deck.at(i).rankName() == "4"){
                score = score + 4;
            }
            else if(deck.at(i).rankName() == "3"){
                score = score + 3;
            }
            else if(deck.at(i).rankName() == "2"){
                score = score + 2;
            }
            else{
                if(score + 11 > 21){
                    score = score + 1;
                }
                else{
                    score = score + 11;
                }
            }
            i++;
        }
        return score;
    }
};

#endif // BLACKJACKHAND_H
