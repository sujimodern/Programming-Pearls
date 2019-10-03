#include <stdio.h>
#include <stdlib.h>

enum { m = 20, n = 200, fix_value_to_reproduce = 1558341867 };

int bigrand() {
  return rand();
}

int randint(int i, int j) {
  int width = j - i + 1;
  return bigrand() % width + i;
}

void printarray(size_t n, int x[n]) {
  for (size_t i = 0; i < n; ++i) {
    printf("%d ", x[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[argc+1]) {
  srand(fix_value_to_reproduce);
  int* x = malloc(m * sizeof *x);

  size_t r;
  size_t len = n / m;
  for (size_t i = 0; i < m; ++i) {
    r = randint(i * len, (i+1) * len - 1);
    x[i] = r;
  }
  printarray(m, x);

  free(x);
  return EXIT_SUCCESS;
}
