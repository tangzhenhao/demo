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

void dangerous_free(struct Node **ptr) {
  free(*ptr);
}

int maybe_zero(int i) {
  return i > 0 ? i : 0;
}

int f(struct Node *p, int x) {
  if (x > 0) {
    return p->x; 
  } else {
    return 0; 
  }
}
