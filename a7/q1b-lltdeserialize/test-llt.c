#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "llt_make_free.h"
#include "llt_stats.h"
#include "array_tools.h"

int main(void) {
  struct llt *t = NULL;
  int *flat = NULL;
  int flatlen = 0;

  printf("Reading trees from stdin.\n"); 
  
  while ((t = llt_read()) != NULL) {
    printf("\nNew tree of %d leaves:\n",
           count_leaves(t));
    
    llt_print(t);

    flat = flatten(t, &flatlen);
    array_print(flat, flatlen);
    free(flat);
    
    llt_destroy(t);
  }
}
