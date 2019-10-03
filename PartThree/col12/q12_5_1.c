#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[argc+1]) {
  printf("%d\n", INT_MAX == RAND_MAX);
  return EXIT_SUCCESS;
}
