#include <stdio.h>
#include <stdlib.h>

enum { room_for_sentinel = 1 };

typedef struct intset intset;
struct intset {
  int* _set;
  size_t maxelements;
  size_t maxval;
  size_t size;
};

intset* intset_new(size_t maxelements, size_t maxval) {
  intset* is = malloc(sizeof *is);
  *is = (intset){
    ._set = malloc((maxelements + room_for_sentinel) * sizeof(int)),
    .maxelements = maxelements,
    .maxval = maxval,
    .size = 0,
  };
  is->_set[0] = maxval;
  return is;
}

void intset_delete(intset is[static 1]) {
  free(is[0]._set);
  free(is);
}

size_t intset_size(intset is[static 1]) {
  return is[0].size;
}

void intset_insert(intset is[static 1], int t) {
  int i, j;
  for (i = 0; is[0]._set[i] < t; ++i);
  if (is[0]._set[i] == t) { return; }
  for (j = is[0].size; j >= i; --j) {
    is[0]._set[j+1] = is[0]._set[j];
  }
  is[0]._set[i] = t;
  is[0].size += 1;
}

void intset_report(intset is[static 1], size_t len, int v[len]) {
  if (is[0].size > len) { return; }
  for (size_t i = 0; i < is[0].size; ++i) {
    v[i] = is[0]._set[i];
  }
}

int main(int argc, char* argv[argc+1]) {
  size_t maxelem = 5;
  size_t maxval = 100;
  int* v = malloc(maxelem * sizeof *v);
  intset* is = intset_new(maxelem, maxval);

  intset_insert(is, 7);
  intset_insert(is, 3);
  intset_insert(is, 15);
  intset_insert(is, 15);
  intset_insert(is, 15);
  intset_insert(is, 8);
  intset_report(is, maxelem, v);

  for (size_t i = 0; i < intset_size(is); ++i) {
    printf("%lu: %d\n", i, v[i]);
  }

  intset_delete(is);
  return EXIT_SUCCESS;
}
