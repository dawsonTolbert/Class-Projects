//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "MyArray.h"

using namespace std;

int main()
{
    MyArray example;

    for(int i = 0; i < 10; i++){
        example.append(i);
        cout << "Appending" << i << "max size is now "
             << example.getMaxSize() << endl;
    }

    example.trim();
    cout << "Trimmed the array. Max size is now: "
         << example.getMaxSize() << endl;

    return 0;
}
