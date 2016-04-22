//
//  main.c
//  SudokuBot
//
//  Created by luis on 4/12/16.
//  Copyright © 2016 FFC. All rights reserved.
//

#include <stdio.h>

//	;	First operation: Record possibilities
//	For each unknown cell
//		For each number 1-9
//			If the number doesn't exist in the cell's row AND the number doesn't exist in the cell's column AND the number doesn't exist in the cell's 3x3 group
//				Mark number down as possibility in the cell
//		Done
//	Done
//	;	Second operation: Remove possibilities
//	For each unknown cell
//		If there are cells in the cell's row that are in other 3x3 groups AND that row in the 3x3 group is the only one with that number as a possibility
//			Remove the number as a possibility in the cell
//	Done
//	;	Third operation: Record the logical answers, such as the lone possible answers and the only cells in each group, row, and column where a number is possible

// Organize functions into headers by type
// TYPES:
// solutions
// board navigation (converting row/column to index in array OR getting group from row/column)

// Functions:
// Convert Row and Column to corresponding index
unsigned rowColToIndex(unsigned row, unsigned col);
// Convert index to Row and Column
void indexToRowCol(unsigned index, unsigned *row, unsigned *col);
// Convert row/column to 3x3 group column
unsigned colToGroupCol(unsigned col);
// Convert row/column to 3x3 group row
unsigned rowToGroupRow(unsigned row);
// Convert row/column to 3x3 group index
unsigned rowColToGroup(unsigned row, unsigned col);
// Convert index to 3x3 group
unsigned indexToGroup(unsigned index);
// Get the indexes in the group
void getGroupIndexes(unsigned indexes[], unsigned group);

// Check known_board for a number in a given row (that isn't in the same 3x3 group)
unsigned checkRowKnown(unsigned row, unsigned col, unsigned number, unsigned known[]);
// Check known_board for a number in a given column (that isn't in the same 3x3 group)
unsigned checkColKnown(unsigned row, unsigned col, unsigned number, unsigned known[]);
// Check known_board for a number in a given 3x3 group
void checkGroupKnown();
// Check possibilities_board for a number in a given row (that isn't in the same 3x3 group)
void checkRowPossible();
// Check possibilities_board for a number in a given column (that isn't in the same 3x3 group)
void checkColPossible();
// Check possibilities_board for a number in a given 3x3 group
void checkGroupPossible();

int main(int argc, const char * argv[]) {
	unsigned known_board[] = {
		0,2,0, 0,0,0, 0,0,7,
		0,0,0, 0,8,6, 9,0,2,
		0,8,9, 0,2,0, 0,0,6,
		
		0,5,0, 0,0,4, 7,0,3,
		7,0,0, 0,0,0, 0,0,5,
		4,0,6, 5,0,0, 0,1,0,
		
		9,0,0, 0,7,0, 3,8,0,
		1,0,4, 8,6,0, 0,0,0,
		2,0,0, 0,0,0, 0,7,0,
	};
	
	unsigned row = 7, col = 3, num = 7, group = 4, groupCol, groupRow;
	
	printf("group = %d ; index = %d\n", group, (3/2) * (group - 1) + 1);
	//printf("groupCol = %d ; col = %d\n", groupCol, 3 * (groupCol - 1) + 1);
	//printf("groupRow = %d ; row = %d\n", groupRow, 3 * (groupRow - 1) + 1);
	
    return 0;
}

unsigned rowColToIndex(unsigned row, unsigned col) {
	return (9 * row) - (9 - col);
}

void indexToRowCol(unsigned index, unsigned *row, unsigned *col) {
	*row = (index - 1) / 9 + 1;
	*col = (index - 1) % 9 + 1;
}

unsigned colToGroupCol(unsigned col) {
	return ((col - 1) / 3) + 1;
}

unsigned rowToGroupRow(unsigned row) {
	return ((row - 1) / 3) + 1;
}

