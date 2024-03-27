//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef MYARRAY_H
#define MYARRAY_H

#include <stdexcept>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

class MyArray{
private:
    int* theArray;
    int length;
    int maxSize;

public:
    MyArray(){
        theArray = new int[1];
        length = 0;
        maxSize = 1;
    }

    MyArray(int size){
        cout << "Constructor" << endl;
        if(size < 1){
        throw std::invalid_argument("Array size must be greater than 0");
        }
        theArray = new int[size];
        length = 0;
        maxSize = size;
    }

    int getLength(){
    return length;
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

    void resize(){
        int* temp = new int[maxSize*2];
        for(int i = 0; i < length; i++){
            temp[i] = theArray[i];
        }

        delete[] theArray;

        theArray = temp;

        maxSize = maxSize *2;
    }

    int getMaxSize(){
        return maxSize;
    }

    void append(int num){
        if(length == maxSize){
            resize();
        }

        theArray[length] = num;
        length++;
    }

    void trim(){
        int* temp = new int[length];

        for(int i = 0; i < length; i++){
            temp[i] = theArray[i];
        }

        delete[] theArray;

        theArray = temp;

        maxSize = length;
    }

    bool isSorted(){
        int sorted = 0;
        for(int i = 0; i < length - 1; i++){
            if(theArray[i+1] < theArray[i]){
                sorted++;
            }
            else{
            }
        }
        if(sorted == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void selectionSort(){
        int top = 0;
        while(top < length){
            int smallest = top;
            for(int i = top; i < length; i++){
                if(theArray[i] < theArray[smallest]){
                    smallest = i;
                }
            int temp = theArray[top];
            theArray[top] = theArray[smallest];
            theArray[smallest] = temp;
            top++;
            }
        }
    }

    void bubbleSort(){
        bool swapped = true;
        while(swapped == true){
            int current = 0;
            swapped = false;
            while(current < length - 1){
                if(theArray[current] > theArray[current + 1]){
                    int temp = theArray[current];
                    theArray[current] = theArray[current + 1];
                    theArray[current + 1] = temp;
                    swapped = true;
                }
                else{
                }
                current++;
            }
        }
    }

    void insertionSort(){
        for(int i = 1; i < length - 1; i++){
            int j = i;
            while(j > 0 and theArray[j-1] > theArray[j]){
                int temp = theArray[j];
                theArray[j] = theArray[j - 1];
                theArray[j - 1] = temp;
                j--;
            }
        }
    }

    int getRandomNumber(int min, int max){
        static std::mt19937 ran(time(nullptr));
        std::uniform_int_distribution<int>dist(min, max);
        return dist(ran);
    }

    void shuffle(){
        for(int i = length - 1; i > 0; i--){
            int n = getRandomNumber(0,i);
            int temp = theArray[i];
            theArray[i] = theArray[n];
            theArray[n] = temp;
        }
    }

    int linearSearch(int item){
        int found = -1;
        for(int i = 0; i < length; i++){
            if(theArray[i] == item){
                found = theArray[i];
            }
            else{
            }
        }
        return found;
    }

    int binarySearch(int item){
        selectionSort();
        int top = 0;
        int bottom = length - 1;
        int middle = -1;
        while(theArray[middle] != item){
            if(middle == top){
                return -1;
            }
            else{
                if(theArray[middle] < item){
                    top = middle;
                    middle = bottom / 2;
                }
                else{
                    bottom = middle;
                    middle = bottom / 2;
                }
            }
        }
        return middle;
    }


    ~MyArray(){
        cout << "Destructor" << endl;
        delete[] theArray;
    }
};

#endif // MYARRAY_H
