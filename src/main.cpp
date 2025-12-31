#include "include/Cell.h"
#include "include/Grid.h"
#include "include/BinaryTree.h"
#include "include/Sidewinder.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    Grid g(5, 5);
    Sidewinder sw;
   
    sw.on(g);

    cout << g;
    
    // Grid g(7, 10);
    // BinaryTree bin_tree;
    // bin_tree.on(g);

    // cout << g;
    return 0;
}