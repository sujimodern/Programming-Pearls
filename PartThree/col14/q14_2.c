#include <stdio.h>
#include <stdlib.h>

enum { len = 14, root = 1 };

void swap(int* a, int* b) {
  int* t;
  t = b;
  b = a;
  a = t;
}

void shiftup(size_t len, int x[len], size_t n) {
  size_t i, p;
  i = n;
  for (;;) {
    if (i == 1) { break; }
    p = i/2;
    if (x[p] <= x[i]) { break; }
    swap(&x[p], &x[i]);
    i = p;
  }
}

void shiftdown(size_t len, int x[len], size_t n) {
  size_t i, c;
  i = 1;
  for (;;) {
    c = 2*i; 
    if (c > n) { break; }
    if (c+1 <= n) {
      if (x[c+1] < x[c]) { c += 1; }
    }
    if (x[i] <= x[c]) { break; }
    swap(&x[c], &x[i]);
    i = c;
  }
}

int main(int argc, char* argv[argc+1]) {
  int x[len] = {0, 12, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19, 13};
  int y[len] = {0, 18, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19, 100};

  shiftup(len, x, len-1);
  shiftdown(len, x, len-1);

  for (size_t i = 0; i < len; ++i) {
    printf("%d ", x[i]);
  }
  puts("");
  for (size_t i = 0; i < len; ++i) {
    printf("%d ", y[i]);
  }
  puts("");

  return EXIT_SUCCESS;
}
