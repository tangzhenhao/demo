#ifndef __LIB_H__
#define __LIB_H__

#include <stdlib.h>
#include <stdio.h>

struct Node {
  int x;
  struct Node *next;
};

struct Node* create(int value);

void destroy(struct Node **ptr);

int maybe_zero(int i);

int f(int *p, int x);

#endif
