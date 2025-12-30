#include "include/Cell.h"
#include "include/Grid.h"
#include "include/BinaryTree.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    Grid g(6, 6);
    BinaryTree bin_tree;
    bin_tree.on(g);

    cout << g;
    return 0;
}