#include <time.h>
#include <stdio.h>
#include <stdlib.h>

enum { buffer_size = 9, rareness = 10, max_number_n = 10000000 };

int main(int argc, char* argv[argc]) {
  size_t* numbers = malloc(max_number_n * sizeof *numbers);
  srand(time(0));

  for (size_t i = 0; i < max_number_n; ++i) {
    numbers[i] = i;
  }

  size_t t, j;
  for (size_t i = 0; i < max_number_n; ++i) {
    j = rand() % max_number_n; 
    t = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = t;
  }

  char buffer[buffer_size] = { 0 };
  FILE* file = fopen("input.txt", "w");
  for (size_t i = 0; i < max_number_n; ++i) {
    if (!(rand() % rareness)) {
      sprintf(buffer, "%07lu\n", numbers[i]);
      fputs(buffer, file);
    }
  }
  fclose(file);

  free(numbers);

  return EXIT_SUCCESS;
}
