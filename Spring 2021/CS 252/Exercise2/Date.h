//Dawson Tolbert
//CS 252
//Sources: N/A
#ifndef DATE_H
#define DATE_H

class Date{
private:
    int month;
    int day;
    int year;

public:
    Date(){
        month = 1;
        day = 22;
        year = 2020;
    }

    Date(int m, int d, int y){
        month = m;
        day = d;
        year = y;
    }

    int desiredMonth(){
        return month;
    }

    int desiredDay(){
        return day;
    }

    int desiredYear(){
        return year;
    }
};

#endif // DATE_H
