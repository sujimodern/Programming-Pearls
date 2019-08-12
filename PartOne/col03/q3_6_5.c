#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { num_patterns = 23 };


char* patterns[num_patterns] = {
  "etic", "alistie", "ptie", "lytic", "otic", "antie", "ntie", "ctic",
  "atic", "hnic", "nic", "mic", "llic", "blic", "clic", "lic", "hic",
  "fic", "dic", "bic", "aic", "mac", "iac"
};

char* patterns_w_hyphen[num_patterns] = {
  "et-ic", "al-is-tie", "p-tie", "-lyt-ic", "ot-ic", "an-tie", "n-tie", "c-tic",
  "at-ic", "h-nic", "n-ic", "m-ic", "l-lic", "b-lic", "-clic", "l-ic", "h-ic",
  "f-ic", "d-ic", "-bic", "a-ic", "-mac", "i-ac"
};

size_t num_hyphens[num_patterns] = {
  1, 2, 1, 2, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1
};

size_t delimit(size_t const len, char const word[len], char** delimited) {
  for (size_t i = 0; i < num_patterns; ++i) {
    char* pattern = patterns[i];
    char* matched = strstr(word, pattern);
    if (matched) {
      size_t count = matched - word;
      size_t hypens = num_hyphens[i];
      *delimited = calloc(len + hypens, sizeof *delimited);
      strcpy(*delimited, word);
      strcpy(*delimited + count, patterns_w_hyphen[i]);
      return len + hypens;
      break;
    }
  } 
  return 0;
}

int main(int argc, char* argv[argc+1]) {
  char word[] = "ethnic";
  char* delimited = 0;
  size_t len = delimit(sizeof word / sizeof word[0], word, &delimited);
  printf("%s\n", delimited);
  printf("%lu\n", len);
  free(delimited);
  return EXIT_SUCCESS;
}
