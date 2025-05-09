#include <stdio.h>
#include <stdlib.h>
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
	const int MIN_LEN = 5;
	// TODO: your implementation here
	assert(str);
	int len = 0;
	while (*str != '\0') {
		++len;
		++str;
		if (len >= MIN_LEN) {
			return true;
		}
	}
	return false;
}


// check_capital(str) returns  true if str contains at least one capital
//   letter, and false otherwise.
// requires: str is a valid string
bool check_capital(const char *str) {
	// TODO: your implementation here
	assert(str);
	while (*str != '\0') {
		if (*str >= 'A' && *str <= 'Z') {
			return true;
		}
		++str;
	}
	return false;
}


// check_num(str) returns  true if str contains at least one number,
//   and false otherwise.
// requires: str is a valid string
bool check_num(const char *str) {
	// TODO: your implementation here
	assert(str);
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			return true;
		}
		++str;
	}
	return false;
}


// check_symbol(str) returns  true if str contains at least one,
//   non-alphanumeric character, and false otherwise.
// requires: str is a valid string
bool check_symbol(const char *str) {
	// TODO: your implementation here
	assert(str);
	while (*str != '\0') {
		if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z') && !(*str >= '0' && *str <= '9')) {
			return true;
		}
		++str;
	}
	return false;
}


// str_contains(str, fragment) returns true if str contains the sequence
//   given by fragment, and false otherwise.
// requires: str is a valid string
//           fragment is a valid string
bool str_contains(const char *str, const char *fragment) {
	// TODO: your implementation here
	assert(str);
	assert(fragment);
	int s = 0;
	int f = 0;
	int bookmark = 0;
	while (str[s] != '\0') {
		if (str[s] == fragment[f]) {
			bookmark = s;
			while (str[s] == fragment[f]) {
				++s;
				++f;
			}
			if (fragment[f] == '\0') {
				return true;
			} 
			s = bookmark;
			f = 0;
		}
		++s;
	}
	return false;
}


// check_positivity(str) returns true if str contains the sequence "(^_^)",
//   and false otherwise.
// requires: str is a valid string
bool check_positivity(const char *str) {
	// TODO: your implementation here
	assert(str);
	char POSITIVITY[] = "(^_^)";
	if (str_contains(str, POSITIVITY)) {
		return true;
	} 
	return false;
}


// check_sum(str) returns true if all digits in str have a valid sum,
//   and false otherwise.
// requires: str is a valid string
bool check_sum(const char *str) {
	// TODO: your implementation here
	assert(str);
	const int DESIRED_SUM = 25;
	int sum = 0;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			sum += (*str - '0');
		}
		++str;
	}
	if (sum == DESIRED_SUM) {
		return true;
	}
	return false;
}

// is_alphanum(c) returns true if c is a letter or number and false otherwise
bool is_alphanum(char c) {
	if (c >= 'A' && c <= 'Z') {
		return true;
	}
	if (c >= 'a' && c <= 'z') {
		return true;
	}
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}

// same_alphanum(c1, c2) returns true if c1 and c2 are both equal, ignoring case
// requires: c1 is either a letter or number character and c2 is 
//           either a letter or number character (not asserted)
bool same_alphanum(char c1, char c2) {
	assert(is_alphanum(c1));
	assert(is_alphanum(c2));
	if ((c1 >= 'A' && c1 <= 'Z') || (c1 >= 'a' && c1 <= 'z')) {
		if (c1 == c2) {
			return true;
		}
		if ((c1 - c2) == ('A' - 'a')) {
			return true;
		}
		if ((c1 - c2) == ('a' - 'A')) {
			return true;
		}
		return false;
	}
	return (c1 == c2);
}

// check_palindrome(str) returns  true if str is a palindrome,
//   and false otherwise.
// requires: str is a valid string
bool check_palindrome(const char *str) {
	// TODO: your implementation here
	assert(str);
	int beg = 0;
	int end = 0;
	while (str[end] != '\0') {
		++end;
	}
	while (end >= beg) {
		if (!is_alphanum(str[beg])) {
			++beg;
		}
		if (!is_alphanum(str[end])) {
			--end;
		}
		if (is_alphanum(str[beg]) && is_alphanum(str[end])) {
			if (!same_alphanum(str[beg], str[end])) {
				return false;
			}
			++beg;
			--end;
		}
	}
	return true;
}

// out_str_add(s_base, len, s_to_add) adds each element of s_to_add to the end of s_base
// returns the new length of s_base
// requires: s_base and s_to_add are valid strings 
// 			 len is the length of s_base (not asserted)
// effects: mutates string s_base
int out_str_add(char *s_base, int len, const char *s_to_add) {
	assert(s_base);
	assert(s_to_add);
	int i = 0;
	while (s_to_add[i] != '\0') {
		s_base[len] = s_to_add[i];
		++i;
		++len;
	}
	return len;
}

// password_help(in_str, out_str) stores in out_str a valid password
//   containing the sequence in_str
// requires: in_str is a valid string
//           out_str points to a valid char[]
//           in_str contains only letter characters (not asserted)
// effects: mutates the char[] pointed to by out_str
void password_help(const char *in_str, char *out_str) {
	// TODO: your implementation here
	assert(in_str);
	assert(out_str);
	int i = 0;
	i = out_str_add(out_str, i, in_str);
	if (!check_capital(in_str)) {
		i = out_str_add(out_str, i, "A");
	}
	i = out_str_add(out_str, i, "375(^_^)");
	bool first_alphanum = true;
	for (int j = i - 1; j >=0; --j) {
		if (is_alphanum(out_str[j]) && first_alphanum == true) {
			first_alphanum = false;
		} else if (is_alphanum(out_str[j])) {
			char c_arr[] = {out_str[j], '\0'};
			i = out_str_add(out_str, i, c_arr);
		}
	}
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
