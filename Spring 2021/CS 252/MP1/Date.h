//Dawson Tolbert
//CS 252
//Sources: N/A
#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;

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

    string dash(){
        return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    }

    string slash(){
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }

    string monthName(){
        switch(month){
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "ERROR";
        }
    }

    string monthDY(){
        return monthName() + " " + to_string(day) + ", " + to_string(year);
    }

    string dayOTWeek(){
        int step1 = year - (14 - month) / 12;
        int step2 = step1 + step1/4 - step1/100 + step1/400;
        int step3 = month + 12 * ((14 - month) / 12) - 2;
        int result = (day + step2 + (31*step3)/12) % 7;
        switch(result){
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thrusday";
        case 5: return "Friday";
        case 6: return "Saturday";
        case 7: return "Sunday";
        default: return "ERROR";
        }
    }

    string dayMonthDY(){
        return dayOTWeek() + ", " + monthDY();
    }

    string season(){
        if(3 == month){
            if(day >= 21){
                return "Spring";
            }
            else{
                return "Winter";
            }
        }
        else if(month > 3 and month < 6){
            return "Spring";
        }
        else if(month == 6){
            if(day >= 21){
                return "Summer";
            }
            else{
                return "Spring";
            }
        }
        else if(month > 6 and month < 9){
            return "Summer";
        }
        else if(month == 9){
            if(day >= 23){
                return "Fall";
            }
            else{
                return "Summer";
            }
        }
        else if(month > 9 and month < 12){
            return "Fall";
        }
        else if(month == 12){
            if(day >= 21){
                return "Winter";
            }
            else{
                return "Fall";
            }
        }
        else if(month < 3){
            return "Winter";
        }
        else{
            return "Spring";
        }
    }

    string inDepthDate(){
        return monthDY() + " is a " + dayOTWeek() + ". It is in the " + season();
    }
};

#endif // DATE_H
