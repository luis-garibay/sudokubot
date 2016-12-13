#ifndef __BOARD__
#define __BOARD__

#include "boolean.h"
#include "set.h"
#include "mem_wrap.h"

typedef struct _Cell {
	int value;
	Boolean known; // has this cell been solved/given?
	Set *possibleValues; // values that might belong in this cell
} Cell;

typedef struct _Board {
	Cell cells[9][9];
} Board;

Board *CreateBoard(int *initBoard);
void DeleteBoard(Board *board);

#endif