unsigned rowColToGroup(unsigned row, unsigned col) {
	// (3 * (((row - 1) / 3) + 1)) - (3 - (((col - 1) / 3) + 1))
	return 3 * ((row - 1) / 3) + ((col - 1) / 3) + 1;
}

unsigned indexToGroup(unsigned index) {
	// row = (index - 1) / 3 + 1
	// col = (index - 1) % 3 + 1
	// 3 * ((row - 1) / 3) + ((col - 1) / 3) + 1
	//
	// 3 * ((((index - 1) / 3 + 1) - 1) / 3) + ((((index - 1) % 3 + 1) - 1) / 3) + 1
	// 3 * (((iPart((index - 1) / 3) + 1) - 1) / 3) + ((((index - 1) % 3 + 1) - 1) / 3) + 1
	// 3 * (((iPart((index - 1) / 3) + 1) - 1) / 3) + ((((index - 1) % 3 + 1) - 1) / 3) + 1
	
	/* TODO: simplify so call to rowColToGroup isn't used ***********/
	
	return rowColToGroup((index - 1) / 3 + 1, (index - 1) % 3 + 1);
}

// groupCol - 1 = iPart((row - 1) / 3);
// groupRow - 1 = iPart((col - 1) / 3);
// index = 9 * row - 9 + col
void getGroupIndexes(unsigned indexes[], unsigned group) {
	
}

/*
 *	Function Name: checkRowKnown
 *	Summary: Check known_board for a number in a given row.
 *
 *	Description:
 *		checkRowKnown() will be supplied the row and column of a cell - which will be the focus of the
 *	operation - as well as a number (1 through 9) and an array corresponding to the cells that were
 *	either given or solved for.
 *		The function will check the cell's row for other cells with the given number. If the number is
 *	found in another cell, then that means the number has been found for that row and therefore cannot
 *	belong to the cell that is being focused on.
 *
 *	Return: A value corresponding to the existence of the number in question in the given row.
 */
unsigned checkRowKnown(unsigned row, unsigned col, unsigned number, unsigned known[]) {
	unsigned cellinrow;
	
	for (cellinrow = 1; cellinrow <= 9; cellinrow++) {					//	iterate through each cell in the row 'row'
		if (cellinrow != col) {											//	execute the following if 'cellinrow' is not pointing to same location as the cell that is at (col, row)
			if (known[rowColToIndex(row, cellinrow) - 1] == number) {	//	if the number in question is found in one of the cells in the row,
				return 0;												//		then return boolean value false
			}
		}
	}
	
	return 1;
}

/*
 *	Function Name: checkColKnown
 *	Summary: Check known_board for a number in a given col.
 *
 *	Description:
 *		checkColKnown() will be supplied the row and column of a cell - which will be the focus of the
 *	operation - as well as a number (1 through 9) and an array corresponding to the cells that were
 *	either given or solved for.
 *		The function will check the cell's column for other cells with the given number. If the number is
 *	found in another cell, then that means the number has been found for that column and therefore cannot
 *	belong to the cell that is being focused on.
 *
 *	Return: A value corresponding to the existence of the number in question in the given column.
 */

unsigned checkColKnown(unsigned row, unsigned col, unsigned number, unsigned known[]) {
	unsigned cellincol;
	
	for (cellincol = 1; cellincol <= 9; cellincol++) {					//	iterate through each cell in the column 'col'
		if (cellincol != row) {											//	execute the following if 'cellincol' is not pointing to same location as the cell that is at (col, row)
			if (known[rowColToIndex(cellincol, col) - 1] == number) {	//	if the number in question is found in one of the cells in the column,
				return 0;												//		then return boolean value false
			}
		}
	}
	
	return 1;
}

void checkGroupKnown(unsigned row, unsigned col, unsigned known[]) {
	
}

void checkRowPossible(unsigned row, unsigned col, unsigned possible[]) {
	
}

void checkColPossible(unsigned row, unsigned col, unsigned possible[]) {
	
}

void checkGroupPossible(unsigned row, unsigned col, unsigned possible[]) {
	
}
