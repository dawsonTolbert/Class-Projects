//Dawson Tolbert
//CS 252
//Sources: http://www.cplusplus.com/reference/string/string/find/

#ifndef SQUARE_H
#define SQUARE_H

class Square{
private:
    int value;

public:
    Square(){
        value = 0;
    }

    void setValue(int value){
        this->value = value;
    }

    int getValue(){
        return value;
    }
};

#endif // SQUARE_H
