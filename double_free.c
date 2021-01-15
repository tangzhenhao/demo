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

void free_later(struct Node **ptr) {
  free(*ptr);
}

void double_free() {
  struct Node *r;
  r = create(1);
  int i = 0;
  scanf("%d", &i);
  if (i > 10) {
    free(r);
  }
  // Double Free
  free_later(&r);
}
