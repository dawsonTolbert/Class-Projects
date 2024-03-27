//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{
    myList list;

    int option = 1;
    while(option != 0){
        cout << "0: Exit \n"
                "1: Prepend \n"
                "2: Append \n"
                "3: Begin \n"
                "4: End \n"
                "5: Next \n"
                "6: Previous \n"
                "7: Remove \n"
                "8: Length \n"
                "9: Current Value \n"
                "10: Set Value \n"
                "11: Reverse List \n"
                "12: Print List" << endl;
        cout << "Enter a number: " << endl;
        cin >> option;
        if(option == 0){
            break;
        }
        if(option == 1){
            int value;
            cout << "Enter a value: " << endl;
            cin >> value;
            list.prepend(value);
        }
        else if(option == 2){
            int value;
            cout << "Enter a value: " << endl;
            cin >> value;
            list.append(value);
        }
        else if(option == 3){
            list.begin();
        }
        else if(option == 4){
            list.last();
        }
        else if(option == 5){
            list.next();
        }
        else if(option == 6){
            list.previous();
        }
        else if(option == 7){
            list.remove();
        }
        else if(option == 8){
            cout << list.getLength() << endl;
        }
        else if(option == 9){
            cout << list.currentValue() << endl;
        }
        else if(option == 10){
            int place;
            cout << "Enter which number node: " << endl;
            cin >> place;
            int value;
            cout << "Enter a value: " << endl;
            cin >> value;
            list.set(place,value);
        }
        else if(option == 11){
            list.reverse();
        }
        else if(option == 12){
            int count = 0;
            int temp = list.getLength();
            list.begin();
            while(count < temp){
                cout << list.currentValue() << endl;
                list.next();
                count++;
            }
        }
        else{
            cout << "Invalid Input!" << endl;
        }
    }

    return 0;
}
