#ifndef GRID_H
#define GRID_H

#include "Square.h"
#include <stdexcept>

class Grid{
private:
    Square grid[3][3];

public:
    Grid(){

    }

    void setPosition(int row, int col, char value){
        if(row < 0 or row >= 3){
            throw std::invalid_argument("Invalid row");
        }

        if(col < 0 or col >= 3){
            throw std::invalid_argument("Invalid col");
        }

        if(value == 'X'){
            grid[row][col].placeX();
        }
        else if(value == 'O'){
            grid[row][col].placeO();
        }
        else{
            throw std::invalid_argument("Invalid value");
        }
    }

    char getPosition(int row, int col){
        if(row < 0 or row >= 3){
            throw std::invalid_argument("Invalid row");
        }

        if(col < 0 or col >= 3){
            throw std::invalid_argument("Invalid col");
        }

        return grid[row][col].getValue();
    }
};

#endif // GRID_H
