#include <stdio.h>
#include <stdlib.h>

enum { n = 100, max_abs_val = 10000 };

void swap(int* a, int* b) {
  int t = *b;
  *b = *a;
  *a = t;
}

/* Nico Lomuto's way */
void qsort1(size_t n, int x[n], int l, int u) {
  if (l >= u) { return; }
  int m = l;
  for (size_t i = l; i <= u; ++i) {
    if (x[l] > x[i]) {
      ++m;
      swap(&x[m], &x[i]);
    }
  }
  swap(&x[m], &x[l]);
  qsort1(n, x, l, m-1);
  qsort1(n, x, m+1, u);
}

/* Bob Sedgewick's way */
void qsort2(size_t n, int x[n], int l, int u) {
  if (l >= u) { return; }
  int m = u+1;
  int i = u+1;
  do {
    while (x[--i] < x[l]);
    swap(&x[--m], &x[i]);
  } while (i != l);
  qsort2(n, x, l, m-1);
  qsort2(n, x, m+1, u);
}

void genrandarray(size_t n, int x[n], int max_abs) {
  for (size_t i = 0; i < n; ++i) {
    x[i] = rand() % (max_abs * 2) - max_abs;
  }
}

void printarray(size_t n, int x[n]) {
  for (size_t i = 0; i < n; ++i) {
    printf("%d ", x[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[argc+1]) {
  int* x = malloc(n * sizeof *x);

  genrandarray(n, x, max_abs_val);
  printarray(n, x);
  qsort2(n, x, 0, n-1);
  printarray(n, x);
  
  free(x);
  return EXIT_SUCCESS;
}
