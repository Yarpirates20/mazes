#include "Grid.h"
#include "BinaryTree.h"

#include <iostream>

int main(int argc, char *argv[])
{

    Grid g(4,4);

    
    BinaryTree bt;
    bt.on(g);

    return 0;
}