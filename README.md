# SUDOKU-NINJA

## Overview
This project, SUDOKU-NINJA, is a command-line application that combines an optimized Sudoku solver with a puzzle generator for conventional 9x9 puzzles, developed in C++. It provides an engaging and interactive way for users to solve or play Sudoku puzzles directly from their terminal or command prompt. The game features several preset puzzles and a robust backtracking algorithm that demonstrates the solution process, making it perfect for both enthusiasts and learners.

## What is Sudoku? For those living under a rock.
Sudoku is a popular logic-based number puzzle. The objective is to fill a 9x9 grid with numbers from 1 to 9, following these rules:

- Each row must contain all numbers from 1 to 9 without repetition.
- Each column must also contain all numbers from 1 to 9 without repetition.
- Each of the nine 3x3 sub-grids, called boxes, must contain all numbers from 1 to 9 without repetition.

The puzzle starts with some cells already filled with numbers, and the player must fill in the remaining cells. Sudoku puzzles range in difficulty from easy to extremely challenging.

## Features
Upon starting the game, you will be presented with the following menu options:

| Option                | Description                                                   |
|-----------------------|---------------------------------------------------------------|
| **New Puzzle**        | Load the next preset puzzle.                                  |
| **Reset puzzle**      | Reset the puzzle to its initial state.                        |
| **Solve Puzzle**      | Solve the current puzzle using the backtracking algorithm.    |
| **Enter Numbers**     | Manually enter numbers into the puzzle grid.                  |
| **Quit**              | Quit or exit the game.                                        |

## Prerequisites
- A C++ compiler 
- Command-line interface

## Compilation
To compile the project, follow these steps:

1. Open your command-line interface.
2. Navigate to the directory containing the project files using the `cd` command.
3. Compile the project using the following command:
  ```bash
  g++ -o Sudoku main.cpp manager.cpp solver.cpp
  ```
  This will generate an executable file named Sudoku.exe on Windows or Sudoku on Unix-based systems.

## Running the Game
After compilation, you can run the game by executing the compiled file:
#### On Windows:
```bash
Sudoku.exe
```
`OR`

```bash
Sudoku
```

#### On Unix-based systems (Linux/macOS):
```bash
./Sudoku
```
## File Structure
| File                  | Description                                                   |
|-----------------------|---------------------------------------------------------------|
| **main.cpp**          | Contains the main function and the primary game loop.         |
| **manager.cpp**       | Implements functions for handling the game menu, loading, resetting puzzles, and entering numbers. |
| **manager.h**         | Header file declaring the functions used in `manager.cpp`.    |
| **solver.cpp**        | Implements the Sudoku solving algorithm.                      |
| **solver.h**          | Header file declaring the functions used in `solver.cpp`.     |
| **txt_styling.h**     | Contains ANSI escape codes for text styling.                  |

