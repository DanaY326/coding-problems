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

const int MAX_PW_LEN = 100;
const int MAX_HELP_LEN = 30;


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////// YOU MAY MAKE EDITS IN THE FOLLOWING SECTION /////////
///// DO NOT CHANGE FUNCTION SIGNATURES OF REQUIRED FUNCTIONS //////
//// INCLUDE DOCUMENTED HELPER FUNCTIONS IF ANY IN THIS SECTION ////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


// check_length(str) returns  true if str has at least the minimum length
//   required for a valid password, and false otherwise.
// requires: str is a valid string
bool check_length(const char *str) {
	// TODO: your implementation here
	return false;
}


// check_capital(str) returns  true if str contains at least one capital
//   letter, and false otherwise.
// requires: str is a valid string
bool check_capital(const char *str) {
	// TODO: your implementation here
	return false;
}


// check_num(str) returns  true if str contains at least one number,
//   and false otherwise.
// requires: str is a valid string
bool check_num(const char *str) {
	// TODO: your implementation here
	return false;
}


// check_symbol(str) returns  true if str contains at least one,
//   non-alphanumeric character, and false otherwise.
// requires: str is a valid string
bool check_symbol(const char *str) {
	// TODO: your implementation here
	return false;
}


// str_contains(str, fragment) returns true if str contains the sequence
//   given by fragment, and false otherwise.
// requires: str is a valid string
//           fragment is a valid string
bool str_contains(const char *str, const char *fragment) {
	// TODO: your implementation here
	return false;
}


// check_positivity(str) returns true if str contains the sequence "(^_^)",
//   and false otherwise.
// requires: str is a valid string
bool check_positivity(const char *str) {
	// TODO: your implementation here
	return false;
}


// check_sum(str) returns true if all digits in str have a valid sum,
//   and false otherwise.
// requires: str is a valid string
bool check_sum(const char *str) {
	// TODO: your implementation here
	return false;
}


// check_palindrome(str) returns  true if str is a palindrome,
//   and false otherwise.
// requires: str is a valid string
bool check_palindrome(const char *str) {
	// TODO: your implementation here
	return false;
}


// password_help(in_str, out_str) stores in out_str a valid password
//   containing the sequence in_str
// requires: in_str is a valid string
//           out_str points to a valid char[]
//           in_str contains only letter characters (not asserted)
// effects: mutates the char[] pointed to by out_str
void password_help(const char *in_str, char *out_str) {
	// TODO: your implementation here
}


/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE BELOW THIS ///////////
/////////////////////////////////////////////////////////


// test_str(result) produces a string to be printed for a boolean test result
char* test_str(const bool result) {
	if(result) {
		return "Passed";
	} else {
		return "Failed";
	}
}


int main(void) {
	// Hard coded test harness will dictate what .in and .expect files are like
	// for .in file:
	// until the end of the file, read lines beginning with a char:
	//   c: run all checks on a candidate password
	//      followed by a string, the candidate password to check
	//   h: create a valid password from a base alphabetic string
	//      followed by an alphabetic string, which must appear in the output
	//   any other char: exit program
	// See sample .in and .expect files for examples.

	char pw[101];
	char help_str[31];
	char command = '\0';

	// read in commands
	while (scanf(" %c", &command) == 1) {
		if (command == 'c') {
			if (scanf("%100s", pw) == 1) {
				printf("Testing candidate password: %s\n", pw);
				printf("Length check: %s\n", test_str(check_length(pw)));
				printf("Capital check: %s\n", test_str(check_capital(pw)));
				printf("Number check: %s\n", test_str(check_num(pw)));
				printf("Symbol check: %s\n", test_str(check_symbol(pw)));
				printf("Digit sum check: %s\n", test_str(check_sum(pw)));
				printf("Positivity check: %s\n",
				       test_str(check_positivity(pw)));
				printf("Palindrome check: %s\n",
				       test_str(check_palindrome(pw)));
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else if (command == 'h') {
			if (scanf("%30s", help_str) == 1) {
				printf("Word to convert to password: %s\n", help_str);
				password_help(help_str, pw);
				printf("Resulting password: %s\n", pw);
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else {
			printf("Exiting.\n");
			return 0;
		}
	}
}
