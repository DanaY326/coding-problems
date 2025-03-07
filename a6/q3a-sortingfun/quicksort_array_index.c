#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "quicksort.h"
#include "array_tools.h"

// === HELPER FUNCTIONS =======================================================
// swap(a, b) swaps the value in a and b.
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
static void quick_sort_worker(int arr[], int arr_len, int first, int last) {
  assert(arr_len >= 1);
  if (first < last) {                    // if there are still some elements to sort
    int pivot = arr[first];              // pick pivot element
    int swapper = last;                  // set the swapper to the last element in arr
    for (int i = last; i > first; --i) { // going backwards through arr
      if (arr[i] > pivot) {         // if arr[i] should be "right of" pivot
        swap(&arr[swapper], &arr[i]);    // swap arr[i] and swapper
        --swapper;                       // move the swapper to the next "unswapped" element
      }
    }
    swap(&arr[first], &arr[swapper]);    // swap the pivot element into the right spot
    array_print(arr, arr_len);
    quick_sort_worker(arr, arr_len, first, swapper - 1); // recursive call on the "left" sub-array
    quick_sort_worker(arr, arr_len, swapper + 1, last);  // recursive call on the "right" sub-array
  }
}

// see quicksort.h for documentation
void quick_sort(int arr[], int arr_len) {
  assert(arr);
  assert(arr_len >= 1);
  quick_sort_worker(arr, arr_len, 0, arr_len - 1);
}
