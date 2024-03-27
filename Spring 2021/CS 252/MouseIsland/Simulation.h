#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grid.h"
#include "GridPrinter.h"
#include <random>   //for randomness
#include <chrono>   //for time
#include <thread>   //for pausing
#include <string>   //for string

/*
This is the controller.
It combines the model (the grid) and
the view (GridPrinter).

It contains the logic and rules for
Mouse Island simulations.
*/
class Simulation{

private:
    Grid map;
    GridPrinter printer;

public:
    Simulation(Grid map){
        this->map = map;
    }

    std::string simulate(){
        Grid simMap = map;
        //Since the mouse location is in the file, we need to find it
        int mouseRow = 0;
        int mouseCol = 0;
        int mouseDir = 0;
        bool mouseFound = false;
        int catRow = 0;
        int catCol = 0;
        int catDir = 0;
        bool catFound = false;
        int turn = 0;
        bool catFood = false;
        bool catPresent = true;
        bool mouseHole = false;
        bool catHole = false;

        for(int i = 0; i < simMap.getRows(); i++){
            for(int j = 0; j < simMap.getCols(); j++){
                if(simMap.getPosition(i,j) == 3){
                    mouseRow = i;
                    mouseCol = j;
                    mouseFound = true;
                }
                if(simMap.getPosition(i,j) == 4){
                    catRow = i;
                    catCol = j;
                    catFound = true;
                }
                if(mouseFound == true and catFound == true){
                    break;
                }
            }
        }

        //print the initial map and delay
        printer.printGrid(simMap);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        //simulation loop, currently goes forever. You should consider changing it.
        while(turn != 100){

            //blank out the cat and mouse's current spot
            if(catPresent == true){
                if(catFood == true){
                    simMap.setPosition(catRow,catCol,5);
                }
                if(catHole == true){
                    simMap.setPosition(catRow,catCol,6);
                    catHole = false;
                }
                else{
                    simMap.setPosition(catRow,catCol,0);
                }
            }
            simMap.setPosition(mouseRow,mouseCol,0);

            //move the cat
            if(catPresent == true){
                catDir = getRandomNumber(0,3);
                if(catDir == 0){
                    catRow--;
                }
                else if(catDir == 1){
                    catCol++;
                }
                else if(catDir == 2){
                    catRow++;
                }
                else if(catDir == 3){
                    catCol--;
                }
            }

            //if cat hits an object, handle reaction
            if(simMap.getPosition(catRow,catCol) == 5){
                catFood = true;
            }
            else{
                catFood = false;
            }
            if(simMap.getPosition(catRow,catCol) == 1){
                if(catDir == 0){
                    catRow++;
                }
                else if(catDir == 1){
                    catCol--;
                }
                else if(catDir == 2){
                    catRow--;
                }
                else if(catDir == 3){
                    catCol++;
                }
            }
            if(simMap.getPosition(catRow,catCol) == 2){
                if(mouseHole == true){
                    catPresent = false;
                }
                else{
                    if(catDir == 0){
                        catRow++;
                    }
                    else if(catDir == 1){
                        catCol--;
                    }
                    else if(catDir == 2){
                        catRow--;
                    }
                    else if(catDir == 3){
                        catCol++;
                    }
                }
            }
            if(simMap.getPosition(catRow,catCol) == 6){
                catHole = true;
            }

            //place the cat in the new position
            if(catPresent == true){
                if(catHole == true){
                    simMap.setPosition(catRow,catCol,6);
                }
                else{
                    simMap.setPosition(catRow,catCol,4);
                }
            }

            //move the mouse
            mouseDir = getRandomNumber(0,3);
            if(mouseDir == 0){
                mouseRow--;
            }
            else if(mouseDir == 1){
                mouseCol++;
            }
            else if(mouseDir == 2){
                mouseRow++;
            }
            else if(mouseDir == 3){
                mouseCol--;
            }

            //if the mouse hits an object, return the result
            if(simMap.getPosition(mouseRow,mouseCol) == 1){
                return "drown";
            }
            else if(simMap.getPosition(mouseRow,mouseCol) == 2){
                return "escape";
            }
            else if(simMap.getPosition(mouseRow,mouseCol) == 4){
                return "eaten";
            }
            else if(simMap.getPosition(mouseRow,mouseCol) == 5){
                turn = 0;
            }
            else if(simMap.getPosition(mouseRow,mouseCol) == 6){
                mouseHole = true;
            }

            //place the mouse in the new position
            simMap.setPosition(mouseRow,mouseCol,3);

            //print the map and wait for a delay
            printer.printGrid(simMap);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));

            //count the loop
            turn++;
        }
        return "starve";
    }

    int getRandomNumber(int min, int max){
        static std::mt19937 ran(time(nullptr));
        std::uniform_int_distribution<int>dist(min, max);
        return dist(ran);
    }
};

#endif // SIMULATION_H
