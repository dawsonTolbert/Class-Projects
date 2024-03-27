//Dawson Tolbert
//CS 252
//Sources: http://www.cplusplus.com/reference/string/string/find/

#ifndef BOARDPRINTER_H
#define BOARDPRINTER_H

#include "Board.h"
#include <iostream>

class BoardPrinter{

public:
    void printBoard(Board board){
        std::cout << "~--------------------------~" << std::endl;
        for(int i = 0; i < 8; i++){
            std::cout << " |";
            for(int j = 0; j < 8; j++){
                if(board.getPosition(i,j) == 0){
                    std::cout << "[%]";
                }
                else if(board.getPosition(i,j) == 1){
                    std::cout << "   ";
                }
                else if(board.getPosition(i,j) == 2){
                    std::cout << " O ";
                }
                else if(board.getPosition(i,j) == 3){
                    std::cout << " + ";
                }
                else if(board.getPosition(i,j) == 4){
                    std::cout << " 0 ";
                }
                else if(board.getPosition(i,j) == 5){
                    std::cout << " * ";
                }
            }
            if(i == 0){
                std::cout << "|A";
            }
            else if(i == 1){
                std::cout << "|B";
            }
            else if(i == 2){
                std::cout << "|C";
            }
            else if(i == 3){
                std::cout << "|D";
            }
            else if(i == 4){
                std::cout << "|E";
            }
            else if(i == 5){
                std::cout << "|F";
            }
            else if(i == 6){
                std::cout << "|G";
            }
            else if(i == 7){
                std::cout << "|H";
            }
            std::cout << std::endl;
        }
        std::cout << "~--------------------------~" << std::endl;
        std::cout << "   1  2  3  4  5  6  7  8 " << std::endl;
        std::cout << std::endl;
    }
};

#endif // BOARDPRINTER_H
