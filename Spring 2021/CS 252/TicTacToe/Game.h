//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game{
private:
    Grid board;

public:

    Game(){

    }

    void place(int row, int col, char value){
        board.setPosition(row,col,value);
    }

    bool checkRow(){
        for(int i = 0; i < 3; i++){
            if(board.getPosition(i,0) == 'X' or board.getPosition(i,0) == 'O'){
                if(board.getPosition(i,0) == board.getPosition(i,1) and
                        board.getPosition(i,1) == board.getPosition(i,2)){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkColumn(){
        for(int i = 0; i < 3; i++){
            if(board.getPosition(0,i) == 'X' or board.getPosition(0,i) == 'O'){
                if(board.getPosition(0,i) == board.getPosition(1,i) and
                        board.getPosition(1,i) == board.getPosition(2,i)){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkDiagonal(){
        if(board.getPosition(0,0) == 'X' or board.getPosition(0,0) == 'O'){
            if(board.getPosition(0,0) == board.getPosition(1,1) and
                    board.getPosition(1,1) == board.getPosition(2,2)){
                return true;
            }
        }
        return false;
    }

    bool checkAntiDiagonal(){
        if(board.getPosition(0,2) == 'X' or board.getPosition(0,2) == 'O'){
            if(board.getPosition(0,2) == board.getPosition(1,1) and
                    board.getPosition(1,1) == board.getPosition(2,0)){
                return true;
            }
        }
        return false;
    }

    bool checkWin(){
        if(checkRow() == true){
            return true;
        }
        if(checkColumn() == true){
            return true;
        }
        if(checkDiagonal() == true){
            return true;
        }
        if(checkAntiDiagonal() == true){
            return true;
        }
        return false;
    }
};

#endif // GAME_H
