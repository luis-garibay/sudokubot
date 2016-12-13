#include <assert.h>

#include "board.h"
#include "boolean.h"

#define rowCol2Index(r, c) (9 * r - 9 + c)

Board *CreateBoard(int *initBoard) {
	Board *board = NULL;
	int col, row;

	assert(initBoard != NULL);

	board = (Board *) wMalloc(sizeof(Board));

	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (initBoard[rowCol2Index(row, col)] != 0) { // if the current cell has a given value
				board->cells[row][col].value = initBoard[rowCol2Index(row, col)];
				board->cells[row][col].known = TRUE;
				board->cells[row][col].possibleValues = NULL;
			} else {
				board->cells[row][col].known = FALSE;
				board->cells[row][col].possibleValues = CreateSet(9);
			}
		}
	}

	return board;
}

void DeleteBoard(Board *board) {
	int col, row;

	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (board->cells[row][col].possibleValues == NULL)
				continue;

			DeleteSet(board->cells[row][col].possibleValues);
		}
	}

	wFree(board);
}
