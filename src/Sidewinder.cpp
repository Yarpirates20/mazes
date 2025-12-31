#include "include/Sidewinder.h"
#include <vector>

void Sidewinder::on(Grid &g)
{
    srand(time(0));

    g.for_each_row([](std::vector<Cell *> &row)
                   {
        std::vector<Cell *> run;

        for (Cell *cell : row)
        {
            run.push_back(cell);

            bool at_eastern_boundary = cell->east == nullptr;
            bool at_northern_boundary = cell->north == nullptr;

            bool should_close_out = at_eastern_boundary || (!at_northern_boundary && (rand() % 2 == 0));

            if (should_close_out)
            {
                int index = rand() % run.size();
                auto member = run.at(index);
                
                if (member->north)
                    member->link(member->north);
                
                run.clear();
            }
            else
            {
                cell->link(cell->east);
            }
            
            
        } });
}
