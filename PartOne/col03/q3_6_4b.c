#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct tm tm;
enum { sec_in_day = 86400 };

int getweekday(tm t) {
  tm o = {
    .tm_year = -1899,
    .tm_mon = 0,
    .tm_mday = 1,
  };
  time_t t0 = mktime(&o);
  time_t t1 = mktime(&t);
  double d = difftime(t1, t0);
  printf("d = %g, i = %d\n", d, (int)d/sec_in_day);
  return ((int)d / sec_in_day) % 7; // It's monday on Jan 1st in AD 1.
}

int main(int argc, char* argv[argc+1]) {
  tm t = {
    .tm_year = 119,
    .tm_mon = 3,
    .tm_mday = 4,
  };
  int weekday = getweekday(t);
  printf("%d\n", weekday);
  return EXIT_SUCCESS;
}
