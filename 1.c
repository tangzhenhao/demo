#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* get_next(struct Node* node) {
  srand((unsigned)time(NULL));
  int rand_num = rand() % 10;
  return rand_num % 2 == 0 ? node->next : NULL;
}

void npd4() {
  struct Node a;
  struct Node b;
  struct Node c;
  struct Node* p;
  a.data = 1;
  a.next = &b;
  b.data = 2;
  b.next = &c;
  c.data = 3;
  c.next = NULL;

  for (p = &a; p != NULL; p = get_next(p)) {
    // FP: NPD
    // fixed
    p->data = 888;
  }

}
