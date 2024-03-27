#ifndef GRID_H
#define GRID_H

#include "Square.h"
#include <string>
#include <stdexcept>

/*
Holds a grid of squares,
the name of a Mouse Island Map,
and the number of rows and columns.

Allows manipulation of grid positions.
*/
class Grid{
private:
    Square grid[30][80];
    std::string mapName;
    int numRows;
    int numCols;

public:
    Grid(){
        mapName = "Uninitialized";
        numRows = 0;
        numCols = 0;
    }

    void setName(std::string name){
        mapName = name;
    }

    void setRows(int rows){
        numRows = rows;
    }

    void setCols(int cols){
        numCols = cols;
    }

    int getRows(){
        return numRows;
    }

    int getCols(){
        return numCols;
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

    int getPosition(int row, int col){
        if(row < 0 or row > numRows){
            throw std::invalid_argument("Invalid row");
        }

        if(col < 0 or col > numCols){
            throw std::invalid_argument("Invalid col");
        }

        return grid[row][col].getValue();
    }
};

#endif // GRID_H
