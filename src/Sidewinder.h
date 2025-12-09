#ifndef SIDEWINDER_H
#define SIDEWINDER_H

#include "Grid.h"
#include "Cell.h"

#include <vector>

/**
 * @brief Creates a maze using Sidewiner algorithim.
 *
 */
class Sidewinder
{
public:
    /**
     * @brief For each row, maintains a run. For each cell, either link
     * east (extend run) or close out: pick a random member of run and link
     * it north, then clear run.
     *
     * @param g Grid from which to create maze.
     */
    void on(Grid &g)
    {
        g.each_row([&](Grid::Row &row)
                   {
                       std::vector<Cell *> run;

                       for (Cell *cell : row)
                       {
                           if (!cell)
                               continue; // defensive

                           run.push_back(cell);

                           bool at_eastern_boundary = (cell->east == nullptr);
                           bool at_northern_boundary = (cell->north == nullptr);

                           bool should_close_out = at_eastern_boundary || (!at_northern_boundary && rand() % 2 == 0);

                           if (should_close_out)
                           {
                               // Choose random member from run and link it north (if
                               // possible)
                               int idx = rand() % run.size();

                               Cell *member = run[idx];
                               if (member && member->north)
                                   member->link(member->north);

                               run.clear();
                           }
                           else
                           {
                               // carve east to extend run
                               if (cell->east)
                                   cell->link(cell->east);
                           }
                       }
                   });
    }
};

#endif // SIDEWINDER_H