- What the Ruby does (brief): iterates every cell, reads its row/column, and sets its four neighbor pointers to the cells at the adjacent coordinates (or nil when out of bounds).

### Steps to implement the same in C++ (no code):

1. Ensure you can read a cell’s coordinates from Grid: provide public accessors (row(), column()) or otherwise let Grid access them (friend or public members).
2. Add a safe accessor on Grid: a function Cell* at(int r, int c) that returns nullptr if (r,c) is outside [0,rows)×[0,columns).
3. Iterate every cell in the grid with nested loops over row (0..rows-1) and col (0..columns-1).
4. For each iteration, get the Cell* (e.g., grid[r][c]) and assign its neighbor pointers using the safe accessor:
    - north = at(r-1, c)
    - south = at(r+1, c)
    - west = at(r, c-1)
    - east = at(r, c+1)
    These assignments will store nullptr for out‑of‑bounds neighbors.
5. Keep the member visibility in mind: cell->north/east/etc. must be accessible to Grid (they are public in your header).
6. Make the method const-correct where appropriate and document that returned pointers may be nullptr and that Grid owns the Cell objects.
7. Add tests or assertions to verify a few edge and interior cells after configuration.
8. (Optional) Consider replacing raw new/Cell* with smart pointers (unique_ptr/shared_ptr) to manage lifetime and avoid leaks.