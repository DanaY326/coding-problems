#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "llt_make_free.h"

// See documentation in llt_make_free.h
struct llt *llt_read(void) {
  //...
  int n = 0;
  struct llt *t = NULL;
  if (scanf("%d", &n) == 1) {
    t = malloc(sizeof(struct llt));
    if (n > 0) {
      t->val = n;
      t->children = malloc(n * sizeof(struct llt *));
      for (int i = 0; i < n; ++i) {
        t->children[i] = llt_read();
      }
      return t;
    } else if (scanf("%d", &n) == 1) {
      t->val = n;
      t->children = NULL;
      return t;
    } 
  }
  return NULL;
}


// See documentation in llt_make_free.h
void llt_destroy(struct llt *t) {
  // ...
  assert(t);
  if (t->children) {
    for (int i = 0; i < t->val; ++i) {
      llt_destroy(t->children[i]);
    }
    free(t->children);
  } 
  free(t);
}
