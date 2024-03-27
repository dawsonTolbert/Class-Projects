#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class Date{
private:
    int month;
    int day;
    int year;

public:
    Date(){
        month = 2;
        day = 7;
        year = 2021;
    }

    bool isLeapYear(int year){
        if(year % 4 != 0){
            return false; //common year
        }
        else if(year % 100 != 0){ //leap year
            return true;
        }
        else if(year % 400 != 0){ //common year
            return false;
        }
        else{
            return true;
        }
    }

    void setMonth(int month){
        if(month < 1 or month > 12){
            throw std::invalid_argument("Invalid Month!");
        }
        else{
            this->month = month;
        }
    }

    void setDay(int day){
        if(day < 1 or day > 31){
            throw std::invalid_argument("Invalid Day! Must be in the range 1 to 31");
        }
        else if(day > daysInMonth(month)){
            throw std::invalid_argument("Invalid Day! Month doesn't have that many days.");
        }
        else{
            this->day = day;
        }
    }

    void setYear(int year){
        if(year < 1){
            throw std::invalid_argument("Invalid Year! Must be a positive number!");
        }
        else{
            this->year = year;
        }
    }

    Date(int month, int day, int year){
        setMonth(month);
        setDay(day);
        setYear(year);
    }

    int getMonth(){
        return month;
    }

    int getDay(){
        return day;
    }

    int getYear(){
        return year;
    }

    std::string dash(){
        return std::to_string(month) + "-" + std::to_string(day) + "-" +
               std::to_string(year);
    }

    std::string dMY(){
        return std::to_string(day) + "-" + std::to_string(month) + "-" +
               std::to_string(year);
    }

    std::string slash(){
        return std::to_string(month) + "/" + std::to_string(day) + "/" +
               std::to_string(year);
    }

    std::string englishMonth(){
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
            default: return "Error";
        }
    }

    std::string dayOfWeek(){
        int step1 = year - (14 - month) / 12;
        int step2 = step1 + step1/4 - step1/100 + step1/400;
        int step3 = month + 12 * ((14-month) / 12) - 2;
        int result = (day + step2 + (31 * step3)/12) % 7;

        switch(result){
            case 0: return "Sunday";
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
            default: return "Error";
        }
    }

    std::string longDate(){
        return dayOfWeek() + ", " + englishMonth() + " " +
               std::to_string(day) + ", " + std::to_string(year);
    }

    std::string season(){
        if(month == 3 and day >= 21){
            return "Spring";
        }
        else if(month == 4 or month == 5){
            return "Spring";
        }
        else if(month == 6 and day <= 20){
            return "Spring";
        }
        else if(month == 6 and day >= 21){
            return "Summer";
        }
        else if(month == 7 or month == 8){
            return "Summer";
        }
        else if(month == 9 and day <= 22){
            return "Summer";
        }
        else if(month == 9 and day >= 23){
            return "Fall";
        }
        else if(month == 10 or month == 11){
            return "Fall";
        }
        else if(month == 12 and day <= 21){
            return "Fall";
        }
        else if(month == 12 and day >= 22){
            return "Winter";
        }
        else if(month == 1 or month == 2){
            return "Winter";
        }
        else if(month == 3 and day <= 20){
            return "Winter";
        }
        else{
            return "Error";
        }
    }

    std::string seasonDate(){
        return englishMonth() + " " + std::to_string(day) + ", " +
               std::to_string(year) + " is a " + dayOfWeek() + ". " +
               "It is in the " + season() + ".";
    }

    int daysInMonth(int month){
        switch(month){
            case 1: return 31;
            case 2: return 29;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return -1;
        }
    }
};

#endif // DATE_H
