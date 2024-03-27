//Dawson Tolbert
//CS 252
//Sources: N/A
#include <iostream>
#include "Date.h"
#include <string>

using namespace std;

//Function Prototypes
int getInt(string prompt);

int main()
{
    cout << "Hello!" << endl;

    Date jan2220;

    int leapYear = 0;

    int year = getInt("Enter the number year: ");
    if(year % 4 != 0){
        leapYear = 0;
    }
    else if(year % 100 != 0){
        leapYear = 1;
    }
    else if(year % 400 != 0){
        leapYear = 0;
    }
    else{
        leapYear = 1;
    }

    int month = getInt("Enter the number month: ");
    while(month < 0 or month > 12){
        cout << "You must enter a valid month: " << endl;
        month = getInt("Enter the number month: ");
    }

    int day = getInt("Enter the number day: ");
    while(day < 0 or day > 31){
        cout << "You must enter a valid day: " << endl;
        day = getInt("Enter the number day: ");
    }
    if(month == 2 and day > 28){
        if(leapYear == 1){
            while(day > 29){
                cout << "You must enter a valid day: " << endl;
                day = getInt("Enter the number day: ");
            }
        }
        else{
            while(day > 28){
                cout << "You must enter a valid day: " << endl;
                day = getInt("Enter the number day: ");
            }
        }
    }
    else{
        while(day > 30){
            cout << "You must enter a valid day: " << endl;
            day = getInt("Enter the number day: ");
        }
    }

    Date userDate(month, day, year);
    cout << "The day is " << userDate.dayOTWeek() << endl;
    cout << "The season is " << userDate.season() << endl;

    cout << "Goodbye!" << endl;
    return 0;
}

int getInt(string prompt){
    while(true){
        cout << prompt;
        int x = 0;
        cin >> x;
        if(cin.fail()or cin.peek() != '\n'){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid Input, try again." << endl;
        }
        else{
            return x;
        }
    }
}
