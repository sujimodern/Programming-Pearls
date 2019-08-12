#include <stdio.h>
#include <stdlib.h>

enum { byte = 8, base = 10, max_number = 10000000 };

int main(int argc, char* argv[argc+1]) {
  size_t len = max_number / sizeof(char);
  char *bitmap = malloc(len * sizeof *bitmap);

  FILE* input_file = fopen("input.txt", "r");
  if (!input_file) return EXIT_FAILURE;

  char *line = 0;
  size_t line_size = 0;
  while (!feof(input_file)) {
    getline(&line, &line_size, input_file);
    size_t n = strtol(line, 0, base);

    size_t index_of_array = n / byte;
    size_t index_of_bits = n % byte;
    bitmap[index_of_array] = bitmap[index_of_array] | (1 << index_of_bits);
  }
  fclose(input_file);

  FILE* output_file = fopen("output.txt.2", "w");
  if (!output_file) return EXIT_FAILURE;
  for (size_t i = 0; i < max_number; ++i) {
    size_t index_of_array = i / byte;
    size_t index_of_bits = i % byte;
    if (bitmap[index_of_array] & (1 << index_of_bits)) {
      fprintf(output_file, "%07lu\n", i);
    }
  }
  fclose(output_file);

  return EXIT_SUCCESS;
}
