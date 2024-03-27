#ifndef QUEUE_H
#define QUEUE_H

#include "myList.h"

class Queue{
private:
    myList theList;

public:
    Queue(){

    }

    bool empty(){
        if(theList.getLength() == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int item){
        theList.append(item);
    }

    int dequeue(){
        theList.start();
        return theList.removeCurrent();
    }

    int peek(){
        theList.start();
        return theList.getCurrentValue();
    }

    void destroy(){
        theList.~myList();
    }

};

#endif // QUEUE_H
