#ifndef __BOARD__
#define __BOARD__

#include "boolean.h"
#include "list.h"
#include "mem_wrap.h"

typedef struct _Cell {
	int value;
	Boolean known; // has this cell been solved/given?
	List *possibleValues; // values that might belong in this cell
} Cell;

typedef struct _Board {
	Cell cells[9][9]; // TODO: make into graph data structure to eliminate excessive use of loops
} Board;

Board *createBoard(int *initBoard);
void setCell(Board *board, int row, int col, int value);
int getCellValue(Board *board, int row, int col);
void addCellPossible(Board *board, int row, int col, int n);
void removeCellPossible(Board *board, int row, int col, int n);
Node *getPossibilities(Board *board, int row, int col);
int getNumPossible(Board *board, int row, int col);
int getFirstPossible(Board *board, int row, int col);
Boolean isCellKnown(Board *board, int row, int col);
Boolean checkRow(Board *board, int row, int col, int n);
Boolean checkCol(Board *board, int row, int col, int n);
Boolean checkGrp(Board *board, int row, int col, int n);
Boolean isRowLonePossible(Board *board, int row, int col, int n);
Boolean isColLonePossible(Board *board, int row, int col, int n);
Boolean isGrpLonePossible(Board *board, int row, int col, int n);
Boolean isSolved(Board *board);
void deleteBoard(Board *board);

void printBoard(Board *board);
void printPossible(Board *board);

#endif
