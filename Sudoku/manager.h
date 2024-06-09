#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

void loadNextPuzzle(std::vector<std::vector<int>>& board, int& currentPuzzle);
void resetPuzzle(std::vector<std::vector<int>>& board, const std::vector<std::vector<int>>& originalBoard);
void printBoard(const std::vector<std::vector<int>>& board);

#endif // MANAGER_H
