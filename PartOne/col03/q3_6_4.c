#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tm tm;
enum { sec_in_day = 86400 };

int diffdays(tm tm2, tm tm1) {
  time_t t2 = mktime(&tm2);
  time_t t1 = mktime(&tm1);
  double delta = difftime(t2, t1);
  return (int)delta / sec_in_day;
}

int main(int argc, char* argv[argc+1]) {
  tm tm2 = {
    .tm_year = 1020,
    .tm_mon = 7,
    .tm_mday = 3,
  };
  tm tm1 = {
    .tm_year = 1019,
    .tm_mon = 7,
    .tm_mday = 1,
  };
  int days = diffdays(tm2, tm1);
  printf("%d\n", days);

  return EXIT_SUCCESS;
}
