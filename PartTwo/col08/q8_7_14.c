#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1]) {
  srand(time(0));
  size_t n = rand() % 100;
  size_t m = rand() % n;
  double max = 10.0;
  double mean = 5.0;
  printf("n = %lu, m = %lu\n", n, m);

  double* x = malloc(n * sizeof *x);
  for (size_t i = 0; i < n; ++i) {
    x[i] = (double)rand() / RAND_MAX * max - mean;
  }

  for (size_t i = 0; i < n - m; ++i) {
  }
  
  return EXIT_SUCCESS;
}
