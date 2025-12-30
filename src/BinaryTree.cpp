#include "include/BinaryTree.h"
#include <vector>
#include <ctime>

/** @copydoc BinaryTree::on(Grid &g) */
void BinaryTree::on(Grid &g)
{
    srand(time(0));

    g.for_each_cell([](Cell &x)
                    {
                        std::vector<Cell *> cell_neighbors;
                        if (x.north)
                        {
                            cell_neighbors.push_back(x.north);
                        }

                        if (x.east)
                        {
                            cell_neighbors.push_back(x.east);
                        }

                        int index = rand() % 2;

                        if (cell_neighbors.size() == 2)
                        {
                            x.link(cell_neighbors.at(index));
                        }

                        if (cell_neighbors.size() == 1)
                        {
                            x.link(cell_neighbors.at(0));
                        }
                    });
}
