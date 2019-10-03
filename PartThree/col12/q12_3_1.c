#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum { bits = 8, m = 20, n = 200, fix_value_to_reproduce = 1558341867 };

int* initialize(int* S, size_t size) {
  size_t num = (size_t)ceil((double)size / (bits * (sizeof(int))));
  return calloc(num, sizeof *S);
}

int in(int* S, int val) {
  size_t byte_idx = val / (bits * (sizeof(int)));
  size_t bit_idx = val % (bits * (sizeof(int)));
  return S[byte_idx] & (1 << bit_idx);
}

void add(int* S, int val) {
  size_t byte_idx = val / (bits * (sizeof(int)));
  size_t bit_idx = val % (bits * (sizeof(int)));
  S[byte_idx] |= (1 << bit_idx);
}

void printset(int* S, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (in(S, i)) {
      printf("%lu ", i);
    }
  }
  printf("\n");
}

int bigrand() {
  return rand();
}

int main(int argc, char* argv[argc+1]) {
  size_t size = 0;
  int* S = 0;
  srand(fix_value_to_reproduce);
  S = initialize(S, n);

  int t;
  while (size < m) {
    t = bigrand() % n; 
    if (!in(S, t)) {
      add(S, t);
      ++size;
    }
  }
  printset(S, n);

  free(S);
  
  return EXIT_SUCCESS;
}
