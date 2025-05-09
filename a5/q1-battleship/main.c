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


// clone_shp(ship_src, shp_dest) copies all the values in struct ship_src into shp_dest
// requires: shp_src and shp_dest are valid struct ships
// effects: mutates the ship pointed to by shp_dest
void clone_shp(struct ship *shp_src, struct ship *shp_dest) {
	assert(shp_src);
	assert(shp_dest);
	for (int i = 0; i < 50; ++i) {
		shp_dest->name[i] = shp_src->name[i];
	}
	shp_dest->sym = shp_src->sym;
	shp_dest->is_vert = shp_src->is_vert;
	shp_dest->length = shp_src->length;
	shp_dest->top_left_row = shp_src->top_left_row;
	shp_dest->top_left_col = shp_src->top_left_col;
	shp_dest->hits = shp_src->hits;
}


// read_ship(shp) reads the values of a ship from stdin and assigns them to the
//   ship pointed to by shp if and only if successful. Returns true if successful
//   and false if not.
// requires: shp is a valid struct ship
// effects: reads input,
//          may mutate the ship pointed to by shp
bool read_ship(struct ship *shp) {
	// TODO: your implementation here
	assert(shp);
	struct ship shp_temp;
	char dir = ' ';
	if (scanf("%50s", shp_temp.name) == 1) {
		if (scanf(" %c", &(shp_temp.sym)) == 1) {
			if (scanf(" %c", &dir) == 1) {
				if (scanf("%d", &shp_temp.length) == 1) {
					if (scanf("%d", &shp_temp.top_left_row) == 1) {
						if (scanf("%d", &shp_temp.top_left_col) == 1) {
							shp_temp.is_vert = (dir == 'v');
							shp_temp.hits = 0;
							clone_shp(&shp_temp, shp);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


// TODO: your design recipe here
// print_board(board) prints a visual representation of the board
// requires: board is a valid board
// effects: produces output
void print_board(char *board) {
	// TODO: your implementation here
	assert(board);
	for (int row = 0; row < BOARD_ROWS; ++row) {
		for (int col = 0; col < BOARD_COLS; ++ col) {
			printf("%c", *board);
			++board;
		}
		printf("\n");
	}
}

// get_sqr(board, row, col) returns the character at a given row and column of the board
// requires: board is a valid board
char get_sqr(char *board, int row, int col) {
	assert(board);
	return board[row * BOARD_COLS + col];
}

// chg_sqr(board, row, col, c) mutates the square at a given row and column of the board to be c
// requires: board is a valid board
// effects: mutates the board pointed to by board
void chg_sqr(char *board, int row, int col, char c) {
	assert(board);
	board[row * BOARD_COLS + col] = c;
}


// TODO: your design recipe here
// place_ship(shp, board) places a ship on the board if it's valid (in bounds and not overlapping with an existing ship)
// and does nothing if invalid
// it returns true if successful and false otherwise
// requires: shp is a valid ship and board is a valid board
// effects: may mutate the board pointed to by board
bool place_ship(const struct ship *shp, char *board) {
	// TODO: your implementation here
	assert(shp);
	assert(board);
	if (shp->top_left_row >= 0 && shp->top_left_col >= 0) {
		int bottom_right_row = shp->top_left_row;
		int bottom_right_col = shp->top_left_col;
	
		if (shp->is_vert) {
			bottom_right_row += (shp->length - 1);
		} else {
			bottom_right_col += (shp->length - 1);
		}
		if (bottom_right_row < 10 && bottom_right_col < 10) {
			bool ship_here = false;
			if (shp->is_vert) {
				for (int r = shp->top_left_row; r <= bottom_right_row; ++r) {
					if (get_sqr(board, r, shp->top_left_col) != '.' && get_sqr(board, r, shp->top_left_col) != '-') {
							ship_here = true;
						 }
				}
			} else {
				for (int c = shp->top_left_col; c <= bottom_right_col; ++c) {
					if (get_sqr(board, shp->top_left_row, c) != '.' && get_sqr(board, shp->top_left_row, c) != '-') {
							ship_here = true;
						 }
				}
			}
			if (ship_here == false) {
				if (shp->is_vert) {
					for (int r = shp->top_left_row; r <= bottom_right_row; ++r) {
						chg_sqr(board, r, shp->top_left_col, shp->sym);
					}
				} else {
					for (int c = shp->top_left_col; c <= bottom_right_col; ++c) {
						chg_sqr(board, shp->top_left_row, c, shp->sym);
					}
				}
				return true;
			}
		}
	}
	return false;
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
	char orig = get_sqr(board, shot_row, shot_col);
	if (orig == '.' || orig == '-') {
		chg_sqr(board, shot_row, shot_col, '-');
	} else {
		chg_sqr(board, shot_row, shot_col, '*');
	}
	return orig;
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
	for (int i = 0; i < num_ships; ++i) {
		place_ship(&ship_arr[i], board);
	}
	for (int j = 0; j < num_shots; ++j) {
		char orig = fire_shot(board, shot_rows[j], shot_cols[j]);
		if (orig == '.' || orig == '-' || orig == '*') {
			printf("Miss at R%d C%d\n", shot_rows[j], shot_cols[j]);
		} else {
			printf("Hit at R%d C%d\n", shot_rows[j], shot_cols[j]);
			int k = 0;
			while (orig != ship_arr[k].sym) {
				++k;
			}
			ship_arr[k].hits += 1;
			if (ship_arr[k].hits == ship_arr[k].length) {
				printf("%s was sunk!\n", ship_arr[k].name);
			}
		}
	}
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
					if (!read_success) {
						printf("Failed to read shot coordinates.\n");
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
