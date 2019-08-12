#include <stdio.h>
#include <stdlib.h>

int binarysearch(size_t const len, int const a[len], int const t, size_t* const count) {
  *count += 1;
  if (len == 0) {
    return -1;
  }

  size_t p = len / 2;
  if (t < a[p]) {
    return binarysearch(p, a, t, count);
  } else if (a[p] < t) {
    size_t q = binarysearch((len%2 && len != 1) ? p+1 : p, a+p, t, count);
    if (q == -1) return q;
    else return p + q;
  } else {
    return p;
  }
}

int main(int argc, char* argv[argc+1]) {
  int a[] = {1, 1, 3, 3, 9};
  size_t len = sizeof a / sizeof a[0];
  int t = 1;
  size_t count = 0;
  int r = binarysearch(len, a, t, &count);
  printf("index: %d\n", r);
  printf("count: %lu\n", count);
  return EXIT_SUCCESS;
}
