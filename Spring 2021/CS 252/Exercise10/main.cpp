//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "myList.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"

using namespace std;

int main()
{
    Queue theQueue;

    theQueue.enqueue(42);
    theQueue.enqueue(24);

    cout << theQueue.peek() << endl;
    theQueue.enqueue(3);
    while(theQueue.empty() == false){
        cout << theQueue.dequeue() << endl;
    }
    theQueue.enqueue(3);
    cout << "Empty? " << theQueue.empty() << endl;

    cout << "------------------" << endl;

    Stack theStack;

    theStack.push(2);
    theStack.push(4);
    cout << theStack.peek() << endl;
    cout << theStack.pop() << endl;
    cout << theStack.peek() << endl;

    cout << "------------------" << endl;

    Deque theDeque;

    theDeque.addFront(2);
    theDeque.addFront(4);
    cout << theDeque.getRear() << endl;
    theDeque.addFront(6);
    cout << theDeque.getFront() << endl;
    theDeque.removeFront();
    cout << theDeque.getFront() << endl;
    theDeque.removeRear();
    cout << theDeque.getRear() << endl;

    return 0;
}
