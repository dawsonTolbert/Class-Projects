//Dawson Tolbert
//CS 252
//Sources: http://www.cplusplus.com/reference/string/string/find/

#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <stdexcept>

class Board{
private:
    Square grid[8][8];
    int numRows;
    int numCols;

public:
    Board(){
        numRows = 7;
        numCols = 7;
        grid[0][1].setValue(3);
        grid[0][3].setValue(3);
        grid[0][5].setValue(3);
        grid[0][7].setValue(3);
        grid[1][0].setValue(3);
        grid[1][2].setValue(3);
        grid[1][4].setValue(3);
        grid[1][6].setValue(3);
        grid[2][1].setValue(3);
        grid[2][3].setValue(3);
        grid[2][5].setValue(3);
        grid[2][7].setValue(3);
        grid[3][0].setValue(1);
        grid[3][2].setValue(1);
        grid[3][4].setValue(1);
        grid[3][6].setValue(1);
        grid[4][1].setValue(1);
        grid[4][3].setValue(1);
        grid[4][5].setValue(1);
        grid[4][7].setValue(1);
        grid[5][0].setValue(2);
        grid[5][2].setValue(2);
        grid[5][4].setValue(2);
        grid[5][6].setValue(2);
        grid[6][1].setValue(2);
        grid[6][3].setValue(2);
        grid[6][5].setValue(2);
        grid[6][7].setValue(2);
        grid[7][0].setValue(2);
        grid[7][2].setValue(2);
        grid[7][4].setValue(2);
        grid[7][6].setValue(2);
    }

    int getPosition(int row, int col){
        if(row < 0 or row >= 8){
            throw std::invalid_argument("Invalid row");
        }
        if(col < 0 or col >= 8){
            throw std::invalid_argument("Invalid col");
        }

        return grid[row][col].getValue();
    }

    void setPosition(int row, int col, int value){
        if(row < 0 or row > numRows){
            throw std::invalid_argument("Invalid row");
        }

        if(col < 0 or col > numCols){
            throw std::invalid_argument("Invalid col");
        }

        grid[row][col].setValue(value);
    }
};

#endif // BOARD_H
