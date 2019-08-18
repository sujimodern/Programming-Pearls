#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef double subarray_algorithm(size_t n, double x[n]);

void generaterandomint(size_t n, double** p, size_t seed) {
  *p = calloc(n, sizeof **p);
  srand(time(0)+seed);
  for (size_t i = 0; i < n; ++i) {
    (*p)[i] = 2 * (rand() / (double)RAND_MAX) - 1;
  }
}

double elapsed_time(clock_t c1[static 1], clock_t c0[static 1]) {
  return (double)(c1[0] - c0[0]) / CLOCKS_PER_SEC;
}

double max(double a, double b) {
  return (a > b) ? a : b;
}

double algo4(size_t n, double x[n]) {
  double maxsofar = 0;
  double maxendinghere = 0;
  for (size_t i = 0; i < n; ++i) {
    maxendinghere = max(maxendinghere + x[i], 0);
    maxsofar = max(maxsofar, maxendinghere);
  }
  return maxsofar;
}

double run_algorithm(size_t n, double x[n], subarray_algorithm* f, char* comment) {
  double max_num;
  clock_t begin, end;
  begin = clock();
  max_num = f(n, x);
  end = clock();
  printf("%s, n = %lu, elapsed = %g, result = %g\n",
         comment, n, elapsed_time(&end, &begin), max_num);
  return max_num;
}

int main(int argc, char* argv[argc+1]) {
  size_t n = 1000;
  size_t run_count = 100;
  double cumulative = 0;

  for (size_t i = 0; i < run_count; ++i) {
    double* x = 0;
    generaterandomint(n, &x, i);
    cumulative += run_algorithm(n, x, algo4, "algorithm 4");
    free(x);
  }
  printf("average max = %g\n", cumulative/(double)run_count);

  return EXIT_SUCCESS;
}
