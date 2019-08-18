#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int subarray_algorithm(size_t n, int x[n], size_t count[static 1]);

void generaterandomint(size_t n, int** p, int max_num) {
  *p = calloc(n, sizeof **p);
  srand(time(0));
  for (size_t i = 0; i < n; ++i) {
    (*p)[i] = rand() % (2 * max_num) - max_num;
  }
}

double elapsed_time(clock_t c1[static 1], clock_t c0[static 1]) {
  return (double)(c1[0] - c0[0]) / CLOCKS_PER_SEC;
}

int max(int a, int b, size_t count[static 1]) {
  count[0] += 1;
  return (a > b) ? a : b;
}

int algo1(size_t n, int x[n], size_t count[static 1]) {
  int maxsofar = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i; j < n; ++j) {
      int sum = 0;
      for (size_t k = i; k <= j; ++k) {
        sum += x[k];
      }
      maxsofar = max(maxsofar, sum, count);
    }
  }
  return maxsofar;
}

int algo2(size_t n, int x[n], size_t count[static 1]) {
  int maxsofar = 0;
  for (size_t i = 0; i < n; ++i) {
    int sum = 0;
    for (size_t j = i; j < n; ++j) {
      sum += x[j];
      maxsofar = max(maxsofar, sum, count);
    }
  }
  return maxsofar;
}

int algo3_inner(size_t n, int x[n], size_t l, size_t u, size_t count[static 1]) {
  if (l > u) return 0;
  if (l == u) return max(0, x[l], count);
  int lmax, rmax, sum;
  size_t m = (l + u) / 2;
  lmax = sum = 0;
  for (size_t i = m; l <= i && i <= n; --i) {
    sum += x[i];
    lmax = max(lmax, sum, count);
  }
  rmax = sum = 0;
  for (size_t i = m+1; i<= u; ++i) {
    sum += x[i];
    rmax = max(rmax, sum, count);
  }
  return max(lmax+rmax, max(algo3_inner(n, x, l, m, count), algo3_inner(n, x, m+1, u, count), count), count);
}

int algo3(size_t n, int x[n], size_t count[static 1]) {
  return algo3_inner(n, x, 0, n-1, count);
}

int algo4(size_t n, int x[n], size_t count[static 1]) {
  int maxsofar = 0;
  int maxendinghere = 0;
  for (size_t i = 0; i < n; ++i) {
    maxendinghere = max(maxendinghere + x[i], 0, count);
    maxsofar = max(maxsofar, maxendinghere, count);
  }
  return maxsofar;
}

int run_algorithm(size_t n, int x[n], subarray_algorithm* f, char* comment) {
  int max_num;
  clock_t begin, end;
  size_t count = 0;
  begin = clock();
  max_num = f(n, x, &count);
  end = clock();
  printf("%s, n = %lu, called = %lu, elapsed = %g, result = %d\n",
         comment, n, count, elapsed_time(&end, &begin), max_num);
  return max_num;
}

int main(int argc, char* argv[argc+1]) {
  int* x = 0;
  size_t n = 100;
  int abs_max_num = 500;

  generaterandomint(n, &x, abs_max_num);
  run_algorithm(n, x, algo1, "algorithm 1");
  run_algorithm(n, x, algo2, "algorithm 2");
  run_algorithm(n, x, algo3, "algorithm 3");
  run_algorithm(n, x, algo4, "algorithm 4");
  free(x);

  return EXIT_SUCCESS;
}
