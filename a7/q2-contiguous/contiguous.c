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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "contiguous.h"

struct contiguous {
  struct cnode *first;
  void *upper_limit;
};

struct cnode {
  size_t nsize;
  struct cnode *prev;
  struct cnode *next;
  struct contiguous *block;
};

const int SIZEOF_CONTIGUOUS = sizeof(struct contiguous);
const int SIZEOF_CNODE = sizeof(struct cnode);



static const char STAR_STR[] = "*";
static const char NULL_STR[] = "NULL";

// maybe_null(void *p) return a pointer to "NULL" or "*",
//   indicating if p is NULL or not.
static const char *maybe_null(void *p) {
  return p ? STAR_STR : NULL_STR;
}

// gapsize(n0, n1) determine the size (in bytes) of the gap between n0 and n1.
static size_t gapsize(struct cnode *n0, struct cnode *n1) {
  assert(n0);
  assert(n1);
  void *v0 = n0;
  void *v1 = n1;
  return (v1 - v0) - n0->nsize - sizeof(struct cnode);
}

// print_gapsize(n0, n1) print the size of the gap between n0 and n1,
//     if it's non-zero.
static void print_gapsize(struct cnode *n0, struct cnode *n1) {
  assert(n0);
  assert(n1);
  size_t gap = gapsize(n0, n1);
  
  if (gap != 0) { 
    printf("%zd byte gap\n", gap);
  }
}


// pretty_print_block(chs, size) Print size bytes, starting at chs,
//    in a human-readable format: printable characters other than backslash
//    are printed directly; other characters are escaped as \xXX
static void pretty_print_block(unsigned char *chs, int size) {
  assert(chs);
  for (int i = 0; i < size; i++) {
    printf(0x20 <= chs[i] && chs[i] < 0x80 && chs[i] != '\\'
           ? "%c" : "\\x%02X", chs[i]);
  }
  printf("\n");
}

// print_node(node) Print the contents of node and all nodes that
//    follow it.  Return a pointer to the last node.
static struct cnode *print_node(struct cnode *node) {
  while (node != NULL) {
    void *raw = node + 1;     // point at raw data that follows.
    printf("struct cnode\n");
    printf("    nsize: %ld\n", node->nsize);
    printf("    prev: %s\n", maybe_null(node->prev));
    printf("    next: %s\n",  maybe_null(node->next));

    printf("%zd byte chunk: ", node->nsize);
    
    pretty_print_block(raw, node->nsize);
    
    if (node->next == NULL) {
      return node;
    } else {
      print_gapsize(node, node->next);
      node = node->next;
    }
  }
  return NULL;
}



static void print_hr(void) {
    printf("----------------------------------------------------------------\n");
}

// print_debug(block) print a long message showing the content of block.
void print_debug(struct contiguous *block) {
  assert(block);
  void *raw = block;

  print_hr();
  printf("struct contiguous\n");
  printf("    first: %s\n", maybe_null(block->first));

  if (block->first == NULL) {
    size_t gap = block->upper_limit - raw - sizeof(struct contiguous);
    printf("%zd byte gap\n", gap);           
  } else {
    void *block_first = block->first;
    size_t gap = block_first - raw - sizeof(struct contiguous);
    if (gap) {
      printf("%zd byte gap\n", gap);
    }
  }
 
  struct cnode *lastnode = print_node(block->first);
  
  if (lastnode != NULL) {
    print_gapsize(lastnode, block->upper_limit);
  }

  print_hr();
}



struct contiguous *make_contiguous(size_t size) {
  // ...
  assert(size >= sizeof(struct contiguous));
  
  void *block = malloc(size);
  struct contiguous *c = block;
  c->first = NULL;
  c->upper_limit = block + size;
  void *d = block + sizeof(struct contiguous);
  while (d < c->upper_limit) {
    char *dc = d;
    *dc = '$';
    d += sizeof(char);
  }
  return c;
}


void destroy_contiguous(struct contiguous *block) {
  // ...
  assert(block);
  if (block->first != NULL) {
    printf("Destroying non-empty block!\n");
  }
  free(block);
}


void cfree(void *p) {
  // ...
  assert(p);
  struct cnode *n = p - sizeof(struct cnode);
  if (n->prev == NULL) {
    n->block->first = n->next;
  } else {
    n->prev->next = n->next;
  }
  if (n->next != NULL) {
    n->next->prev = n->prev;
  }
}

// create_node(dest, block, size, prev, next) creates a new node and chunk at the location that dest points to
// it adds itself to the middle of a linked list with the given prev and next cnodes
// requires: dest and block are valid non-null pointers
//           prev and next are valid pointers to nodes in block [not asserted]
//           at dest there's enough space in the block for the node and its chunk [not asserted]
// effects: modifies dest
//          may modify block, prev or next
// time: O(1)

void *create_node(void *dest, struct contiguous *block, int size, struct cnode *prev, struct cnode *next) {
  assert(dest);
  assert(block);

  struct cnode *new_node = dest;
  new_node->block = block;
  new_node->prev = prev;
  if (prev == NULL) {
    block->first = new_node;
  } else {
    prev->next = new_node;
  }
  new_node->next = next;
  if (next != NULL) {
    next->prev = new_node;
  }
  new_node->nsize = size;
  return dest + sizeof(struct cnode);
}

void *cmalloc(struct contiguous *block, int size) {
  // ...
  assert(block);
  assert(size >= 0);

  struct cnode *n = block->first;
  void *nv = n;
  if (n == NULL) {
    nv = block;
    nv += sizeof(struct contiguous);
    return create_node(nv, block, size, NULL, NULL);
  }

  nv = n;
  void *nv2 = block;
  if ((nv - nv2) - sizeof(struct contiguous) >= (sizeof(struct cnode) + size)) {
    nv2 += sizeof(struct contiguous);
    return create_node(nv2, block, size, NULL, block->first);
  }

  while (n != NULL && n->next != NULL) {
    if ((n->next != NULL && (gapsize(n, n->next) >= (sizeof(struct cnode) + size)))) {
      nv = n;
      nv += sizeof(struct cnode) + n->nsize;
      return create_node(nv, block, size, n, n->next);
    }
    n = n->next;
  }

  nv = n;
  if ((block->upper_limit - nv) - sizeof(struct cnode) - n->nsize >= (sizeof(struct cnode) + size)) {
    nv += sizeof(struct cnode) + n->nsize;
    return create_node(nv, block, size, n, NULL);
  }

  return NULL;
}


