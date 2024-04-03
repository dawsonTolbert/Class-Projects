//Dawson Tolbert
//CS 442

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Trie.h"

using namespace std;

int main()
{
    Trie theTrie;

    //grid to hold chars from boggle grid
    char grid[4][4];
    //grid to mark each char as visited or unvisited
    int marked[4][4];

    cout << "Please enter a boggle grid txt file: ";
    string input;
    cin >> input;

    //open file containing boggle grid
    ifstream file;
    file.open(input);

    int cLen = 4;
    int rLen = 4;
    int solns = 0;

    file >> solns;
    for(int i = 0; i < cLen; i++){
        for(int j = 0; j < rLen; j++){
            file >> grid[i][j];
        }
    }

    //close file
    file.close();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cout<< grid[i][j];
        cout<<endl;
    }

    //create a list to contain all the valid words found
    list<string> wordList;

    //open file containing dictionary
    ifstream fileIn("boggleDictionary.txt");

    string line;

    //insert each line as string to the Trie
    while(getline(fileIn, line)){
        theTrie.insertString(line);
    }

    //Perform DFS on boggle grid starting at each possible 4x4 location
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            theTrie.dfs(i, j, theTrie.getRoot(), "", grid, marked, wordList);
        }
    }

    // Create and open a text file
    ofstream output("solution.txt");

    output << wordList.size() << " valid words found:\n";

    // loop through word list of words found, write each word to file
    for(auto v : wordList){
        output << v << "\n";
    }

    // Close the file
    output.close();


    return 0;
}


