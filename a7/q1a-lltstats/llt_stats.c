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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "llt_stats.h"
#include "llt_make_free.h"

// complete your work in this file.

// count_leaves(t) Count how many leaves there are in t.
int count_leaves(const struct llt *t) {
    if (!t->children) {
        return 1;
    }
    int ct = 0;
    for (int i = 0; i < t->val; ++i) {
        ct += count_leaves(t->children[i]);
    }
    return ct;
}

// returns the number of leaves added to arr
static void flatten_to_arr(const struct llt *t, int *len, int *arr) {
    if (t->children) {
        for (int i = 0; i < t->val; ++i) {
            flatten_to_arr(t->children[i], len, arr);
        }
    } else {
        arr[*len] = t->val;
        ++(*len);
    }
}

// flatten(t, len) Create an array containing all the (leaf) values
// stored in t, in order.  Mutate *len so it contains the length of
// this array.
// effects: allocates memory; caller must call free; mutates len.
// time: O(n)
int *flatten(const struct llt *t, int *len) {
    *len = 0;
    int *arr = malloc(count_leaves(t) * sizeof(int));
    flatten_to_arr(t, len, arr);
    return arr;
}

void llt_print_worker(const struct llt *t) {
    if (t->children) {
        printf("<");
        for (int i = 0; i < t->val; ++i) {
            llt_print(t->children[i]);
            if (i < t->val - 1) {
                printf(", ");
            }
        }
        printf(">");
    } else {
        printf("%d", t->val);
    }
}

// llt_print(t) Print the tree t, nicely, with brackets.
void llt_print(const struct llt *t) {
    llt_print_worker(t);
    printf("\n");
}