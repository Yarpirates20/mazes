#include "BinaryTree.h"
#include "Cell.h"

#include <vector>
#include <cstdlib>
#include <ctime>

/** @copydoc void BinaryTree::on(Grid g) */
void BinaryTree::on(Grid &g)
{
    g.each_cell([](Cell *c)
                {
                    std::vector<Cell *> neighbors;
                    if (c->north != nullptr)
                    {
                        neighbors.push_back(c->north);
                    }

                    if (c->east != nullptr)
                    {
                        neighbors.push_back(c->east);
                    }

                    if (neighbors.empty())
                    {
                        return;
                    }
                    
                    int index = rand() % static_cast<int>(neighbors.size());

                    Cell* neighbor = neighbors[index];

                    if (neighbor)
                    {
                        c->link(neighbor);
                    } });
}