//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void createVector();
int returnMode(vector<int> vector);
float returnMedian(vector<int> vector);
void writeSort(vector<int> vector);

int main()
{
    cout << "Hello World!" << endl;

    vector<int> example;
    example.push_back(1);
    example.push_back(2);
    example.push_back(3);
    example.push_back(2);

    cout << returnMode(example) << endl;
    cout << returnMedian(example) << endl;
    writeSort(example);

    createVector();

    return 0;
}

void createVector(){
    string inputFileName = "";
    cout << "Please enter a file name: ";
    cin >> inputFileName;

    ifstream inputFile;

    inputFile.open(inputFileName);

    if(inputFile.is_open()){
        string line;
        vector<int> v;

        cout << "Reading File... " << endl;
        while(inputFile.good()){ //if the file is in the good state
            getline(inputFile, line);

            int conversion = stoi(line);
            v.push_back(conversion);

            cout << line << endl; //print the line
        }

        cout << "Printing Vector... " << endl;
        for(int item : v){
                cout << item << endl;
            }
        inputFile.close(); //close the file
    }
    else{ //give a message if the file isn't open
        cout << "Invalid File Name" << endl;
    }
}

int returnMode(vector<int> vector){
    int count = 0;
    int prevCount = 0;
    int mode = 0;

    int length = vector.size();
    for(int i = 0; i < length; i++){
        int startingNum = vector.at(i);
        for(int i2 = 0; i2 < length; i2++){
            if(vector.at(i2) == startingNum){
                count++;
            }
            else{
            }
            if(count > prevCount){
                mode = startingNum;
            }
            else{
            }
        }
        prevCount = count;
        count = 0;
    }
    return mode;
}

float returnMedian(vector<int> vector){
    int length = vector.size();
    if(length % 2 != 0){
        return vector.at(length / 2);
    }
    else{
        return (vector.at(length/2.0) + vector.at(length/2.0 - 1)) / 2.0;
    }
}

void writeSort(vector<int> vector){
    string outputFileName = "";
    cout << "Please enter a file name: ";
    cin >> outputFileName;

    ofstream outputFile;

    outputFile.open(outputFileName);
    if(outputFile.is_open()){
            outputFile << "Median: " << returnMedian(vector) << endl;
            outputFile << "Mode: " << returnMode(vector) << endl;
            for(int item : vector){
                    outputFile << item << endl;
                }
            outputFile.close();
        }
        else {
            cout << "Invalid File Name" << endl;
        }
}
