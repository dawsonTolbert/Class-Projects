//Dawson Tolbert
//CS 252
//Sources: N/A

#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST theTree;

    theTree.insert(50);
    theTree.insert(40);
    theTree.insert(60);
    theTree.insert(45);
    theTree.insert(70);

    theTree.inOrder();
    cout << "------------" << endl;
    theTree.preOrder();
    cout << "------------" << endl;
    theTree.postOrder();
    cout << "------------" << endl;
    cout << "Smallest: " << theTree.smallest() << endl;
    cout << "Biggest: " << theTree.biggest() << endl;
    cout << "------------" << endl;
    cout << "70 in tree? " << theTree.search(70) << endl;
    cout << "13 in tree? " << theTree.search(13) << endl;


    return 0;
}
