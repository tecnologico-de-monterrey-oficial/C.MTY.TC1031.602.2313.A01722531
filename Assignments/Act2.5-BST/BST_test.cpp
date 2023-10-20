
#include <iostream>
using namespace std;

#include "BST.h"

int main() {
    BST<int> bst;
    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(5);
    bst.insert(35);
    bst.insert(15);
    bst.insert(25);
    bst.insert(1);
    bst.insert(7);
    bst.insert(9);
    bst.insert(14);
    bst.insert(4);
    bst.insert(16);
    bst.insert(13);
    bst.print();

    cout << " find 16: " << bst.find(16) << endl << endl;
    cout << " find 7: " << bst.find(7) << endl << endl;

    cout << "visit" << endl;
    cout << endl;
    bst.visit(1);
    cout << endl;
    bst.visit(2);
    cout << endl;
    bst.visit(3);
    cout << endl;
    bst.visit(4);
    cout << endl;
    
    cout << "height: " << bst.height() << endl << endl;

    cout << " ancestors of 35: ";
    bst.ancestors(35);
    cout << endl;

    cout << " what level am i? 15: " << bst.whatLevelamI(19) << endl << endl;

    bst.remove(13);
    bst.remove(30);
    bst.remove(4);
    bst.remove(1);
    bst.remove(20);
    bst.remove(9);
    bst.remove(14);
    bst.print();

    cout << "find 16: " << bst.find(16) << endl << endl;
    cout << "find 7: " << bst.find(7) << endl << endl;

    cout << "visit" << endl;
    cout << endl;
    bst.visit(1);
    cout << endl;
    bst.visit(2);
    cout << endl;
    bst.visit(3);
    cout << endl;
    bst.visit(4);
    cout << endl;
    
    cout << "height: " << bst.height() << endl << endl;

    cout << "ancestors of 35: ";
    bst.ancestors(35);
    cout << endl;

    cout << "what level am I? 15: " << bst.whatLevelamI(15) << endl << endl;
}