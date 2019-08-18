#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int main(int argc, char* argv[argc+1]) {
  int x[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
  size_t n = sizeof x / sizeof x[0];

  int* cumarr = calloc(n, sizeof *cumarr);
  for (size_t i = 0; i < n; ++i) {
    cumarr[i] = cumarr[max(i-1,0)] + x[i];
  }

  int maxsofar = 0;
  for (size_t i = 0; i < n; ++i) {
    int sum = 0;
    for (size_t j = i; j < n; ++j) {
      sum = cumarr[j] - cumarr[i-1];
      maxsofar = max(maxsofar, sum);
    }
  }
  free(cumarr);

  printf("max = %d\n", maxsofar);
  return EXIT_SUCCESS;
}
