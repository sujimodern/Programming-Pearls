#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int dist(int a, int b) {
  return abs(a - b);
}

int main(int argc, char* argv[argc+1]) {
  int x[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
  size_t n = sizeof x / sizeof x[0];
  int target = 58;

  int delta = INT_MAX;
  int sofar = 0;
  int sumendinghere = 0;
  for (size_t i = 0; i < n; ++i) {
    sumendinghere = max(sumendinghere + x[i], 0);
    printf("%d\n", sumendinghere);
    if (dist(target, sumendinghere) < delta) {
      delta = dist(target, sumendinghere);
      sofar = sumendinghere;
    }
  }
  printf("min = %d\n", sofar);

  return EXIT_SUCCESS;
}
