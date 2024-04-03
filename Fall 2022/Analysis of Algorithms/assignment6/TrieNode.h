#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>
#include <iostream>

using namespace std;

class TrieNode{
private:
    char character;
    vector<TrieNode*> vec;

public:
    TrieNode(char c){
        character = c;
    }

    char getChar(){
        return this->character;
    }


    TrieNode* hasChild(char c){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i]->getChar() == c){
                return vec[i];
            }
        }
        return nullptr;
    }

    void insertChild(char c){
        TrieNode* newNode = new TrieNode(c);
        vec.push_back(newNode);
    }


};

#endif // TRIENODE_H
