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

int count_leaves(const struct llt *t) {
    assert(t);

    if (t->children) { 
        int ct = 0;
        for (int i = 0; i < t->val; ++i) {
            ct += count_leaves(t->children[i]);
        }
        return ct;
    }

    return 1;
}

// flatten_to_arr(t, len, arr) adds all values of t to arr in order
// and increases *len by the number of values added to arr 
// requires: arr have space for all leaves of t [not asserted]
//           t, len and arr are valid
// effects: mutates len.
// time: O(n)
static void flatten_to_arr(const struct llt *t, int *len, int *arr) {
    assert(t);
    assert(len);
    assert(arr);

    if (t->children) {
        for (int i = 0; i < t->val; ++i) {
            flatten_to_arr(t->children[i], len, arr);
        }
    } else {
        arr[*len] = t->val;
        ++(*len);
    }
}

int *flatten(const struct llt *t, int *len) {
    assert(t);
    assert(len);

    *len = 0;
    int *arr = malloc(count_leaves(t) * sizeof(int));
    flatten_to_arr(t, len, arr);
    return arr;
}

// llt_print_worker(t) prints out t with each non-leaf node as a list of its nodes surrounded
// by <> brackets and separated by commas and each leaf node as a number
// does not include a newline at the end, allowing it to call itself recursively
// requires: t is valid
// effects: produces output
// time: O(n)
static void llt_print_worker(const struct llt *t) {
    if (t != NULL) {{
        if (t->children) { 
            printf("<");
            for (int i = 0; i < t->val; ++i) {
                llt_print_worker(t->children[i]);
                if (i < t->val - 1) {
                    printf(", ");
                }
            }
            printf(">");
        } else {
            printf("%d", t->val);
        }
    }}
    assert(t);
}

void llt_print(const struct llt *t) {
    assert(t);

    llt_print_worker(t);
    printf("\n");
}