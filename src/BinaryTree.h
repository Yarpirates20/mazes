#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Grid.h"

class BinaryTree
{
public:
   
    /**
     * @brief Randomly choose north or east neighbor to link each cell into the 
     * maze.
     * 
     * @param g Grid to mutate. 
     */
    void on(Grid &g);
};

#endif // BINARYTREE_H