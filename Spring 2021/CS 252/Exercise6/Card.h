#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>

class Card{
private:
    int suit; //0 is joker, 1 is clubs, 2 diamonds, 3 hearts, 4 is spades
    int rank; //0 is joker, 1 is ace, 2-10, 11 is jack, 12 is queen, 13 is king

    //Setters are private, there's no reason to change the card once created
    void setSuit(int suit){
        if(suit < 0 or suit > 4){
            throw std::invalid_argument("Invalid Suit");
        }
        this->suit = suit;
    }

    void setRank(int rank){
        if(rank < 0 or rank > 13){
            throw std::invalid_argument("Invalid Suit");
        }
        this->rank = rank;
    }

public:
    Card(int suit, int rank){
        setSuit(suit);
        setRank(rank);
    }

    int suitNum(){
        return suit;
    }

    std::string suitName(){
        switch(suit){
        case 0: return "Joker";
        case 1: return "Clubs";
        case 2: return "Diamonds";
        case 3: return "Hearts";
        case 4: return "Spades";
        default: return "Error";
        }
    }

    int rankNum(){
        return rank;
    }

    std::string rankName(){
        switch(rank){
        case 0: return "Joker";
        case 1: return "Ace";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        default: return "Error";
        }
    }

    std::string toString(){
        if(suit == 0){
            return "Joker";
        }
        else{
            return rankName() + " of " + suitName();
        }
    }

};

#endif // CARD_H
