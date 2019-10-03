#include <stdio.h>
#include <stdlib.h>

enum heap_constant { root = 1 };

void swap(int* a, int* b) {
  int* t;
  t = b;
  b = a;
  a = t;
}

typedef struct heap heap;
struct heap {
  int* x;
  size_t size;
  size_t maxsize;
};

heap* heap_new(size_t maxsize) {
  int* x = calloc(maxsize, sizeof *x);
  heap* h = malloc(sizeof *h);
  *h = (heap){
    .x = x,
    .size = 0,
    .maxsize = maxsize,
  };
  return h;
}

void heap_delete(heap* h) {
  free(h->x);
  free(h);
}

void heap_shiftup(size_t len, int x[len], size_t n) {
  size_t i, p;
  i = n;
  for (;;) {
    if (i == root) { break; }
    p = i/2;
    if (x[p] <= x[i]) { break; }
    swap(&x[p], &x[i]);
    i = p;
  }
}

void heap_shiftdown(size_t len, int x[len], size_t n) {
  size_t i, c;
  i = root;
  for (;;) {
    c = 2*i;
    if (c > n) { break; }
    if ((c+1 <= n) && (x[c+1] < x[c])) {
      c += 1;
    }
    if (x[i] <= x[c]) { break; }
    swap(&x[c], &x[i]);
    i = c;
  }
}

void heap_insert(heap* h, int t) {
  size_t size = h->size;
  size_t maxsize = h->maxsize;
  if (size < maxsize) {
    h->x[size] = t;
    heap_shiftup(maxsize, h->x, size);
    h->size += 1;
  }
}

void heap_print(heap* h) {
  for (size_t i = 0; i < h->size; ++i) {
    printf("%d ", h->x[i]);
  }
  printf("\n");
}

typedef struct priqueue priqueue;
struct priqueue {
  heap* h;
};

priqueue* priqueue_new(size_t maxsize) {
  heap* h = heap_new(maxsize);
  priqueue* p = malloc(sizeof *p);
  *p = (priqueue){
    .h = h,
  };
  return p;
}

void priqueue_delete(priqueue* p) {
  heap_delete(p->h);
  free(p);
}

void priqueue_insert(priqueue* p, int t) {
  heap_insert(p->h, t);
}

void priqueue_print(priqueue* p) {
  heap_print(p->h);
}

int main(int argc, char* argv[argc+1]) {
  size_t mx = 100;
  int x[14] = {0, 12, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19, 13};
  return 0;
}
