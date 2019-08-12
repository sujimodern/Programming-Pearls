#include <stdio.h>
#include <stdlib.h>

void rotate(size_t len, char a[len], size_t delta) {
  char t = a[0];
  size_t i = 0;
  size_t next;
  for (;;) {
    next = (i+delta) % len;
    if (!next) {
      a[i] = t;
      break;
    }
    a[i] = a[next]; 
    i = next;
  }
}

int main(int argc, char* argv[argc+1]) {
  char a[] = "abcdefghijklmnopqrstuvwxyz";
  size_t delta = 7;
  size_t len = (sizeof a/sizeof a[0]) - 1; // take account of '\0'

  rotate(len, a, delta);
  printf("%s\n", a);

  return EXIT_SUCCESS;
}
