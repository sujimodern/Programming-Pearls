#include <stdio.h>
#include <stdlib.h>

enum { n = 1000, max_abs_value = 500, fix_value_to_reproduce = 1560910215 };

void swap(int a[static 1], int b[static 1]) {
  int t;
  t = b[0];
  b[0] = a[0];
  a[0] = t;
}

void isort1(size_t n, int x[n]) {
  for (size_t i = 1; i < n; ++i) {
    for (size_t j = i; j > 0 && x[j-1] > x[j]; --j) {
      swap(&x[j-1], &x[j]);
    }
  }
}

void printarray(size_t n, int x[n], char* comment) {
  printf("%s\n", comment);
  for (size_t i = 0; i < n; ++i) {
    printf("%d ", x[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[argc+1]) {
  int* x = malloc(n * sizeof *x);

  srand(fix_value_to_reproduce);
  for (size_t i = 0; i < n; ++i) {
    x[i] = rand() % (max_abs_value * 2) - max_abs_value;
  }

  printarray(n, x, "before sort:");
  isort1(n, x);
  printarray(n, x, "after sort:");

  free(x);
  return EXIT_SUCCESS;
}
