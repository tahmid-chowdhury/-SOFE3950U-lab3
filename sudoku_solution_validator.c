// sudoku_solution_validator.c
// Operating Systems - Lab 3
// CRN 74026 - Group 9
// Tahmid Chowdhury, 100822671
// Suluxan Manogharan, 100823684
// Armaghan Nasir, 100820948
// Saieashan Sathivel, 100818528

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 11

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

int valid = 1;

// Thread function to check all rows
void* checkRow(void* param) {
	int row = *(int*)param;
	
	// Logic to check each row for numbers 1 through 9
	int used[9] = {0};
	
	for (int col = 0; col < 9; ++col) {
		int num = sudoku[row][col];
		
		if (num < 1 || num > 9 || used[num - 1] == 1) {
			printf("Invalid row %d\n", row);
			valid = 0;
			return NULL;
		}
		
		used[num - 1] = 1;
	}
	
	return NULL; // Return NULL or a result structure
}

// Thread function to check all columns
void* checkColumn(void* param) {
	int col = *(int*)param;
	
	// Logic to check each column for numbers 1 through 9
	int used[9] = {0};
	
	for (int row = 0; row < 9; ++row) {
		int num = sudoku[row][col];
		
		if (num < 1 || num > 9 || used[num - 1] == 1) {
			printf("Invalid column %d\n", row);
			valid = 0;
			return NULL;
		}
		
		used[num - 1] = 1;
	}
	
	return NULL;
}

// Thread function to check all 3x3 subgrids
void* checkSubGrid(void* param) {
	int subgrid = *(int*)param;
	int startRow = (subgrid / 3) * 3;
	int startCol = (subgrid % 3) * 3;
	
	// Logic to check 3x3 subgrid for numbers 1 through 9
	int used[9] = {0};
	
	for (int row = startRow; row < startRow + 3; ++row) {
		for (int col = startCol; col < startCol + 3; ++col) {
			int num = sudoku[row][col];
			
			if (num < 1 || num > 9 || used[num - 1] == 1) {
				printf("Invalid subgrid %d\n", subgrid);
				valid = 0;
				return NULL;
			}
			
			used[num - 1] = 1;
		}
	}
	
	return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS];
	
	// Row & column checks
	int row_numbers[NUM_THREADS];
	
	for (int i = 0; i < NUM_THREADS; i++) {
		row_numbers[i] = 1;
		pthread_create(&threads[i], NULL, checkRow, &row_numbers[i]);
	}
	
	int col_numbers[NUM_THREADS];
	
	for (int i = 0; i < NUM_THREADS; i++) {
		col_numbers[i] = 1;
		pthread_create(&threads[i], NULL, checkColumn, &col_numbers[i]);
	}
	
	// Creating nine threads for each 3x3 subgrid validation (Subgrid checks)
	int subgrid_numbers[9];
	
	for (int i = 0; i < 9; i++) {
		subgrid_numbers[i] = i;
		pthread_create(&threads[i], NULL, checkSubGrid, &subgrid_numbers[i]);
	}
	
	// Waiting for all threads to complete
	for(int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	// Add validation logic here to determine if the Sudoku is valid based on the threads' results
	if (valid) {
		printf("Sudoku is valid.\n");
	} else {
		printf("Sudoku is invalid.\n");
	}
	
	return 0;
}
