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

// set.c [IMPLEMENTATION]

#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

// see set.h for documentation
struct Set *set_create(int n) {
  // add your implementation
  struct Set *s = malloc(sizeof(struct Set));
  s->data = malloc(n * sizeof(int));
  s->maxlen = n;
  s->len = 0;
  return NULL;
}

// see set.h for documentation
void set_destroy(struct Set *s) {
  // add your implementation
  assert(s);
  free(s->data);
  free(s);
}

// see set.h for documentation
int set_length(const struct Set *s) {
  // add your implementation
  return s->len;
}

// see set.h for documentation
void set_add(struct Set *s, int v) {
  // add your implementation
  assert(s);
  int temp1 = 0;
  int temp2 = 0;
  for (int i = 0; i < s->len; ++i) {
    if (*(s->data + i) > v) {
      temp2 = v;
      for (int j = i; j < s->len; ++j) {
        temp1 = *(s->data + j);
        *(s->data + j) = temp2;
        temp2 = temp1;
      }
      break;
    }
  }
  s->data[s->len] = v;
  s->len++;
  if (s->len == s->maxlen) {
    s->data = realloc(s->data, 2 * s->maxlen * sizeof(int));
    s->maxlen *= 2;
  }
}

// see set.h for documentation
void set_remove(struct Set *s, int v) {
  // add your implementation
  assert(s);
  for (int i = 0; i < s->len; ++i) {
    if (s->data[i] == v) {
      for (int j = i; j < s->len; ++j) {
        s->data[j] = s->data[j + 1];
      }
      s->len--;
      return;
    }
  }
}

// see set.h for documentation
// O(log n) ???
bool set_is_member(const struct Set *s, int v) {
  // add your implementation
  assert(s);
  for (int i = 0; i < s->len; ++i) {
    if (s->data[i] == v) {
      return true;
    }
  }
  return false;
}

// see set.h for documentation
struct Set *set_union(const struct Set *s1, const struct Set *s2) {
  // add your implementation
  assert(s1);
  assert(s2);
  set_create(s1->maxlen + s2->maxlen);

  return NULL;
}

// see set.h for documentation
struct Set *set_intersect(const struct Set *s1, const struct Set *s2) {
  // add your implementation
  assert(s1);
  assert(s2);
  return NULL;
}

// see set.h for documentation
bool set_is_subset(const struct Set *s1, const struct Set *s2) {
  // add your implementation
  assert(s1);
  assert(s2);
  return false;
}

// see set.h for documentation
struct Set *set_difference(const struct Set *s1, const struct Set *s2) {
  // add your implementation
  assert(s1);
  assert(s2);
  return NULL;
}

// see set.h for documentation
void set_print(const struct Set *s) {
  // add your implementation
  assert(s);
  printf("[");
  for (int i = 0; i < s->len; ++i) {
    printf("%d", s->data[i]);
    if (i < s->len - 1) {
      printf("%c", ',');
    }
  }
  printf("]\n", s->data[s->len]);
}
