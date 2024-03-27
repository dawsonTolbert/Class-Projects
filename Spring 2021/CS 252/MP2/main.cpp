//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "MyArray.h"

using namespace std;

void printArray(MyArray);
void selectTest();
void bubbleTest();
void insertionTest();

int main()
{
    MyArray example;

    for(int i = 0; i < 10; i++){
        example.append(i);
        cout << "Appending " << i << " max size is now "
             << example.getMaxSize() << endl;
    }

    example.trim();
    cout << "Trimmed the array. Max size is now: "
         << example.getMaxSize() << endl;

    printArray(example);
    cout << "Is sorted? " << example.isSorted() << endl;
    cout << example.binarySearch(8) << endl;

    cout << "Select test: " << endl;
    selectTest();
    cout << "Bubble test: " << endl;
    bubbleTest();
    cout << "Insertion test: " << endl;
    insertionTest();

    cout << "Shuffle: " << endl;
    example.shuffle();
    printArray(example);

    example.insertionSort();
    cout << "Is sorted? " << example.isSorted() << endl;

    cout << example.linearSearch(8) << endl;

    return 0;
}

void printArray(MyArray array){
    for(int i = 0; i < array.getLength(); i++){
        cout << array.getValue(i) << endl;
    }
}

void selectTest(){
    MyArray example;

    for(int i = 0; i < 10; i++){
        example.append(i);
    }

    example.setValue(0,42);
    example.setValue(1,99);
    example.setValue(9,56);
    bool result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }

    example.selectionSort();

    result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }
}

void bubbleTest(){
    MyArray example;

    for(int i = 0; i < 10; i++){
        example.append(i);
    }

    example.setValue(0,42);
    example.setValue(1,99);
    example.setValue(9,56);
    bool result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }

    example.bubbleSort();

    result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }
}

void insertionTest(){
    MyArray example;

    for(int i = 0; i < 10; i++){
        example.append(i);
    }

    example.setValue(0,42);
    example.setValue(1,99);
    example.setValue(9,56);
    bool result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }

    example.insertionSort();

    result = example.isSorted();
    if(result == true){
        cout << "Sorted!" << endl;
    }
    else{
        cout << "Not sorted!" << endl;
    }
}
