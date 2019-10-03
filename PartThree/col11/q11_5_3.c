#include <time.h>
#include <stdio.h>
#include <stdlib.h>

enum { n = 10000, max_abs_val = 1000000 };

void swap(int* a, int* b) {
  int t = *b;
  *b = *a;
  *a = t;
}

void isort3(size_t n, int x[n]) {
  for (size_t i = 1; i < n; ++i) {
    int t = x[i];
    int j;
    for (j = i; j > 0 && x[j-1] > x[j]; --j) {
      x[j] = x[j-1];
    }
    x[j] = t;
  }
}

void qsort4(size_t n, int x[n], int l, int u, int cutoff) {
  if (u-l < cutoff) { return; }
  int t = x[l];
  int i = l;
  int j = u+1;
  for (;;) {
    do { ++i; } while (i <= u && x[i] < t);
    do { --j; } while (x[j] > t);
    if (i > j) { break; }
    swap(&x[i], &x[j]);
  }
  swap(&x[l], &x[j]);
  qsort4(n, x, l, j-1, cutoff);
  qsort4(n, x, j+1, u, cutoff);
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
  clock_t start, end;
  double elapsed;

  genrandarray(n, x, max_abs_val);
  for (int cutoff = 1; cutoff < 90; cutoff += 1) {
    start = clock();
    qsort4(n, x, 0, n-1, cutoff);
    isort3(n, x);
    end = clock();
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%d\t%g\n", cutoff, elapsed);
  }
  
  free(x);
  return EXIT_SUCCESS;
}
