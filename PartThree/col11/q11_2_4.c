#include <stdio.h>
#include <stdlib.h>

enum { cutoff = 10, n = 1000, max_abs_value = 500, fix_value_to_reproduce = 1560910215 };

void swap(int a[static 1], int b[static 1]) {
  int t = b[0];
  b[0] = a[0];
  a[0] = t;
}

void isort3(size_t n, int x[n]) {
  int t;
  size_t j;
  for (size_t i = 1; i < n; ++i) {
    t = x[i];
    for (j = i; j > 0 && x[j-1] > x[j]; --j) {
      x[j] = x[j-1];
    }   
    x[j-1] = t;
  }
}

int randint(int l, int u) {
  srand(fix_value_to_reproduce);
  return (int)(((double)rand() / RAND_MAX) * (u - l + 1)) + l;
}

void qsort4(size_t n, int x[n], int l, int u) {
  if (u - l < cutoff) {
    return;
  } else {
    swap(&x[l], &x[randint(l, u)]);
    int t = x[l];
    int i = l;
    int j = u+1;
    int temp;
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
      temp = x[i];
      x[i] = x[j];
      x[j] = temp;
    }
    swap(&x[l], &x[j]);
    qsort4(n, x, l, j-1);
    qsort4(n, x, j+1, u);
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
  qsort4(n, x, 0, n-1);
	isort3(n, x);
	printarray(n, x, "after sort:");

  free(x);
  return EXIT_SUCCESS;
}
