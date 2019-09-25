#include <iostream>
//#include "tester/tester.h"
#include "bstree.h"
using namespace std;

int main(int argc, char *argv[]) {
   // cout << "===========================================================" << endl;
   // cout << "Binary Search Tree Practice" << endl;
   // cout << "===========================================================" << endl << endl;
//
   // Tester::execute();
   // return EXIT_SUCCESS;
    BSTree<int> a;
    a.insert(4);
    a.insert(7);
    a.insert(2);
    a.insert(1);
    a.insert(8);
    a.insert(9);
    a.insert(18);
    a.insert(6);
    a.insert(3);
    a.insert(12);
    a.traverseInOrder();
}
