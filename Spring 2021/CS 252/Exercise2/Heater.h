//Dawson Tolbert
//CS 252
//Sources: N/A
#ifndef HEATER_H
#define HEATER_H
#include <string>

using namespace std;

class Heater{
private:
    bool on; //true is on, fales is off
    int goalTemp; //turn off the heater when it reaches this

public:
    Heater(){
        on = false;
        goalTemp = 68;
    }

    Heater(bool status, int desired){
        on = status;
        goalTemp = desired;
    }

    string isOn(){
        if(on == 1){
            return "true";
        }
        else{
            return "false";
        }
    }

    int desiredTemp(){
        return goalTemp;
    }

    void turnOn(){
        on = true;
    }

    void turnOff(){
        on = false;
    }

    void increaseTemp(){
        goalTemp++;
    }

    void decreaseTemp(){
        goalTemp--;
    }

    void setTemp(int goal){
        goalTemp = goal;
    }


};

#endif // HEATER_H
