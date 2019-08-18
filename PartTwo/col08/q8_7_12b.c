#include <stdio.h>
#include <stdlib.h>

enum { len = 10 };

int main(int argc, char* argv[argc+1]) {
  int x[len] = { 0 };
  size_t larray[len] = {1, 3, 0, 5, 9, 2, 3, 6, 2, 1};
  size_t uarray[len] = {9, 2, 8, 9, 9, 6, 4, 9, 5, 6};
  int varray[len] = {3, -1, 8, 12, 7, 1, 5, -8, -9};

  for (size_t i = 0; i < len; ++i) {
    printf("%d\n", x[i]);
  }

  return EXIT_SUCCESS;
}
