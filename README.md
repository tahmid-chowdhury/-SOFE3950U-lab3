# Operating Systems - Lab 3
**CRN 74026 - Group 9**
- [Tahmid Chowdhury](https://github.com/tahmid-chowdhury) - 100822671
- [Suluxan Manogharan](https://github.com/Suluseahawks) - 100823684
- [Armaghan Nasir](https://github.com/Armaghan180) - 100820948
- [Saieashan Sathivel](https://github.com/Saieashan1) - 100818528

## Introduction
Sudoku Solution Validator (SSV) is a multithreaded program that validates a given 9x9 Sudoku grid. The program ensures that each row, column, and each of the nine 3x3 subgrids contain all digits from 1 to 9 exactly once, without any repetitions. This is accomplished using 27 threads in total: nine for rows, nine for columns, and nine for the subgrids. The purpose of this README is to provide users with comprehensive instructions on how to efficiently run SSV.

## Installation and Compilation
To install SSV, run the following command in the terminal:
```bash
git clone https://github.com/tahmid-chowdhury/SOFE3950U-lab3.git
```

To navigate to the directory containing the source code:
```bash
cd SOFE3950U-lab3
```

To compile SSV:
```bash
gcc -g -o ssv sudoku_solution_validator.c -pthread
```

To run the compiled executable:
```bash
./ssv
```

## Usage
To edit the Sudoku puzzle:

- Open `sudoku_solution_validator.c` in your favourite text editor
- Edit the current Sudoku puzzle in lines 15-25:
  ```c
  int sudoku[9][9] = {
  	{5, 3, 4, 6, 7, 8, 9, 1, 2},
  	{6, 7, 2, 1, 9, 5, 3, 4, 8},
  	{1, 9, 8, 3, 4, 2, 5, 6, 7},
  	{8, 5, 9, 7, 6, 1, 4, 2, 3},
  	{4, 2, 6, 8, 5, 3, 7, 9, 1},
  	{7, 1, 3, 9, 2, 4, 8, 5, 6},
  	{9, 6, 1, 5, 3, 7, 2, 8, 4},
  	{2, 8, 7, 4, 1, 9, 6, 3, 5},
  	{3, 4, 5, 2, 8, 6, 1, 7, 9}
  };
  ```
- Save the updated Sudoku puzzle in your text editor (Ctrl + S)
- Recompile and run the SSV executable:
  ```bash
  gcc -g -o ssv sudoku_solution_validator.c -pthread
  ./ssv
  ```
