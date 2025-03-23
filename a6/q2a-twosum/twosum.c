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

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "twosum.h"

void two_sum_one(const int a[], int len, int *first, int *second) {
    assert(a);
    assert(len >= 2);
    assert(first);
    assert(second);
    *first = a[0];
    *second = a[1];
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (abs(a[i] + a[j]) < abs(*first + *second)) {
                *first = a[i];
                *second = a[j];
            }
        }
    }
    if (*first > *second) {
        int temp = *first;
        *first = *second;
        *second = temp;
    }    
}

// merge(dest, a1, len1, a2, len2) sorts a1 and a2 into one array which is contained in dest
// requires: length of dest is at least (len1 + len2) [not asserted]
//           a1 and a2 are sorted [not asserted]
// effects: modifies dest
// time: O(n), where n is len1 + len2
void merge(int dest[], const int a1[], int len1,
    const int a2[], int len2) {
        assert(dest);
        assert(a1);
        assert(a2);
        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i < len1 + len2; ++i) {
            if (pos1 == len1 || (pos2 < len2 && a2[pos2] < a1[pos1])) {
                dest[i] = a2[pos2];
                ++pos2;
            } else {
                dest[i] = a1[pos1];
                ++pos1;
            }
        }
}

// merge_sort(a, len) sorts array a into ascending order
// requires: a is a valid array with given len [not asserted]
// effects: modifies a
// time: O(nlogn)
void merge_sort(int a[], int len) {
  assert(a);
  if (len <= 1) {
    return;
  }
  int l_len = len / 2;
  int r_len = len - l_len;
  
  int *left = malloc(l_len * sizeof(int));
  int *right = malloc(r_len * sizeof(int));
  
  for (int i = 0; i < l_len; ++i) {
    left[i] = a[i];
  }
  for (int i = 0; i < r_len; ++i) {
    right[i] = a[i + l_len];
  }
  
  merge_sort(left, l_len);
  merge_sort(right, r_len);
  
  merge(a, left, l_len, right, r_len);
  
  free(left);
  free(right);
}

void two_sum_two(int a[], int len, int *first, int *second) {
    merge_sort(a, len);
    int left = 0;
    int right = len - 1;
    *first = a[left];
    *second = a[right];
    while (right > left) {
        //printf("left:%d righ:%d a[left]:%d a[right]:%d *first:%d *second:%d\n", left, right, a[left], a[right], *first, *second);
        if (abs(a[left + 1] + *second) < abs(a[left] + *second)) {
            ++left;
        } else if (abs(*first + a[right - 1]) < abs(*first + a[right])) {
            --right;
        } else {
            ++left;
            --right;
        }
        if (abs(a[left] + *second) < abs(*first + *second)) {
            *first = a[left];
        }
        if (*first + abs(a[right]) < abs(*first + *second)) {
            *second = a[right];
        }
    }
}
