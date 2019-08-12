#include <stdio.h>
#include <stdlib.h>

void rotate(size_t len, char a[len], size_t delta) {
  // printf("a = %s, len = %lu, delta = %lu\n", a, len, delta);
  char t;
  if (len - delta >= delta) {
    for (size_t i = 0; i < delta; ++i) {
      t = a[i+delta];
      a[i+delta] = a[i];
      a[i] = t;
    }
    if (len == delta * 2) return;
    rotate(len - delta, a + delta, delta);
  } else {
    delta = len - delta;
    size_t last = len - 1;
    for (size_t i = 0; i < delta; ++i) {
      t = a[last - i - delta];
      a[last - i - delta] = a[last - i];
      a[last - i] = t;
    }
    if (len == delta * 2) return;
    rotate(len - delta, a, len - delta - delta);
  }
}

int main(int argc, char* argv[argc+1]) {
  char a[] = "abcdefgh";
  size_t len = (sizeof a / sizeof a[0]) - 1; // take account of '\0'
  size_t delta = 5;

  rotate(len, a, delta);
  printf("%s\n", a);
  
  return EXIT_SUCCESS;
}
