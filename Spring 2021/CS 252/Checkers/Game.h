//Dawson Tolbert
//CS 252
//Sources: http://www.cplusplus.com/reference/string/string/find/

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "BoardPrinter.h"

class Game{
private:
    Board board;
    BoardPrinter printer;

public:
    Game(Board board){
        this->board = board;
    }

    bool possible(int pieceRow, int pieceCol, int row, int col, int piece){
        if(board.getPosition(row,col) == 1){//checks if the move is to a black square (possible move)

            if(piece == 4 or piece == 5){//checks for king pieces

                if(row >= pieceRow - 2 and row <= pieceRow + 2){//makes sure move is in 1 square move or piece jump range
                    if(col >= pieceCol - 2 and col <= pieceCol + 2){//^^^
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }

            else if(piece == 2){//checks for O piece moving up
                if(row >= pieceRow - 2){
                    if(col >= pieceCol - 2 and col <= pieceCol + 2){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }

            else if(piece == 3){//checks for + piece moving down
                if(row <= pieceRow + 2){
                    if(col >= pieceCol - 2 and col <= pieceCol + 2){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        else if(board.getPosition(row,col) == 0){//checks if the move is to a white/red square (impossible)
            return false;
        }
    }

    bool occupied(int row, int col){
        int move = board.getPosition(row,col);
        if(move == 2 or move == 3 or move == 4 or move == 5){
            return true;
        }
        else{
            return false;
        }
    }

    bool canMove(int pieceRow, int pieceCol, int player){
        int piece = board.getPosition(pieceRow, pieceCol);
        if(player == 0){

            if(piece == 2 or piece == 4){//valid pieces for player 0 to move
                return true;
            }
            else{
                return false;
            }
        }
        else if(player == 1){

            if(piece == 3 or piece == 5){//valid pieces for player 1 to move
                return true;
            }
            else{
                return false;
            }
        }
    }

    bool move(int pieceRow, int pieceCol, int row, int col, int player){
        int piece = board.getPosition(pieceRow, pieceCol);
        if(player == 0){

            if(piece == 2 or piece == 4){//valid pieces for player 0 to move
                bool possible = this->possible(pieceRow,pieceCol,row,col,piece);
                bool occupied = this->occupied(row,col);
                if(possible == true and occupied == false){
                    if(row == 0){//Kings piece if it reaches other end of board
                        board.setPosition(row,col,4);
                    }
                    else{
                        board.setPosition(row,col,piece);
                    }
                    board.setPosition(pieceRow,pieceCol,1);
                    if(row == pieceRow - 2 and col == pieceCol - 2){
                        board.setPosition(pieceRow - 1,pieceCol - 1,1);
                    }
                    else if(row == pieceRow - 2 and col == pieceCol + 2){
                        board.setPosition(pieceRow - 1,pieceCol + 1,1);
                    }
                    else if(row == pieceRow + 2 and col == pieceCol - 2){
                        board.setPosition(pieceRow + 1,pieceCol - 1,1);
                    }
                    else if(row == pieceRow + 2 and col == pieceCol + 2){
                        board.setPosition(pieceRow + 1,pieceCol + 1,1);
                    }
                    print(board);
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else if(player == 1){

            if(piece == 3 or piece == 5){//valid pieces for player 1 to move
                bool possible = this->possible(pieceRow,pieceCol,row,col,piece);
                bool occupied = this->occupied(row,col);
                if(possible == true and occupied == false){
                    if(row == 7){//Kings piece if it reaches other end of board
                        board.setPosition(row,col,5);
                    }
                    else{
                        board.setPosition(row,col,piece);
                    }
                    board.setPosition(pieceRow,pieceCol,1);
                    if(row == pieceRow - 2 and col == pieceCol - 2){
                        board.setPosition(pieceRow - 1,pieceCol - 1,1);
                    }
                    else if(row == pieceRow - 2 and col == pieceCol + 2){
                        board.setPosition(pieceRow - 1,pieceCol + 1,1);
                    }
                    else if(row == pieceRow + 2 and col == pieceCol - 2){
                        board.setPosition(pieceRow + 1,pieceCol - 1,1);
                    }
                    else if(row == pieceRow + 2 and col == pieceCol + 2){
                        board.setPosition(pieceRow + 1,pieceCol + 1,1);
                    }
                    print(board);
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    int won(){//checks if there are any white/black pieces left on the board, if not then opposite side wins
        bool blackFound = false;
        bool whiteFound = false;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                int place = board.getPosition(i,j);
                if(place == 5 or place == 3){
                    blackFound = true;
                }
                else if(place == 2 or place == 4){
                        whiteFound = true;
                }
            }
        }
        if(whiteFound == false){
            return 2;
        }
        else if(blackFound == false){
            return 1;
        }
        else{
            return 0;
        }
    }

    void print(Board playBoard){
        printer.printBoard(playBoard);
    }

    std::string play(int mode){
        Board playBoard = board;
        printer.printBoard(playBoard);
    }
};

#endif // GAME_H
