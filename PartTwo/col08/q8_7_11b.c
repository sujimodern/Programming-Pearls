#include <stdio.h>
#include <stdlib.h>

enum { num_intervals = 7 };

int main(int argc, char* argv[argc+1]) {
  size_t tolls[num_intervals] = {500, 300, 120, 600, 750, 250, 80};

  size_t (*toll_table)[num_intervals] = calloc(num_intervals, sizeof *toll_table);
  size_t accumulated;
  for (size_t from = 0; from < num_intervals; ++from) {
    accumulated = 0;
    for (size_t to = 0; to < num_intervals; ++to) {
      if (from <= to) {
        accumulated += tolls[to];
        toll_table[from][to] = accumulated;
      }
    }
  }

  size_t begin = 1;
  size_t end = 6;
  printf("toll = %lu\n", toll_table[begin][end]);

  free(toll_table);
  return EXIT_SUCCESS;
}
