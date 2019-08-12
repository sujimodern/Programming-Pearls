#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum { seg_length = 5, num_segs = 7, num_digits = 10 };

unsigned segments[num_digits][num_segs] = {
 /*0  1  2  3  4  5  6*/
  {1, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 0, 1},
  {1, 1, 1, 0, 1, 1, 0},
  {1, 1, 1, 0, 1, 0, 1},
  {0, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {1, 1, 1, 1, 0, 1, 1},
  {0, 0, 1, 0, 1, 0, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 0, 1},
};

void make7seg(size_t len, size_t segs[len], size_t num) {
  for (size_t i = 0; i < len; ++i) {
    size_t digit = (num / (size_t)pow(10, i)) % 10;
    for (size_t j = 0; j < num_segs; ++j) {
      unsigned val = segments[digit][j];
      segs[len-1-i] = (segs[len-1-i] | (val << j));
    }
  }
}

int main(int argc, char* argv[argc+1]) {
  size_t num = 123;
  size_t segs[seg_length] = { 0 };
  make7seg(seg_length, segs, num);
  for (size_t i = 0; i < seg_length; ++i) {
    printf("segs[%lu] = %lu\n", i, segs[i]);
    for (size_t j = 0; j < num_segs; ++j) {
      printf("%lu", (segs[i] >> j) & 1);
    }
    printf("\n");
  }
}
