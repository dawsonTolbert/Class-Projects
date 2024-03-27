//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "MyArray.h"

using namespace std;

int main()
{
    MyArray example(5);

    cout << "The length is: " << example.getLength() << endl;

    example.setValue(0,42);
    example.setValue(1,2);
    example.setValue(2,85);
    example.setValue(3,14);
    example.setValue(4,0);

    for(int i = 0; i < example.getLength(); i++){
        cout << "The value at position " << i << " is: " << example.getValue(i) << endl;
    }

    cout << "The average is: " << example.average() << endl;
    cout << "The largest number is: " << example.largest() << endl;
    cout << "The smallest number is: " << example.smallest() << endl;
    cout << "The difference is: " << example.difference() << endl;

    example.reverse();
    cout << example.getValue(0) << endl;
    cout << "Reverse array: " << endl;
    for(int i = 0; i < example.getLength(); i++){
        cout << "The value at position " << i << " is: " << example.getValue(i) << endl;
    }

    example.wipe();

    return 0;
}
