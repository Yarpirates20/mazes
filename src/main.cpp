#include "include/Cell.h"
#include "include/Grid.h"
#include "include/BinaryTree.h"
#include "include/Sidewinder.h"
#include "include/bitmap_image.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // Grid g(5, 5);
    // Sidewinder sw;
   
    // sw.on(g);

    // cout << g;
    
    Grid g(10, 10);
    BinaryTree bin_tree;
    bin_tree.on(g);

    cout << g;

    g.render_bitmap();

    return 0;
}