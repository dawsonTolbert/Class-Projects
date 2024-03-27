#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>
#include <stdexcept>
#include "Grid.h"

/*
This class reads a Mouse Island input file,
populates a Grid object from that file,
and then returns that Grid object.

It handles opening and closing the file.
*/

class FileReader{
private:
    std::ifstream inputFile;

public:
    FileReader(std::string fileName){
        inputFile.open(fileName);

        if(!inputFile.good()){
            throw std::invalid_argument("Invalid file name");
        }
    }

    Grid getGrid(){
        Grid returnGrid;

        if(inputFile.is_open()){
            std::string line;
            std::getline(inputFile, line);
            returnGrid.setName(line);

            int numCols = 0;
            int numRows = 0;

            inputFile >> numRows;
            inputFile >> numCols;

            returnGrid.setRows(numRows);
            returnGrid.setCols(numCols);

            int currentRow = 0;
            int currentCol = 0;

            /*
             This is needed when switching between
             cin and getline type commands.

             cin style leaves newline characters
             in the buffer. This code clears those
             out by reading them into it a string.
            */
            std::string clear = "";
            getline(inputFile,clear);

            while(inputFile.good()){
                std::getline(inputFile,line);

                currentCol = 0;

                //Put each character into the grid
                for(char character : line){

                    returnGrid.setPosition(currentRow,currentCol,character-'0');
                    currentCol++;

                    if(currentCol > numCols){
                        throw std::out_of_range("Too many columns");
                    }
                }
                currentRow++;

                if(currentRow > numRows){
                    throw std::out_of_range("Too many rows");
                }
            }
            inputFile.close();
        }
        else{
            throw std::runtime_error("File not open");
        }

        return returnGrid;
    }

};

#endif // FILEREADER_H
