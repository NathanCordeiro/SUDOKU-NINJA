#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

bool solveSudoku(std::vector<std::vector<int>>& board);
bool isValid(std::vector<std::vector<int>>& board, int row, int col, int num);

#endif // SOLVER_H
