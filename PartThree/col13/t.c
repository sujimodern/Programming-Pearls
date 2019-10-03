#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
  int val;
  node* next;
};

int main(int argc, char* argv[argc+1]) {
  node* head = malloc(sizeof(node));
  printf("%p\n", head);
  node* node1 = malloc(sizeof(node));
  printf("%p\n", node1);
  node* node2 = malloc(sizeof(node));
  printf("%p\n", node2);
  *head = (node){
    .val = 7,
    .next = node1,
  };
  *node1 = (node){
    .val = 23,
    .next = node2,
  };
  *node2 = (node){
    .val = 13,
    .next = 0,
  };

  for (node* p = head; p; p = p->next) {
    printf("val = %d\n", p->val);
  }

  node* current = head;
  node* next;
  while (current != NULL) {
    next = current->next;
    printf("current = %p\n", current);
    printf("next = %p\n", next);
    free(current);
    current = next;
  }
  return EXIT_SUCCESS;
}
