//Dawson Tolbert
//CS 252
//Sources: http://www.cplusplus.com/reference/string/string/find/

#include <iostream>
#include <string>

using namespace std;

#include "Board.h"
#include "BoardPrinter.h"
#include "Game.h"

//Function Prototypes
int selection(string input, int mode);
int getInt(string prompt);

int main()
{
    Board board;
    Game game(board);

    int mode = 1;
    while(mode == 1){
        cout << "Select a mode: " << endl;
        cout << "[0] - Player vs Player" << endl;
        cout << "[1] - Player vs Comp (UNDER CONSTRUCTION)" << endl;
        cin >> mode;
        while(mode < 0 or mode > 1){
            cout << "You must input a valid number!" << endl;
            cin >> mode;
        }
        if(mode == 1){
            cout << "Sorry, Player vs Comp mode is still under construction." << endl;
        }
    }


    int win = 0;
    game.print(board);
    while(win == 0){
        cout << "Player 1 (White) turn!" << endl;
        int selectRow = 8;
        int selectCol = 8;
        while(selectRow == 8 or selectCol == 8){
            cout << "Enter the location of the piece you would like to move (ex F1): " << endl;
            string select = "";
            cin >> select;
            selectRow = selection(select,0);
            selectCol = selection(select,1);
            if(selectRow == 8 or selectCol == 8){
                cout << "Please enter a valid location!" << endl;
            }
            bool can = game.canMove(selectRow, selectCol, 0);
            while(can == false){
                cout << "Please select a movable piece" << endl;
                cin >> select;
                selectRow = selection(select,0);
                selectCol = selection(select,1);
                can = game.canMove(selectRow, selectCol, 0);
            }
        }
        bool pieceMove = false;
        while(pieceMove == false){
            int selectRow2 = 8;
            int selectCol2 = 8;
            while(selectRow2 == 8 or selectCol2 == 8){
                cout << "Enter the location to move to: " << endl;
                string select2 = "";
                cin >> select2;
                selectRow2 = selection(select2,0);
                selectCol2 = selection(select2,1);
                if(selectRow2 == 8 or selectCol2 == 8){
                    cout << "Please enter a valid location!" << endl;
                }
            }
            pieceMove = game.move(selectRow,selectCol,selectRow2,selectCol2,0);
        }

        win = game.won();

        cout << "Player 2 (Black) turn!" << endl;
        selectRow = 8;
        selectCol = 8;
        while(selectRow == 8 or selectCol == 8){
            cout << "Enter the location of the piece you would like to move (ex F1): " << endl;
            string select = "";
            cin >> select;
            selectRow = selection(select,0);
            selectCol = selection(select,1);
            if(selectRow == 8 or selectCol == 8){
                cout << "Please enter a valid location!" << endl;
            }
            bool can = game.canMove(selectRow, selectCol, 1);
            while(can == false){
                cout << "Please select a movable piece" << endl;
                cin >> select;
                selectRow = selection(select,0);
                selectCol = selection(select,1);
                can = game.canMove(selectRow, selectCol, 1);
            }
        }
        pieceMove = false;
        while(pieceMove == false){
            int selectRow2 = 8;
            int selectCol2 = 8;
            while(selectRow2 == 8 or selectCol2 == 8){
                cout << "Enter the location to move to: " << endl;
                string select2 = "";
                cin >> select2;
                selectRow2 = selection(select2,0);
                selectCol2 = selection(select2,1);
                if(selectRow2 == 8 or selectCol2 == 8){
                    cout << "Please enter a valid location!" << endl;
                }
            }
            pieceMove = game.move(selectRow,selectCol,selectRow2,selectCol2,1);
        }

        win = game.won();
    }
    if(win == 1){
        cout << "White won!" << endl;
    }
    else if(win == 2){
        cout << "Black won!" << endl;
    }

    return 0;
}

int selection(string input, int mode){//Deals with player inputs
    if(mode == 0){
        if(input.find("A")!=std::string::npos){
            return 0;
        }
        else if(input.find("B")!=std::string::npos){
            return 1;
        }
        else if(input.find("C")!=std::string::npos){
            return 2;
        }
        else if(input.find("D")!=std::string::npos){
            return 3;
        }
        else if(input.find("E")!=std::string::npos){
            return 4;
        }
        else if(input.find("F")!=std::string::npos){
            return 5;
        }
        else if(input.find("G")!=std::string::npos){
            return 6;
        }
        else if(input.find("H")!=std::string::npos){
            return 7;
        }
        else{
            return 8;
        }
    }
    else{
        if(input.find("1")!=std::string::npos){
            return 0;
        }
        else if(input.find("2")!=std::string::npos){
            return 1;
        }
        else if(input.find("3")!=std::string::npos){
            return 2;
        }
        else if(input.find("4")!=std::string::npos){
            return 3;
        }
        else if(input.find("5")!=std::string::npos){
            return 4;
        }
        else if(input.find("6")!=std::string::npos){
            return 5;
        }
        else if(input.find("7")!=std::string::npos){
            return 6;
        }
        else if(input.find("8")!=std::string::npos){
            return 7;
        }
        else{
            return 8;
        }
    }
}
