#include <stdio.h>
#include <stdlib.h>

enum { n = 100, max_abs_val = 1000 };

void swap(int* a, int* b) {
  int t = *b;
  *b = *a;
  *a = t;
}

void selsort(size_t n, int x[n]) {
  for (size_t i = 0; i < n-1; ++i) {
    for (size_t j = i; j < n; ++j) {
      if (x[i] > x[j]) {
        swap(&x[i], &x[j]);
      }
    }
  }
}

void printarray(size_t n, int x[n]) {
  for (size_t i = 0; i < n; ++i) {
    printf("%d ", x[i]);
  }
  printf("\n");
}

void genrandarray(size_t n, int x[n]) {
  for (size_t i = 0; i < n; ++i) {
    x[i] = rand() % (max_abs_val * 2) - max_abs_val;
  }
}

int main(int argc, char* argv[argc+1]) {
  int* x = malloc(n * sizeof *x); 

  genrandarray(n, x);
  printarray(n, x);
  selsort(n, x);
  printarray(n, x);

  free(x);
  return EXIT_SUCCESS;
}
