#include "llt_make_free.h"

// count_leaves(t) Count how many leaves there are in t.
int count_leaves(const struct llt *t);

// flatten(t, len) Create an array containing all the (leaf) values
// stored in t, in order.  Mutate *len so it contains the length of
// this array.
// effects: allocates memory; caller must call free; mutates len.
// time: O(n)
int *flatten(const struct llt *t, int *len);


// llt_print(t) Print the tree t, nicely, with brackets.
void llt_print(const struct llt *t);
