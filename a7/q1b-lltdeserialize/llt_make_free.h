#ifndef _LLT_MAKE_FREE_H_
#define _LLT_MAKE_FREE_H_

struct llt {
  int val;
  struct llt **children;
};

// llt_read(void) Read from stdin and creates a struct llt in the heap.
// The data are serialized as follows:
// * A leaf shall be stored as the integer 0 followed by the label for
//   the leaf;
// * A non-leaf shall be stored as a positive integer representing the
//   number of children of a node, followed by the representations of
//   all its children, recursively.
// If the first read fails, return NULL (indicating that no further
// trees are available to read).

// effects: reads from stdin
//          allocates memory; user must call llt_destroy.
// time: O(n) where n is the number of nodes in the tree.
struct llt *llt_read(void);

// llt_destroy(t) Clean up t.
// effects: frees memory.
void llt_destroy(struct llt *t);

#endif
