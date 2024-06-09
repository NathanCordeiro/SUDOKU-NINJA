#include <iostream>
#include <vector>
#include <conio.h>  // For _getch() on Windows. Replace with <ncurses.h> on Unix-like systems.
#include "solver.h"
#include "manager.h"
#include "txt_styling.h"

void displayMenu() {
    using namespace txt_styling;
    std::cout << "\n" << std::endl;
    std::cout << BOLD_TEXT << CYAN_BACKGROUND << "Sudoku Solver Menu" << RESET << std::endl;
    std::cout << BLUE_TEXT << "1. New Puzzle" << RESET << std::endl;
    std::cout << BLUE_TEXT << "2. Reset Puzzle" << RESET << std::endl;
    std::cout << BLUE_TEXT << "3. Solve Puzzle" << RESET << std::endl;
    std::cout << BLUE_TEXT << "4. Enter Numbers" << RESET << std::endl;
    std::cout << BLUE_TEXT << "5. Quit" << RESET << std::endl;
}

void enterNumbers(std::vector<std::vector<int>>& board, const std::vector<std::vector<int>>& originalBoard) {
    using namespace txt_styling;
    int row = 0, col = 0; // Start at the top-left corner

    while (true) {
        system("cls"); // Clear the screen on Windows, use "clear" on Unix-like systems
        printBoard(board);
        std::cout << BOLD_TEXT << "Use WASD to navigate, 1-9 to enter numbers, 0 to clear a cell, Q to quit." << RESET << std::endl;
        std::cout << "Current Position: (" << row + 1 << ", " << col + 1 << ")" << std::endl;

        char input = _getch(); // Get user input without waiting for enter (use getch() in <ncurses.h> for Unix-like systems)

        if (input == 'q' || input == 'Q') break; // Quit entering numbers

        switch (input) {
            case 'w': case 'W': // Move up
                if (row > 0) row--;
                break;
            case 's': case 'S': // Move down
                if (row < 8) row++;
                break;
            case 'a': case 'A': // Move left
                if (col > 0) col--;
                break;
            case 'd': case 'D': // Move right
                if (col < 8) col++;
                break;
            case '0': // Clear cell
                if (originalBoard[row][col] == 0) board[row][col] = 0;
                break;
            default: // Enter numbers 1-9
                if (input >= '1' && input <= '9') {
                    int num = input - '0'; // Convert char to int
                    if (originalBoard[row][col] == 0) board[row][col] = num;
                }
                break;
        }
    }
}

int main() {
    using namespace txt_styling;
    std::vector<std::vector<int>> board(9, std::vector<int>(9, 0));
    std::vector<std::vector<int>> originalBoard;
    int currentPuzzle = 0;
    int choice;

    loadNextPuzzle(board, currentPuzzle);
    originalBoard = board;

    while (true) {
        std::cout << std::endl;
        printBoard(board);
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // New Puzzle
                loadNextPuzzle(board, currentPuzzle);
                originalBoard = board;
                break;
            case 2: // Reset Puzzle
                resetPuzzle(board, originalBoard);
                break;
            case 3: // Solve Puzzle
                if (solveSudoku(board)) {
                    std::cout << GREEN_TEXT << "Puzzle solved!" << RESET << std::endl;
                } else {
                    std::cout << RED_TEXT << "No solution exists for the puzzle!" << RESET << std::endl;
                }
                break;
            case 4: // Enter Numbers
                enterNumbers(board, originalBoard);
                break;
            case 5: // Quit
                std::cout << MAGENTA_TEXT << "Goodbye!" << RESET << std::endl;
                return 0;
            default:
                std::cout << RED_TEXT << "Invalid choice. Please try again." << RESET << std::endl;
        }
    }

    return 0;
}
