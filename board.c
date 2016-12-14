<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
#include <assert.h>

#include "board.h"
#include "boolean.h"
<<<<<<< HEAD
#include "list.h"

#define rowCol2Index(r, c) (9 * r + c)
=======
#include "queue.h"

#define rowCol2Index(r, c) (9 * r - 9 + c)
>>>>>>> b3a420814834502b3a081728314e704507b57fe3

Board *createBoard(int *initBoard) {
	Board *board = NULL;
	int col, row;

	assert(initBoard != NULL);

	board = (Board *) wMalloc(sizeof(Board));

	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (initBoard[rowCol2Index(row, col)] != 0) { // if the current cell has a given value
				setCell(board, row, col, initBoard[rowCol2Index(row, col)]);
				board->cells[row][col].possibleValues = NULL;
			} else {
<<<<<<< HEAD
				board->cells[row][col].value = 0;
				board->cells[row][col].known = FALSE;
				board->cells[row][col].possibleValues = createList();
=======
				board->cells[row][col].known = FALSE;
				board->cells[row][col].possibleValues = createQueue(9);
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
			}
		}
	}

	return board;
}

void setCell(Board *board, int row, int col, int value) {
	board->cells[row][col].value = value;
	board->cells[row][col].known = TRUE;
}

int getCellValue(Board *board, int row, int col) {
	if (board->cells[row][col].known == FALSE)
		return 0;

	return board->cells[row][col].value;
}

void addCellPossible(Board *board, int row, int col, int n) {
<<<<<<< HEAD
	listInsert(board->cells[row][col].possibleValues, n);
}

void removeCellPossible(Board *board, int row, int col, int n) {
	listRemoveValue(board->cells[row][col].possibleValues, n);
=======
	enqueue(board->cells[row][col].possibleValues, n);
}

void removeCellPossible(Board *board, int row, int col, int n) {
	dequeueVal(board->cells[row][col].possibleValues, n);
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
}

int getNumPossible(Board *board, int row, int col) {
	if (board->cells[row][col].possibleValues == NULL)
		return -1;

<<<<<<< HEAD
	return board->cells[row][col].possibleValues->elemcount;
=======
	return board->cells[row][col].possibleValues->numElements;
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
}

int getFirstPossible(Board *board, int row, int col) {
	if (board->cells[row][col].possibleValues == NULL)
		return -1;

<<<<<<< HEAD
	return listHeadValue(board->cells[row][col].possibleValues);
=======
	return dequeue(board->cells[row][col].possibleValues);
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
}

Boolean isCellKnown(Board *board, int row, int col) {
	return board->cells[row][col].known;
}

Boolean checkRow(Board *board, int row, int col, int n) {
	int c;

	for (c = 0; c < 9; c++) {
		if (c == col)
			continue;

		if (board->cells[row][c].value == n) {
			return FALSE;
		}
	}

	return TRUE;
}

Boolean checkCol(Board *board, int row, int col, int n) {
	int r;

	for (r = 0; r < 9; r++) {
		if (r == row)
			continue;

		if (board->cells[r][col].value == n) {
			return FALSE;
		}
	}

	return TRUE;
}

Boolean checkGrp(Board *board, int row, int col, int n) {
<<<<<<< HEAD
	int rc2g[9][9] = {
=======
	int rc2g[][] = {
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
		{1,1,1, 2,2,2, 3,3,3},
		{1,1,1, 2,2,2, 3,3,3},
		{1,1,1, 2,2,2, 3,3,3},

		{4,4,4, 5,5,5, 6,6,6},
		{4,4,4, 5,5,5, 6,6,6},
		{4,4,4, 5,5,5, 6,6,6},

		{7,7,7, 8,8,8, 9,9,9},
		{7,7,7, 8,8,8, 9,9,9},
		{7,7,7, 8,8,8, 9,9,9}
	};

	int beginCol, endCol,
		beginRow, endRow,
		i, j;

	// based on position in 3x3 group,
	// choose beginning and end of for-
	// loop range
	
	// determine column range
	switch (rc2g[row][col]) {
	case 1:
		beginCol = 0; endCol = 2;
		beginRow = 0; endRow = 2;
		break;
	case 2:
		beginCol = 3; endCol = 5;
		beginRow = 0; endRow = 2;
		break;

	case 3:
		beginCol = 6; endCol = 8;
		beginRow = 0; endRow = 2;
		break;

	case 4:
		beginCol = 0; endCol = 2;
		beginRow = 3; endRow = 5;
		break;

	case 5:
		beginCol = 3; endCol = 5;
		beginRow = 3; endRow = 5;
		break;

	case 6:
		beginCol = 6; endCol = 8;
		beginRow = 3; endRow = 5;
		break;

	case 7:
		beginCol = 0; endCol = 2;
		beginRow = 6; endRow = 8;
		break;

	case 8:
		beginCol = 3; endCol = 5;
		beginRow = 6; endRow = 8;
		break;

	case 9:
		beginCol = 6; endCol = 8;
		beginRow = 6; endRow = 8;
		break;
	}

	for (i = beginCol; i <= endCol; i++) {
		for (j = beginRow; j <= endRow; j++) {
			if (i == col && j == row)
				continue;

			if (board->cells[j][i].value == n)
				return FALSE;
		}
	}

	return TRUE;
}

Boolean isSolved(Board *board) {
	int row, col;

	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (board->cells[row][col].known == FALSE)
				return FALSE;
		}
	}

	return TRUE;
}

void deleteBoard(Board *board) {
	int col, row;

	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			if (board->cells[row][col].possibleValues == NULL)
				continue;

<<<<<<< HEAD
			deleteList(board->cells[row][col].possibleValues);
=======
			deleteQueue(board->cells[row][col].possibleValues);
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
		}
	}

	wFree(board);
}
<<<<<<< HEAD

void printBoard(Board *board) {
	int row, col;

	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			printf("%d ", board->cells[row][col].value);

			if (col % 3 == 2)
				printf(" ");
		}

		printf("\n");

		if (row % 3 == 2)
			printf("\n");
	}
}
=======
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
