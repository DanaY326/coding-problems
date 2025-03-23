/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Dana Yuan
// login ID: d32yuan
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

// quick_sort_worker(first, last, arr, arr_len) sorts the elements between
//   first and last in arr using quick sort. arr_len is used for debug output
//   only.
// requires: first, last, and arr must be valid, arr_len must be positive
// effects: might modify arr
static void quick_sort_worker(int *first, int *last, 
  int *arr, int arr_len) {
  // your implementation goes here
  assert(arr_len >= 1);
  struct stack *s = stack_create();

  if (first < last) {             
    int *pivot = first;         
    int *swapper = last;       
    for (int *i = last; i > first; --i) { 
      if (*i > *pivot) {         
        swap(swapper, i);    
        --swapper;           
      }
    }
    swap(first, swapper);  
    array_print(arr, arr_len);
    quick_sort_worker(first, swapper - 1, arr, arr_len); 
    quick_sort_worker(swapper + 1, last, arr, arr_len); 
  }
}

// see quicksort.h for documentation
void quick_sort(int arr[], int arr_len) {
  // your implementation goes here
  assert(arr);
  assert(arr_len >= 1);
  quick_sort_worker(arr, arr + arr_len - 1, arr, arr_len);
}
