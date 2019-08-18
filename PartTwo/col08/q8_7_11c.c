#include <stdio.h>
#include <stdlib.h>

enum { num_intervals = 7 };

int main(int argc, char* argv[argc+1]) {
  size_t tolls[num_intervals] = {500, 300, 120, 600, 750, 250, 80};

  // FIXME: should i use +1 ?
  size_t* accumulated_tolls = calloc(num_intervals+1, sizeof *accumulated_tolls);
  size_t accumulated = 0;
  for (size_t i = 0; i < num_intervals+1; ++i) {
    accumulated_tolls[i] = accumulated;
    accumulated += tolls[i];
  }

  // for (size_t i = 0; i < num_intervals+1; ++i) {
  //   printf("%lu, ", accumulated_tolls[i]);
  // }
  // printf("\n");

  size_t begin = 1;
  size_t end = 6;
  printf("toll = %lu\n", accumulated_tolls[end+1] - accumulated_tolls[begin]);

  free(accumulated_tolls);
  return EXIT_SUCCESS;
}
