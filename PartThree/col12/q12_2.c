#include <stdio.h>
#include <stdlib.h>

enum { m = 20, n = 200, fix_value_to_reproduce = 1558341867 };

int bigrand() {
  return rand();
}

int main(int argc, char* argv[argc+1]) {
  size_t select, remaining;
  srand(fix_value_to_reproduce);

  select = m;
  remaining = n;
  for (size_t i = 0; i < n; ++i) {
    if ((bigrand() % remaining) < select) {
      printf("%lu ", i);
      --select;
    }
    --remaining;
  }
  printf("\n");

  return EXIT_SUCCESS;
}
