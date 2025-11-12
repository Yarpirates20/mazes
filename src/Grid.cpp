#include "Grid.h"

Grid::Grid(int r, int c) : rows(r), columns(c)
{
    prepare_grid();
    configure_cells();
}