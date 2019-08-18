#include <stdio.h>
#include <stdlib.h>

enum { n = 10 };

int main(int argc, char* argv[argc+1]) {
  int x[n] = { 1, 3, 4, 6, 9, 11, 19, 19, 19, 20 };
  int t = 19;
  size_t l, u, m, p;

  l = -1;
  u = n;
  while (l+1 != u) {
    m = (l + u) / 2;
    if (x[m] < t) {
      l = m;
    } else {
      u = m;
    }
  }
  p = u;
  if (p >= n || x[p] != t) {
    p = -1;
  }
  printf("p = %lu\n", p);

  return EXIT_SUCCESS;
}
