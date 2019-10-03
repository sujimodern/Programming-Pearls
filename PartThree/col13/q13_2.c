#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum { room_for_sentinel = 1, fix_value_to_reproduce = 1566296018 };

typedef struct node node;
struct node {
  int val;
  node* next;
};

typedef struct intset intset;
struct intset {
  node* head;
  node* sentinel;
  size_t maxelements;
  size_t maxval;
  size_t size;
};

intset* intset_new(size_t maxelements, size_t maxval) {
  intset* is = malloc(sizeof *is);
  *is = (intset){
    .head = malloc(sizeof(node)),
    .maxelements = maxelements,
    .maxval = maxval,
    .size = 0,
  };
  *(is->head) = (node){
    .val = maxval,
    .next = 0,
  };
  is->sentinel = is->head;
  return is;
}

void intset_delete(intset* is) {
  node* current = is->head;
  node* next;
  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
  free(is);
}

size_t intset_size(intset* is) {
  return is->size;
}

node* intset_rinsert(intset* is, node* n, int t) {
  if (n->val < t) {
    n->next = intset_rinsert(is, n->next, t);
  } else if (n->val > t) {
    node* temp = n;
    n = malloc(sizeof(node));
    *n = (node){
      .val = t,
      .next = temp,
    };
    is->size += 1;
  }
  return n;
}

void intset_insert(intset* is, int t) {
  is->head = intset_rinsert(is, is->head, t);
}

void intset_report(intset* is, size_t len, int v[len]) {
  if (is->size > len) { return; }
  node* n = is->head;
  for (size_t i = 0; n; n = n->next) {
    v[i] = n->val;
    i += 1;
  }
}

int main(int argc, char* argv[argc+1]) {
  size_t maxelem = 50000;
  size_t maxval = 100000;
  int* v = malloc(maxelem * sizeof *v);
  intset* is = intset_new(maxelem, maxval);

  srand(fix_value_to_reproduce);
  for (size_t i = 0; i < maxelem; ++i) {
    int r = rand() % maxval;
    intset_insert(is, r);
  }

  intset_report(is, maxelem, v);
  for (size_t i = 0; i < is->size; ++i) {
    printf("%d\n", v[i]);
  }

  intset_delete(is);
  return EXIT_SUCCESS;
}
