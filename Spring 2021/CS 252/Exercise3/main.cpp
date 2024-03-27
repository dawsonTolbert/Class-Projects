#include <iostream>
#include <string>
#include "Date.h"
#include <cassert>

using namespace std;

int getInt(string);

/*
 Test takes a boolean condition and a string identifier.
 If the boolean condition is false, the string prints.
 Example:
 test(1==1, "1==1") - nothing prints
 test(1==2, "1==2") - Test 1==2 failed will print
*/
void test(bool, string);

void testMonth();
void testSeason();
void testRunner(); //contains a series of tests

int main()
{
    bool validDate = false;

    while(validDate == false){
        int month = getInt("Enter a month: ");
        int day = getInt("Enter a day: ");
        int year = getInt("Enter a year: ");

        try{
            Date example(month,day,year);
            cout << example.getMonth() << "/" << example.getDay()
                 << "/" << example.getYear() << endl;
            validDate = true;
        }
        catch(invalid_argument error){
            cout << error.what() << endl;
        }
    }

    return 0;
}

int getInt (string prompt) {
    while (true) {
        cout << prompt;
        int x = 0;
        cin >> x;
        if (cin.fail() or cin.peek() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid Input, try again." << endl;
        }
        else{
            return x;
        }
    }
}

void test(bool cond, string title){
    if(cond == false){
        cout << "Test " << title << " failed" << endl;
    }
}

void testMonth(){
    Date january(1,2,2021);
    test(january.englishMonth() == "January", "January test");
}

void testSeason(){
    Date august(8,7,2021);
    test(august.season() == "Summer", "August summer test");
}

void testLeap(){
    Date feb2020(2,1,2020);
    test(feb2020.isLeapYear(2020) == true, "Leap year test 1");
    Date feb2021(2,1,2021);
    test(feb2021.isLeapYear(2021) == false, "Leap year test 2");
    Date jan2016(1,1,2016);
    test(jan2016.isLeapYear(2016) == true, "Leap year test 3");
    Date dec2023(12,1,2023);
    test(dec2023.isLeapYear(2023) == true, "Leap year test 4");
    Date feb2017(2,30,2017);
    test(feb2017.isLeapYear(2017) == false, "Leap year test 5");
}

void testRunner(){
    cout << "Running Tests" << endl;
    testMonth();
    testSeason();
    testLeap();
    cout << "End of Test Runner" << endl;
}
