#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum { num_digits_k = 1000000, max_number_n = 10000000 };

int main(int argc, char* argv[argc+1]) {
  srand(time(0));
  size_t byte_size = sizeof(char);
  size_t len = max_number_n / byte_size;
  char *bitmap = malloc(len * sizeof *bitmap);
  FILE* output_file = fopen("output.txt.4", "w");
  if (!output_file) return EXIT_FAILURE;

  size_t num_digits = 0;
  size_t x, index_of_array, index_in_bits;
  while (num_digits < num_digits_k) {
    x = rand() % max_number_n;
    index_of_array = x / byte_size;
    index_in_bits = x % byte_size;
    if (!(bitmap[index_of_array] & (1 << index_in_bits))) {
      fprintf(output_file, "%07lu\n", x);    
      bitmap[index_of_array] = bitmap[index_of_array] | (1 << index_in_bits);
      num_digits += 1;
    }
  }

  fclose(output_file);
  free(bitmap);

  return EXIT_SUCCESS;
}
