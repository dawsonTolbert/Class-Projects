#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <list>
#include <iostream>
#include <algorithm>

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode(' ');
    }

    TrieNode* getRoot(){
        return root;
    }

    void insertString(string str){
        //make sure string isn't already in the Trie
        if(search(str) == false){
            TrieNode *current = root;
            //loop through chars in string to insert each char into trie
            for(int i = 0; i < str.length(); i++){
                //insert child only if it doesn't already exist, avoids duplicates
                if(current->hasChild(str[i]) == nullptr){
                    current->insertChild(str[i]);
                }
                //set current to child
                current = current->hasChild(str[i]);
            }
            //insert a period to finish a string in the trie
            current->insertChild('.');
        }
    }

    bool search(string str){
        TrieNode *current = root;
        for(int i = 0; i < str.length(); i++){
            if(current->hasChild(str[i]) == nullptr){
                return false;
            }
            else{
                current = current->hasChild(str[i]);
            }
        }
        if(current->hasChild('.') != nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void dfs(int row, int col, TrieNode* current, string word, char grid[4][4], int marked[4][4], list<string>& wordList){
        //If row or column is outside board bounds, return
        if(row < 0 or col < 0 or row > 3 or col > 3){
            return;
        }

        //If char at row,col isn't in the current's children, return
        if(current->hasChild(grid[row][col]) == nullptr){
            return;
        }

        //If row,col has already been visited, return
        if(marked[row][col] == 1){
            return;
        }

        word += grid[row][col];

        bool validWord = search(word);
        if(validWord == true){
            if(std::find(wordList.begin(), wordList.end(), word) != wordList.end()){

            }
            else{
                wordList.push_back(word);
            }
        }

        current = current->hasChild(grid[row][col]);
        marked[row][col] = 1;

        dfs(row+1, col+1, current, word, grid, marked, wordList);
        dfs(row, col+1, current, word, grid, marked, wordList);
        dfs(row-1, col+1, current, word, grid, marked, wordList);
        dfs(row+1, col, current, word, grid, marked, wordList);
        dfs(row+1, col-1, current, word, grid, marked, wordList);
        dfs(row, col-1, current, word, grid, marked, wordList);
        dfs(row-1, col-1, current, word, grid, marked, wordList);
        dfs(row-1, col, current, word, grid, marked, wordList);

        //Search finished, mark each cell as unvisited
        marked[row][col] = 0;
    }
};

#endif // TRIE_H
