#include <iostream>

using namespace std;

#include "FileReader.h"
#include "Grid.h"
#include "Simulation.h"

int main()
{
    string inputFileName = "";
    cout << "Enter an input file: " << endl;
    cin >> inputFileName;

    FileReader reader(inputFileName);
    Grid map = reader.getGrid();

    int simCount = 0;
    cout << "Enter the number of simulations you want to run: " << endl;
    cin >> simCount;

    int starve = 0;
    int eaten = 0;
    int drown = 0;
    int escape = 0;
    while(simCount != 0){
        Simulation sim(map);

//        cout << sim.simulate() << endl;

        string x = sim.simulate();
        if(x == "starve"){
            starve++;
            cout << "The Mouse Starved." << endl;
        }
        else if(x == "eaten"){
            eaten++;
            cout << "The Mouse was Eaten." << endl;
        }
        else if(x == "drown"){
            drown++;
            cout << "The Mouse Drowned." << endl;
        }
        else if(x == "escape"){
            escape++;
            cout << "The Mouse Escaped!" << endl;
        }

        if(simCount - 1 != 0){
            cout << "-----------------" << endl;
            cout << "Simulation ended, resetting..." << endl;
            cout << "-----------------" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        }

        simCount--;
    }
    cout << "The Mouse Starved " + std::to_string(starve) + " times \n"
            "The Mouse Drowned " + std::to_string(drown) + " times \n"
            "The Mouse was Eaten " + std::to_string(eaten) + " times \n"
            "The Mouse Escaped " + std::to_string(escape) + " times \n"
         << endl;

    return 0;
}

