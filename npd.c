#include <stdlib.h>
#include <stdio.h>

struct Node {
  int x;
  struct Node *next;
};

static struct Node* create(int value) {
  struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
  ret->x = value;
  return ret;
}

static void destroy(struct Node **ptr) {
  free(*ptr);
  *ptr = NULL;
}

void npd1() {
  // Case 1: here is a simple case of NPD
  struct Node *p;
  p = create(0);
  destroy(&p);
  // NPD
  int y = p->x;
}

void npd2() {
  // Case 2: here is a complex case of NPD
  struct Node *q;
  int c, killed = 0;
  scanf("%d", &c);
  q = create(1);
  if (c > 0) {
    destroy(&q);
    killed = 1;
  }
  // No NPD
  int z1 = killed ? 0 : q->x;
  // NPD
  int z2 = killed ? q->x : 0;
}
