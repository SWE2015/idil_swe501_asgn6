#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree myTree;

    srand(time(0));

    myTree.InsertItem(15);

    for(int i=0; i<15; i++){
        int a = rand()%100+1;
        myTree.InsertItem(a);
    }

    bool found = false;
    int a = 15;
    myTree.RetrieveItem(a, found);
    cout << "\nCheck RetrieveItem function - should be true: " << found << endl;

    cout << "\nPrint tree from left to right:" << endl;
    myTree.Print();

    cout << "\n\nPrint same tree after deleting an item: " << endl;
    myTree.DeleteItem(15);
    myTree.Print();

    return 0;
}
