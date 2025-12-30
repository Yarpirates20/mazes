#ifndef SIDEWINDER_H
#define SIDEWINDER_H

#include "Grid.h"


class Sidewinder
{
    public:
        /**
         * @brief Maze generator using Sidewinder algorithm.
         * 
         * @param g Grid to generate Sidewinder algorithm maze on.
         */
        void on(Grid &g);
};

#endif // SIDEWINDER_H