#include <stdio.h>
#include <stdlib.h>

int binarysearch(size_t const len, int a[len], int t) {
  if (len == 0) {
    return -1;
  }

  size_t p = len / 2;
  if (t < a[p]) {
    return binarysearch(p, a, t);
  } else if (a[p] < t) {
    size_t q = binarysearch((len%2 && len != 1) ? p+1 : p, a+p, t);
    if (q == -1) return q;
    else return p + q;
  } else {
    return p;
  }
}

int main(int argc, char* argv[argc+1]) {
  int a[] = {1, 3, 5, 7, 9};
  size_t len = sizeof a / sizeof a[0];
  int t = 5;
  int r = binarysearch(len, a, t);
  printf("%d\n", r);
  return EXIT_SUCCESS;
}
