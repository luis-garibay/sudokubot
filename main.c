//
//  main.c
//  SudokuBot
//
//  Created by luis on 4/12/16.
//

#include <stdio.h>
#include "list.h"
#include "boolean.h"
#include "board.h"

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

int main(int argc, const char * argv[]) {
	int given_board[] = {
		0,3,0, 0,0,0, 4,0,7,
		1,0,8, 0,5,0, 0,0,0,
		0,0,0, 0,0,2, 0,9,0,

		0,0,6, 5,1,0, 2,4,0,
		0,0,0, 0,0,0, 0,0,0,
		0,4,2, 0,7,9, 3,0,0,

		0,1,0, 2,0,0, 0,0,0,
		0,0,0, 0,8,0, 1,0,4,
		8,0,5, 0,0,0, 0,3,0,
	};

	Board *b;
	int row, col, num;
	Node *possible;

	b = createBoard(given_board); // initialize board

	// for each unknown cell
	//  for 1 - 9
	//   if the # is not in the row, col, or group
	//    add # to cell possible values
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (isCellKnown(b, row, col) == TRUE)
				continue;

			for (num = 1; num <= 9; num++) {
				if (checkRow(b, row, col, num)
					&& checkCol(b, row, col, num)
					&& checkGrp(b, row, col, num)) {
					
					addCellPossible(b, row, col, num);
				}
			}
		}
	}

	// while not solved
	// check for lone possibilities
	// then eliminate possibilities
	while (!isSolved(b)) {
		// for each cell
		//  if there is 1 possibility
		//   set as cells value
		for (col = 0; col < 9; col++) {
			for (row = 0; row < 9; row++) {
				if (getNumPossible(b, row, col) == 1) {
					setCell(b, row, col, getFirstPossible(b, row, col));
				}
			}
		}

		// if there is one cell in a row, column, or group with
		//  a certain possibility, then set that cell to that value
		for (row = 0; row < 9; row++) {
			for (col = 0; col < 9; col++) {
				possible = getPossibilities(b, row, col);

				while (possible != NULL) {
					if (isRowLonePossible(b, row, col, possible->value)
						|| isColLonePossible(b, row, col, possible->value)
						|| isGrpLonePossible(b, row, col, possible->value)) {
						setCell(b, row, col, possible->value);
						break;
					}

					possible = possible->next;
				}
			}
		}

		// eliminate possibilities if number exists
		//  in the same row, column, or group
		for (col = 0; col < 9; col++) {
			for (row = 0; row < 9; row++) {
				if (isCellKnown(b, row, col) == TRUE)
					continue;

				for (num = 1; num <= 9; num++) {
					if (!checkRow(b, row, col, num)
						|| !checkCol(b, row, col, num)
						|| !checkGrp(b, row, col, num)) {
						
						removeCellPossible(b, row, col, num);
					}
				}
			}
		}
	}

	printBoard(b);

	printf("\n");

	deleteBoard(b);
	
	wMemStats();

	return 0;
}
