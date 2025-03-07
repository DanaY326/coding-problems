// A program to test the quicksort module

#include "array_tools.h"
#include "quicksort.h"

int main(void) {
  int arr[10] = { 0 };
  int arr_len = array_read(arr, 10);

  quick_sort(arr, arr_len);
}
