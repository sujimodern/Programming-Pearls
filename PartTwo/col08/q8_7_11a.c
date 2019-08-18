#include <stdio.h>
#include <stdlib.h>

enum { num_tolls = 7 };

int main(int argc, char* argv[argc+1]) {
  size_t tolls[num_tolls] = {500, 300, 120, 600, 750, 250, 80};
  size_t begin = 1;
  size_t end = 6;
  size_t total = 0;
  for (size_t i = 0; i < num_tolls; ++i) {
    if (begin <= i && i <= end) { 
      total += tolls[i];
    }
  }
  printf("toll = %lu\n", total);
  return EXIT_SUCCESS;
}
