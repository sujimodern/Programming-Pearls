#include <stdlib.h>
#include <stdio.h>

enum { height = 200, width = 200, population = 2000, reproducible_fix_value = 1558189629 };

void generatepoint(size_t width, size_t height, short map[width][height]) {
  srand(reproducible_fix_value);
  size_t x, y;
  for (size_t i = 0; i < population; ++i) {
    x = rand() % width;
    y = rand() % height;
    map[x][y] = i;
  }
}

int main(int argc, char* argv[argc+1]) {
  short map[width][height] = { { 0 } };
  generatepoint(width, height, map);
  
  return EXIT_SUCCESS;
}
