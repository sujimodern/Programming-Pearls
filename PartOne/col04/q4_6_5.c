#include <stdlib.h>
#include <stdio.h>

void collatz(size_t n) {
  while (n != 1) {
    if (n%2 == 0) {
      n = n/2;
    } else {
      n = 3*n+1;
    }
  }
}

int main(int argc, char* argv[argc+1]) {
  for (size_t i = 1; i <= 100000; ++i) {
    collatz(i);
  }
  return EXIT_SUCCESS;
}
