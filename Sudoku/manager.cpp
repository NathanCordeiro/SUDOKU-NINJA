#include "manager.h"
#include "txt_styling.h"
#include <iostream>

// Preset Sudoku puzzles
std::vector<std::vector<std::vector<int>>> presetPuzzles = {
    { // Puzzle 1
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    },
    { // Puzzle 2
        {0, 0, 0, 6, 0, 0, 4, 0, 0},
        {7, 0, 0, 0, 0, 3, 6, 0, 0},
        {0, 0, 0, 0, 9, 1, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 1, 8, 0, 0, 0, 3},
        {0, 0, 0, 3, 0, 6, 0, 4, 5},
        {0, 4, 0, 2, 0, 0, 0, 6, 0},
        {9, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 1, 0, 0}
    },
    { // Puzzle 3
        {1, 0, 0, 0, 0, 7, 0, 9, 0},
        {0, 3, 0, 0, 2, 0, 0, 0, 8},
        {0, 0, 9, 6, 0, 0, 5, 0, 0},
        {0, 0, 5, 3, 0, 0, 9, 0, 0},
        {0, 1, 0, 0, 8, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 4, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 4, 1, 0, 0, 0, 0, 0, 7},
        {0, 0, 7, 0, 0, 0, 3, 0, 0}
    },
    { // Puzzle 4
        {9, 0, 0, 0, 7, 0, 0, 0, 0},
        {2, 0, 0, 4, 8, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 7, 6, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 9, 1, 0, 0},
        {0, 0, 5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 1, 6, 0, 0, 3},
        {0, 0, 0, 0, 9, 0, 0, 0, 7}
    },
    { // Puzzle 5
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 3},
        {0, 3, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 8},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    },
    { // Puzzle 6
        {0, 0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 0, 0, 8},
        {4, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 7, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 6, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 5},
        {7, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 7, 2, 0, 0, 0, 0}
    }
};

// Load the next puzzle in the list
void loadNextPuzzle(std::vector<std::vector<int>>& board, int& currentPuzzle) {
    board = presetPuzzles[currentPuzzle];
    currentPuzzle = (currentPuzzle + 1) % presetPuzzles.size();
}

// Reset the puzzle to its original state
void resetPuzzle(std::vector<std::vector<int>>& board, const std::vector<std::vector<int>>& originalBoard) {
    board = originalBoard;
}

// Print the Sudoku board with styling
void printBoard(const std::vector<std::vector<int>>& board) {
    using namespace txt_styling;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0)
                std::cout << YELLOW_TEXT << " . " << RESET;
            else
                std::cout << GREEN_TEXT << " " << board[row][col] << " " << RESET;
            if ((col + 1) % 3 == 0 && col != 8) std::cout << " | ";
        }
        std::cout << std::endl;
        if ((row + 1) % 3 == 0 && row != 8) std::cout << "--------------------------------" << std::endl;
    }
}
