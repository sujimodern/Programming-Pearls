#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum { sample_size = 3 };

typedef int subarray_algorithm(size_t n, int x[n]);

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

int max(int a, int b) {
  return (a > b) ? a : b;
}

int algo1(size_t n, int x[n]) {
  int maxsofar = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i; j < n; ++j) {
      int sum = 0;
      for (size_t k = i; k <= j; ++k) {
        sum += x[k];
      }
      maxsofar = max(maxsofar, sum);
    }
  }
  return maxsofar;
}

int algo2(size_t n, int x[n]) {
  int maxsofar = 0;
  for (size_t i = 0; i < n; ++i) {
    int sum = 0;
    for (size_t j = i; j < n; ++j) {
      sum += x[j];
      maxsofar = max(maxsofar, sum);
    }
  }
  return maxsofar;
}

int algo3_inner(size_t n, int x[n], size_t l, size_t u) {
  if (l > u) return 0;
  if (l == u) return max(0, x[l]);
  int lmax, rmax, sum;
  size_t m = (l + u) / 2;
  lmax = sum = 0;
  for (size_t i = m; l <= i && i <= n; --i) {
    sum += x[i];
    lmax = max(lmax, sum);
  }
  rmax = sum = 0;
  for (size_t i = m+1; i<= u; ++i) {
    sum += x[i];
    rmax = max(rmax, sum);
  }
  return max(lmax+rmax, max(algo3_inner(n, x, l, m), algo3_inner(n, x, m+1, u)));
}

int algo3(size_t n, int x[n]) {
  return algo3_inner(n, x, 0, n-1);
}

int algo4(size_t n, int x[n]) {
  int maxsofar = 0;
  int maxendinghere = 0;
  for (size_t i = 0; i < n; ++i) {
    maxendinghere = max(maxendinghere + x[i], 0);
    maxsofar = max(maxsofar, maxendinghere);
  }
  return maxsofar;
}

int run_algorithm(size_t n, int x[n], subarray_algorithm* f, char* comment) {
  int max_num;
  clock_t begin, end;
  begin = clock();
  max_num = f(n, x);
  end = clock();
  printf("%s, n = %lu, elapsed = %g, result = %d\n",
         comment, n, elapsed_time(&end, &begin), max_num);
  return max_num;
}

int main(int argc, char* argv[argc+1]) {
  size_t n[sample_size] = {100, 1000, 10000};
  int abs_max_num = 500;
  for (size_t i = 0; i < sample_size; ++i) {
    int* x = 0;
    generaterandomint(n[i], &x, abs_max_num);
    run_algorithm(n[i], x, algo1, "algorithm 1");
    run_algorithm(n[i], x, algo2, "algorithm 2");
    run_algorithm(n[i], x, algo3, "algorithm 3");
    run_algorithm(n[i], x, algo4, "algorithm 4");
    free(x);
  }

  return EXIT_SUCCESS;
}
