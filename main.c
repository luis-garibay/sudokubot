//
//  main.c
//  SudokuBot
//
//  Created by luis on 4/12/16.
//

#include <stdio.h>
#include "set.h"
#include "boolean.h"
#include "board.h"

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
<<<<<<< HEAD
	int given_board[] = {
=======
	unsigned given_board[] = {
>>>>>>> b3a420814834502b3a081728314e704507b57fe3
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

	Board *b;
	int row, col, num;

<<<<<<< HEAD
	b = createBoard(given_board); // initialize board

	printf("OG SETUP:\n");
	printf("###################\n\n");
	printBoard(b);
	printf("###################\n");
=======
	b = CreateBoard(given_board); // initialize board
>>>>>>> b3a420814834502b3a081728314e704507b57fe3

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
<<<<<<< HEAD
			}
		}

		// eliminate possibilities
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

		printf("\n###################\n\n");
		printBoard(b);
		printf("###################\n");
	}

	printBoard(b);

	printf("\n");

	wMemStats();

	deleteBoard(b);
=======
			}
		}

		// eliminate possibilities
		for (col = 0; col < 9; col++) {
			for (row = 0; row < 9; row++) {
				if (isCellKnown(b, row, col) == TRUE)
					continue;

				for (num = 1; num <= 9; num++) {
					if (!checkRow(b, row, col, num)
						|| !checkCol(b, row, col, num)
						|| !checkGrp(b, row, col, num)) {

						
					}
				}
			}
		}
	}

>>>>>>> b3a420814834502b3a081728314e704507b57fe3
	return 0;
}
