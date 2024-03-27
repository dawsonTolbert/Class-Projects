#include <iostream>

using namespace std;

#include "Grid.h"
#include "Game.h"

void printGrid(Grid);

int main()
{
    Game myGame;
    myGame.place(1,1,'X');
    myGame.place(0,0,'X');
    myGame.place(2,2,'X');
    cout << "True: " << true << endl;
    cout << "False: " << false << endl;
    cout << myGame.checkWin() << endl;

    return 0;
}

void printGrid(Grid grid){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << grid.getPosition(i,j) << " ";
        }
        cout << endl;
    }

}

