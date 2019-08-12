#include <stdio.h>
#include <stdlib.h>

void reverse(size_t len, char a[len], size_t start, size_t end) {
  size_t subject_len = end - start + 1;
  char t;
  for (size_t i = 0; i < (subject_len / 2); ++i) {
    t = a[end-i];
    a[end-i] = a[start+i];
    a[start+i] = t;
  }
}

void rotate(size_t len, char a[len], size_t delta) {
  reverse(len, a, 0, delta-1);
  reverse(len, a, delta, len-1);
  reverse(len, a, 0, len-1);
}

int main(int argc, char* argv[argc+1]) {
  char a[] = "abcdefghijklmnopqrstuvwxyz";
  size_t len = (sizeof a / sizeof a[0]) - 1; // take account of '\0'
  size_t delta = 7;
  rotate(len, a, delta);
  printf("%s\n", a);
}
