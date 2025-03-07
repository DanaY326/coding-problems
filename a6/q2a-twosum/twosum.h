// two_sum_one(a, len, first, second) finds two values at different indices
//   of array a whose sum is closest to zero and stores these two values 
//   in *first and *second. Mutated *first must be smaller than mutated
//   *second.
// requires: a is a valid array, len >= 2, first and second are valid
// time:     O(n^2)
void two_sum_one(const int a[], int len, int *first, int *second);

// two_sum_two(a, len, first, second) finds two values at different indices
//   of array a whose sum is closest to zero and stores these two values 
//   in *first and *second. Mutated *first must be smaller than mutated
//   *second.
// requires: a is a valid array, len >= 2, first and second are valid
// time: O(nlogn)
void two_sum_two(int a[], int len, int *first, int *second);
