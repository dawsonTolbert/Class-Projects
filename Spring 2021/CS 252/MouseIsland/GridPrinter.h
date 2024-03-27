#ifndef GRIDPRINTER_H
#define GRIDPRINTER_H

#include "Grid.h"
#include <iostream>

/*
Handles all output from the grid
*/
class GridPrinter{

public:
    void printGrid(Grid grid){
        for(int i = 0; i < grid.getRows(); i++){
            for(int j = 0; j < grid.getCols(); j++){
                if(grid.getPosition(i,j) == 0){
                    std::cout << " ";
                }
                else if(grid.getPosition(i,j) == 1){
                    std::cout << "w";
                }
                else if(grid.getPosition(i,j) == 2){
                    std::cout << "B";
                }
                else if(grid.getPosition(i,j) == 3){
                    std::cout << "m";
                }
                else if(grid.getPosition(i,j) == 4){
                    std::cout << "C";
                }
                else if(grid.getPosition(i,j) == 5){
                    std::cout << "F";
                }
                else if(grid.getPosition(i,j) == 6){
                    std::cout << "h";
                }
                else{
                    std::cout << grid.getPosition(i,j);
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // GRIDPRINTER_H
