#include <stdio.h>
#include <stdlib.h>

enum { n = 1000, max_abs_value = 500, fix_value_to_reproduce = 1560910215 };

void swap(int a[static 1], int b[static 1]) {
  int t = b[0];
  b[0] = a[0];
  a[0] = t;
}

void qsort3(size_t n, int x[n], int l, int u) {
  if (l >= u) {
    return;
  } else {
    int t = x[l];
    int i = l;
    int j = u+1;
    for (;;) {
      do {
        ++i;
      } while (i <= u && x[i] < t);
      do {
        --j;
      } while (x[j] > t);
      if (i > j) {
        break;
      }
      swap(&x[i], &x[j]);
    }
    swap(&x[l], &x[j]);
    qsort3(n, x, l, j-1);
    qsort3(n, x, j+1, u);
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
    // x[i] = rand() % (max_abs_value * 2) - max_abs_value;
    x[i] = 3;
  }

	printarray(n, x, "before sort:");
  qsort3(n, x, 0, n-1);
	printarray(n, x, "after sort:");

  free(x);
  return EXIT_SUCCESS;
}
