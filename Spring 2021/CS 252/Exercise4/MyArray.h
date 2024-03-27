//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef MYARRAY_H
#define MYARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

class MyArray{
private:
    int* theArray;
    int length;

public:
    MyArray(int size){
        cout << "Constructor" << endl;
        if(size < 1){
        throw std::invalid_argument("Array size must be greater than 0");
        }
        theArray = new int[size];
        length = size;
    }

    int getLength(){
    return length;
    }

    ~MyArray(){
        cout << "Destructor" << endl;
        delete[] theArray;
    }

    void setValue(int position, int value){
        if(position < 0 or position >= length){
            throw std::invalid_argument("Invalid position!");
        }
        theArray[position] = value;
    }

    int getValue(int position){
        if(position < 0 or position >= length){
            throw std::invalid_argument("Invalid position!");
        }        return theArray[position];
    }

    void wipe(){
        for(int i = 0; i < length; i++){
            theArray[i]= 0;
        }
    }

    bool isEmpty(){
        for(int i = 0; i < length; i++){
            if(theArray[i] != 0){
                return false;
            }
        }
        return true;
    }

    double average(){
        double total = 0;
        for(int i = 0; i < length; i++){
            total = total + theArray[i];
        }
        return total / length;
    }

    int largest(){
        int biggest = theArray[0];

        for(int i = 0; i < length; i++){
            if(theArray[i] > biggest){
                biggest = theArray[i];
            }
        }
        return biggest;
    }

    int smallest(){
        int smallest = theArray[0];

        for(int i = 0; i < length; i++){
            if(theArray[i] < smallest){
                smallest = theArray[i];
            }
        }
        return smallest;
    }

    int difference(){
        return largest() - smallest();
    }

    void reverse(){
        int top = 0;
        int bottom = length - 1;

        while(top < bottom){
            int temp = theArray[top];
            theArray[top] = theArray[bottom];
            theArray[bottom] = temp;
            top++;
            bottom--;
        }
    }
};

#endif // MYARRAY_H
