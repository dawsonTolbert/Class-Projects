#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>

class BST{
private:
    BSTNode* root;

    void insertHelper(BSTNode* node, int info){
        if(node->getInfo() < info){
            if(node->getRight() == nullptr){
                node->setRight(new BSTNode(info, nullptr,nullptr));
            }
            else{
                insertHelper(node->getRight(), info);
            }
        }
        else if(node->getInfo() > info){
            if(node->getLeft() == nullptr){
                node->setLeft(new BSTNode(info, nullptr,nullptr));
            }
            else{
                insertHelper(node->getLeft(), info);
            }
        }
    }

    void inOrderHelper(BSTNode* node){
        if(node == nullptr){
            return;
        }

        inOrderHelper(node->getLeft());
        std::cout << node->getInfo() << std::endl;
        inOrderHelper(node->getRight());
    }

    void preOrderHelper(BSTNode* node){
        if(node == nullptr){
            return;
        }

        std::cout << node->getInfo() << std::endl;
        preOrderHelper(node->getLeft());
        preOrderHelper(node->getRight());
    }

    void postOrderHelper(BSTNode* node){
        if(node == nullptr){
            return;
        }

        preOrderHelper(node->getLeft());
        preOrderHelper(node->getRight());
        std::cout << node->getInfo() << std::endl;
    }

    int minHelper(BSTNode* current){
        if(current->getLeft() == nullptr){
            return current->getInfo();}
        else{
            return minHelper(current->getLeft());
        }
    }

    BSTNode* removeHelper(BSTNode* current, int value){
        if(current == nullptr){ //escape if value doesn't exist
            return current;
        }

        if(value < current->getInfo()){ //Searches left if the value is smaller than current
            current->setLeft(removeHelper(current->getLeft(), value));
        }
        else if(value > current->getInfo()){ //Searches right if the value is bigger than current
            current->setRight(removeHelper(current->getRight(), value));
        }
        else if(value == current->getInfo()){ //Starts removal if value is found, check cases
            if(current->getLeft() == nullptr){ //Checks if there is a left child, if not then you have a 1 child case
                BSTNode* rightChild  = current->getRight();
                delete current;
                return rightChild;
            }
            else if(current->getRight()==nullptr){ //Checks for right child, if not then 1 child case
                BSTNode* leftChild = current->getLeft();
                delete current;
                return leftChild;
            }
            else{ //2 child case
                int minValue = minHelper(current->getRight()); //saves lowest value from right subtree
                current->setInfo(minValue); //swaps min to current

                current->setRight(removeHelper(current->getRight(),minValue)); //deletes the original lowest value node
            }
            return current;
        }

        return current;
    }

public:
    BST(){
        root = nullptr;
    }

    void insert(int info){
        if(root == nullptr){
            root = new BSTNode(info, nullptr,nullptr);
        }
        else{
            insertHelper(root, info);
        }
    }

    void inOrder(){
        inOrderHelper(root);
    }

    void preOrder(){
        preOrderHelper(root);
    }

    void postOrder(){
        postOrderHelper(root);
    }

    int smallest(){
        BSTNode* current = root;
        while(current->getLeft() != nullptr){
            current = current->getLeft();
        }
        return current->getInfo();
    }

    int biggest(){
        BSTNode* current = root;
        while(current->getRight() != nullptr){
            current = current->getRight();
        }
        return current->getInfo();
    }

    bool search(int value){
        BSTNode* current = root;
        while(current != nullptr){
            if(value == current->getInfo()){
                return true;
            }
            else if(value > current->getInfo()){
                current = current->getRight();
            }
            else if(value < current->getInfo()){
                current = current->getLeft();
            }
        }
        return false;
    }

    void remove(int info){
        root = removeHelper(root, info);
    }

    ~BST(){
        while(root != nullptr){
            remove(root->getInfo());
        }
    }

};

#endif // BST_H
