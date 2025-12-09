#include "Grid.h"
#include "BinaryTree.h"
#include "Sidewinder.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{

    Grid g(5,5);

    
    BinaryTree bt;
    bt.on(g);

    cout << g << endl; 

    Grid g2(5, 5);
    Sidewinder side;
    side.on(g2);

    cout << g2 << endl;

    return 0;
}