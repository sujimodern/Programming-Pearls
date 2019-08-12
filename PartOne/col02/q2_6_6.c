#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum { num_chars = 3, string_len = 4, num_keys = 10, ascii_code_of_zero = 48 };

char keypad[num_keys][string_len] = {
  "___", "___", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"
};

void printname(size_t len, char digits[len], size_t indicator[len]) {
  char c;
  long n;
  for (size_t i = 0; i< len; ++i) {
    c = digits[i];
    if (c == '*') {
      printf("%c", c);
    } else {
      n = c - ascii_code_of_zero;
      printf("%c", keypad[n][indicator[i]]);
    }
  }
  printf("\n");
}

void toname(size_t len, char digits[len]) {
  char c;
  size_t n;
  for (size_t i = 0; i < pow(num_chars, len); ++i) {
    for (size_t j = 0; j < len; ++j) {
      c = digits[j];
      if (c == '*') {
        printf("%c", c);
      } else {
        n = c - ascii_code_of_zero;
        printf("%c", keypad[n][(i >> (int)pow(num_chars, j)) % num_chars]);
      }
    }
    printf("\n");
  }
  /*
  00000
  00001
  00002
  00010
  00011
  00012
  00020
  00021
  00022
  */
}

int main(int argc, char* argv[argc+1]) {
  char digits[] = "5375*6*";
  size_t len = sizeof digits / sizeof digits[0] - 1;
  toname(len, digits);
  return EXIT_SUCCESS;
}
