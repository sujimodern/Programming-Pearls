#include <stdio.h>
#include <stdlib.h>

int compare_unsigned_long(void const* a, void const* b) {
  size_t const* A = a;
  size_t const* B = b;
  if (*A < *B) return -1;
  else if (*A > *B) return 1;
  else return 0;
}

void qsort_unsigned_long(size_t nmeb, unsigned long base[nmeb]) {
  qsort(base, nmeb, sizeof base[0], compare_unsigned_long);
}

int main(int argc, char* argv[argc+1]) {
  FILE* input_file = fopen("input.txt", "r");
  if (!input_file) return EXIT_FAILURE;
  size_t num_lines = 0;
  while (!feof(input_file)) {
    if (fgetc(input_file) == '\n')
      num_lines += 1;
  }
  fclose(input_file);

  size_t* numbers = malloc(num_lines * sizeof *numbers);

  input_file = fopen("input.txt", "r");
  if (!input_file) return EXIT_FAILURE;
  char* buffer;
  size_t buffer_size = 9;
  size_t digits= 0;
  size_t index = 0;
  while (!feof(input_file)) {
    getline(&buffer, &buffer_size, input_file);
    digits = strtol(buffer, 0, 10);
    numbers[index] = digits;
    index += 1;
  }
  fclose(input_file);
  qsort_unsigned_long(num_lines, numbers);

  FILE* output_file = fopen("output.txt.1", "w");
  if (!output_file) return EXIT_FAILURE;
  for (size_t i = 0; i < num_lines; ++i) {
    fprintf(output_file, "%07lu\n", numbers[i]);
  }
  fclose(output_file);

  return EXIT_SUCCESS;
}
