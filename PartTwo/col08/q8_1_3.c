#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int maxsum3(size_t len, int x[len], size_t l, size_t u) {
  if (l > u) {
    return 0;
  } else if (l == u) {
    return max(0, x[l]);
  } else {
    int lmax, rmax, sum;
    size_t m = (l + u) / 2;
    lmax = sum = 0;
    for (size_t i = m; l <= i && i <= len; --i) { // size_t always positive. I should use int instead of size_t.
      sum += x[i];
      lmax = max(lmax, sum);
    }
    rmax = sum = 0;
    for (size_t i = m+1; i <= u; ++i) {
      sum += x[i];
      rmax = max(rmax, sum);
    }
    return max(lmax+rmax, max(maxsum3(len, x, l, m), maxsum3(len, x, m+1, u)));
  }
}

int main(int argc, char* argv[argc+1]) {
  int x[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
  size_t n = sizeof x / sizeof x[0];

  int m = maxsum3(n, x, 0, n-1);

  printf("max = %d\n", m);
  return EXIT_SUCCESS;
}
