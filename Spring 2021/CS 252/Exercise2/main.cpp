//Dawson Tolbert
//CS 252
//Sources: N/A
#include <iostream>
#include "Heater.h"
#include "Date.h"

using namespace std;

int main()
{
    cout << "Hello!" << endl;

    Heater kitchen; //default settings
    Heater livingRoom(false, 70); //specific settings
    cout << "Living room heater on? " << livingRoom.isOn() << endl;

    cout << "The kitchen heater's goal is " << kitchen.desiredTemp() << endl;

    kitchen.increaseTemp();
    kitchen.increaseTemp();

    cout << "The kitchen heater's goal is now " << kitchen.desiredTemp() << endl;

    Date jan2220;
    Date jan3121(1, 31, 2021);
    cout << "The year is " << jan3121.desiredYear() << endl;

    cout << "Goodbye!" << endl;
    return 0;
}
