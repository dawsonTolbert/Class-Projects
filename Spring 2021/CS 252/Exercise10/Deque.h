#ifndef DEQUE_H
#define DEQUE_H

#include "myList.h"

class Deque{
private:
    myList theList;

public:
    Deque(){

    }

    void addFront(int item){
        theList.prepend(item);
    }

    void addRear(int item){
        theList.append(item);
    }

    void removeFront(){
        theList.start();
        theList.removeCurrent();
    }

    void removeRear(){
        theList.end();
        theList.removeCurrent();
    }

    int getFront(){
        theList.start();
        return theList.getCurrentValue();
    }

    int getRear(){
        theList.end();
        return theList.getCurrentValue();
    }
};

#endif // DEQUE_H
