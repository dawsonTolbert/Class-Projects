//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef UNOCARD_H
#define UNOCARD_H

#include <string>
#include <stdexcept>

class UnoCard{
private:
    int suit;
    int rank;

    void setSuit(int suit){
        if(suit < 0 or suit > 4){
            throw std::invalid_argument("Invalid Suit");
        }
        this->suit = suit;
    }

    void setRank(int rank){
        if(rank < 0 or rank > 14){
            throw std::invalid_argument("Invalid Suit");
        }
        this->rank = rank;
    }

public:
    UnoCard(int suit, int rank){
        setSuit(suit);
        setRank(rank);
    }

    int suitNum(){
        return suit;
    }

    std::string suitName(){
        switch(suit){
        case 0: return "Wild";
        case 1: return "Red";
        case 2: return "Yellow";
        case 3: return "Green";
        case 4: return "Blue";
        default: return "Error";
        }
    }

    int rankNum(){
        return rank;
    }

    std::string rankName(){
        switch(rank){
        case 0: return "Draw 4";
        case 1: return "Color Switch";
        case 2: return "0";
        case 3: return "1";
        case 4: return "2";
        case 5: return "3";
        case 6: return "4";
        case 7: return "5";
        case 8: return "6";
        case 9: return "7";
        case 10: return "8";
        case 11: return "9";
        case 12: return "Skip";
        case 13: return "Reverse";
        case 14: return "Draw 2";
        default: return "Error";
        }
    }

    std::string toString(){
        if(suit == 0){
            if(rank == 0){
                return "Draw 4";
            }
            else{
                return "Color Switch";
            }
        }
        else{
            return suitName() + " " + rankName();
        }
    }
};

#endif // UNOCARD_H
