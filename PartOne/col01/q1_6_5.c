#include <stdio.h>
#include <stdlib.h>

enum { base = 10, max_number_n = 10000000 };

int main(int argc, char* argv[argc+1]) {
  size_t half_number_h = (max_number_n + 1) / 2;
  size_t byte = sizeof(char);
  size_t len = half_number_h / byte;

  char *line = 0;
  size_t line_size = 0;
  for (size_t round = 0; round < 2; ++round) {
    char *bitmap = calloc(len, sizeof *bitmap);
    size_t min = (round) ? half_number_h : 0;
    size_t max = (round) ? max_number_n : half_number_h;
    size_t offset = (round) ? half_number_h : 0;
    FILE* input_file = fopen("input.txt", "r");
    if (!input_file) return EXIT_FAILURE;
    while (!feof(input_file)) {
      getline(&line, &line_size, input_file);
      size_t n = strtol(line, 0, base);
      if (min <= n && n < max) {
        size_t index_of_array = (n-offset) / byte;
        size_t index_of_bits = (n-offset) % byte;
        bitmap[index_of_array] = bitmap[index_of_array] | (1 << index_of_bits);
      }
    }
    fclose(input_file);

    char mode[2][2] = { "w", "a" };
    FILE* output_file = fopen("output.txt.5", mode[round]);
    if (!output_file) return EXIT_FAILURE;
    for (size_t i = 0; i < half_number_h; ++i) {
      size_t index_of_array = i / byte;
      size_t index_of_bits = i % byte;
      if (bitmap[index_of_array] & (1 << index_of_bits)) {
        fprintf(output_file, "%07lu\n", i+offset);
      }
    }
    fclose(output_file);
    free(bitmap);
  }

  return EXIT_SUCCESS;
}
