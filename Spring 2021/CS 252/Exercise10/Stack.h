#ifndef STACK_H
#define STACK_H

#include "myList.h"

class Stack{
private:
    myList theList;

public:
    Stack(){

    }

    void push(int item){
        theList.prepend(item);
    }

    int pop(){
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

#endif // STACK_H
