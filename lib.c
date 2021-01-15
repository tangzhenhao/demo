#include "lib.h"

struct Node;

struct Node* create(int value) {
  struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
  ret->x = value;
  return ret;
}

void destroy(struct Node **ptr) {
  free(*ptr);
  *ptr = NULL;
}

int maybe_zero(int i) {
  return i > 0 ? i : 0;
}
