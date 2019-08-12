#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct tm tm;
enum { sec_in_day = 86400 };

int diffdate(tm tm2, tm tm1) {
  time_t t2 = mktime(&tm2);
  time_t t1 = mktime(&tm1);
  double dt = difftime(t2, t1);
  return (int)dt/sec_in_day;
}

int main(int argc, char* argv[argc+1]) {
  tm t2 = {
    .tm_year = 119,
    .tm_mon = 3,
    .tm_mday = 3,
  };
  tm t1 = {
    .tm_year = 119,
    .tm_mon = 3,
    .tm_mday = 1,
  };
  int delta = diffdate(t2, t1);
  printf("%d\n", delta);
  return EXIT_SUCCESS;
}
