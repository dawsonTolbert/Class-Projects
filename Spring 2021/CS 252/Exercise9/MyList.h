//Dawson Tolbert
//CS 252
//Sources: N/A

#ifndef MYLIST_H
#define MYLIST_H

#include "Node.h"

class myList{
private:
    Node* head;
    Node* end;
    Node* current;
    int length;

public:
    myList(){
        head = nullptr;
        end = nullptr;
        current = nullptr;
        length = 0;
    }

    void prepend(int item){
        if(head == nullptr){
            head = new Node(item,nullptr);
        }
        else{
            Node* temp = new Node(item,head);
            head = temp;
        }
    }

    void append(int item){
        if(head == nullptr){
            head = new Node(item,nullptr);
            end = head;
        }
        else{
            end->setNext(new Node(item,nullptr));
            end = end->getNext();
        }
        length++;
    }

    void begin(){
        current = head;
    }

    void last(){
        current = end;
    }

    void next(){
        current = current->getNext();
    }

    void previous(){
        Node* temp;
        temp = head;
        while(temp < current - 1){
            temp = temp->getNext();
        }
        current = temp;
    }

    int remove(){
        int temp;
        temp = current->getInfo();
        delete current;
        return temp;
    }

    int getLength(){
        return length;
    }

    int currentValue(){
        return current->getInfo();
    }

    void set(int place, int value){
        Node* current = head;
        for(int i = 1; i < place; i++){
            current = current->getNext();
        }
        current->setInfo(value);
    }

    void reverse(){
        Node* top = head;
        current = end;
        int topCount = 1;
        int bottomCount = length;

        while(topCount < bottomCount){
            int topVal = top->getInfo();
            int botVal = current->getInfo();
            top->setInfo(botVal);
            current->setInfo(topVal);
            top = top->getNext();
            previous();
            topCount++;
            bottomCount--;
        }
    }
};

#endif // MYLIST_H
