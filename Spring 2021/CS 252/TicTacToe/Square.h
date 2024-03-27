#ifndef SQUARE_H
#define SQUARE_H

class Square{
private:
    char value;

public:
    Square(){
        value = ' ';
    }

    void placeX(){
        value = 'X';
    }

    void placeO(){
        value = 'O';
    }

    char getValue(){
        return value;
    }
};

#endif // SQUARE_H
