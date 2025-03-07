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

// quicksort.c [IMPLEMENTATION]

#include <assert.h>
#include <stdbool.h>
#include "quicksort.h"
#include "array_tools.h"
#include "stack.h"

// === HELPER FUNCTIONS =======================================================

// swap(a, b) swaps the value in a and b.
// requires: a and b must be valid
// effects: modifies *a and *b
static void swap(int *a, int *b) {
  assert(a && b);
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// === QUICK SORT =============================================================

// see quicksort.h for documentation
void quick_sort(int arr[], int arr_len) {
  // your implementation goes here
}
