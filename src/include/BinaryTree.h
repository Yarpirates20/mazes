#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Grid.h"

class BinaryTree
{
    public:
        /**
         * @brief Creates a maze using Binary Tree algorithm by collecting 
         * neighbors, putting them in a list, and choosing one cell from that 
         * list to link to current cell.
         * 
         * @param g Reference to Grid to run Binary Tree on.
         */
        void on(Grid &g);


};

#endif // BINARYTREE_H