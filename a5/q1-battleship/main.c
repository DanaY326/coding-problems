/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// ERROR_NO_INTEGRITY_STATEMENT
//
// Name: ERROR_NO_NAME
// login ID: ERROR_NO_LOGIN
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


/////////////////////////////////////////////////////////
/////////////// DO NOT MODIFY THIS CODE /////////////////
/////////////////////////////////////////////////////////

const int MAX_SHIPS = 5;
const int MAX_SHOTS = 100;
const int MAX_STR_LEN = 50;
const int BOARD_ROWS = 10;
const int BOARD_COLS = 10;

struct ship {
	char name[51];     // ship's name (e.g. "Battleship")
	char sym;          // symbol for use on the board (e.g. 'B')
	bool is_vert;      // true if positioned vertically, false if horizontal
	int length;        // number of spaces occupied
	int top_left_row;  // row index of top-leftmost occupied square
	int top_left_col;  // column index of top-leftmost occupied square
	int hits;          // number of times this ship has been hit
};


// print_ship(shp) prints the fields of the ship pointed to by shp to stdout
// requires: shp is a valid ship
// effects: produces output
void print_ship(const struct ship *shp) {
	assert(shp);
	printf("Name: %s, Symbol: %c, Vertical?: %d, ",
	    	shp->name, shp->sym, shp->is_vert);
	printf("Length: %d, Top Left Row: %d, Top Left Col: %d\n",
			shp->length, shp->top_left_row, shp->top_left_col);
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////// YOU MAY MAKE EDITS IN THE FOLLOWING SECTION /////////
///// DO NOT CHANGE FUNCTION SIGNATURES OF REQUIRED FUNCTIONS //////
//// INCLUDE DOCUMENTED HELPER FUNCTIONS IF ANY IN THIS SECTION ////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


// read_ship(shp) reads the values of a ship from stdin and assigns them to the
//   ship pointed to by shp if and only if successful. Returns true if successful
//   and false if not.
// requires: shp is a valid struct ship
// effects: reads input,
//          may mutate the ship pointed to by shp
bool read_ship(struct ship *shp) {
	// TODO: your implementation here
	return false;
}


// TODO: your design recipe here
void print_board(char *board) {
	// TODO: your implementation here
}


// TODO: your design recipe here
bool place_ship(const struct ship *shp, char *board) {
	// TODO: your implementation here
	return true;
}


// fire_shot(board, shot_row, shot_col) simulates firing a shot on the given
//   board at row, shot_row, and column, shot_col. Changes the symbol at that
//   position to '-' if a miss, and '*' if a hit.
// requires: 0 <= shot_row < BOARD_ROWS,
//           0 <= shot_col < BOARD_COLS,
//           board is not NULL,
//           board has length BOARD_ROWS * BOARD_COLS (not asserted)
// effects: mutates the board pointed to by board
char fire_shot(char *board, const int shot_row, const int shot_col) {
	// TODO: your implementation here
	return '\0';
}


// play_battleship(ship_arr, num_ships, board, num_shots, shot_rows, shot_cols)
//   simulates a (single-player) game of Battleship on the given board. ship_arr
//   contains a number of ships equal to num_ships. shot_rows and 
//   shot_cols each contain num_shots items. The row of shot i is given by
//   shot_rows[i], and the column by shot_cols[i].
//   Prints a message to stdout for each shot that misses, hits,
//   and each ship sunk.
// requires: ship_arr is not NULL,
//           ships in ship_arr are already added to board (not asserted)
//           board is not NULL,
//           shot_rows is not NULL,
//           shot_cols is not NULL,
//           shot_rows and shot_cols have length num_shots (not asserted)
// effects: mutates the board pointed to by board
//          may mutate the ships in ship_arr
//          may produce output
void play_battleship(struct ship *ship_arr, const int num_ships, char *board,
					const int num_shots, const int *shot_rows,
					const int *shot_cols) {
	// TODO: your implementation here
}


/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE BELOW THIS ///////////
/////////////////////////////////////////////////////////


int main(void) {
	// Hard coded test harness will dictate what .in and .expect files 
	// are like for .in file:
	// first line is 1 integer, N, giving the number of ships
	// the next N lines give 1 ship each with 6 values:
	//   a string, the ship's name
	//   a char, a capital letter for representing the ship on the board
	//   a char, either h (horizontal placement) or v (vertical placement)
	//   an int, the length of the ship
	//   an int, the row of the top left square occupied by the ship
	//   an int, the column of the top left square occupied by the ship
	// until the end of the file, read lines beginning with a char:
	//   b: print the board
	//   s: print a ship
	//      followed by an int, the index of the ship to be printed
	//   p: play Battleship
	//      followed by int M, giving the number of shots
	//      followed by 2*M ints giving the row and column of shots
	//        (in the order row_0 col_0 row_1 col_1 row_2 col_2 ...)
	//   any other char: exit program
	// See sample .in and .expect files for examples.

	int num_ships = 0;
	char board[10 * 10];
	struct ship ship_arr[5];

	for (int i = 0; i < BOARD_ROWS; ++i) {
		for (int j = 0; j < BOARD_COLS; ++j) {
			board[i * BOARD_COLS + j] = '.';
		}
	}

	// read in ships
	if (!(scanf("%d", &num_ships) == 1)) {
		printf("Failed to read number of ships.\n");
		return 0;
	}
	if (num_ships > MAX_SHIPS) {
		printf("Number of ships exceeds maximum.\n");
		return 0;
	}
	for (int i=0; i<num_ships; ++i) {
		if (!read_ship(&(ship_arr[i]))) {
			printf("Invalid ship.\n");
			return 0;
		} else if (!place_ship(&(ship_arr[i]), board)) {
			printf("Invalid ship placement.\n");
			return 0;
		}
	}

	char command = '\0';
	int print_index = 0;
	int num_shots = 0;
	int shot_rows[100];
	int shot_cols[100];

	// read in commands
	while (scanf(" %c", &command) == 1) {
		if (command == 'b') {
			print_board(board);
		} else if (command == 's') {
			if (scanf("%d", &print_index) == 1 && print_index >= 0 &&
			   print_index < MAX_SHIPS) {
				print_ship(&(ship_arr[print_index]));
			} else {
				printf("Given invalid ship index to print.\n");
				return 0;
			}
		} else if (command == 'p') {
			if (scanf("%d", &num_shots) == 1 && num_shots >= 0 &&
			   num_shots < MAX_SHOTS) {
				for (int i = 0; i < num_shots; ++i) {
					bool read_success = scanf("%d", &(shot_rows[i])) == 1;
					read_success = read_success &&
					               scanf("%d", &(shot_cols[i])) == 1;
					read_success = read_success && shot_rows[i] >= 0;
					read_success = read_success && shot_rows[i] < BOARD_ROWS;
					read_success = read_success && shot_cols[i] >= 0;
					read_success = read_success && shot_cols[i] < BOARD_COLS;
					if (!read_success) {
						printf("Given invalid shot coordinates.\n");
						return 0;
					}
				}
				play_battleship(ship_arr, num_ships, board,
				                num_shots, shot_rows, shot_cols);
			} else {
				printf("Given invalid number of shots.\n");
				return 0;
			}
		} else {
			printf("Exiting.\n");
			return 0;
		}
	}
}
