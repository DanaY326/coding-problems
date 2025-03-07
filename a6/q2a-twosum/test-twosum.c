#include <assert.h>
#include <stdio.h>

#include "array_tools.h"
#include "twosum.h"

int main(void) {
  int a[10] = { 0 };
  int b[10] = { 0 };
  int len = array_read(a, 10);
  for (int i = 0; i < 10; i++) {
    b[i] = a[i];
  }

  int first = 0;
  int second = 0;
  two_sum_one(a, len, &first, &second);
  printf("%d %d\n", first, second);

  first = 0;
  second = 0;
  two_sum_two(b, len, &first, &second);
  printf("%d %d\n", first, second);
}
