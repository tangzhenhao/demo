#include "lib.h"

int main(int argc, char **args) {
  // Case 1: here is a simple case of NPD
  struct Node *p;
  p = create(0);
  destroy(&p);
  // NPD
  int y = p->x;

  // Case 2: the following code does not produce NPD
  struct Node *q;
  int c, killed = 0;
  q = create(1);
  if (c > 0) {
    destroy(&q);
    killed = 1;
  }

  // Case 2': the following code does produce NPD
  killed = 0;
  q = create(1);
  if (c > 0) {
    destroy(&q);
    killed = 1;
  }
  // no NDP
  int z = killed ? q->x : 0;

  // Case 3: the following code does produce double free
  struct Node *r;
  r = (struct Node *) malloc(sizeof(struct Node *));
  int i = rand();
  if (i > 10) {
    free(r);
  }
  if (i <= 11) {
    free(r);
  }

  // Case 3': the following code does not produce double free
  r = (struct Node *) malloc(sizeof(struct Node *));
  if (i > 10) {
    free(r);
  }
  if (i <= 10) {
    free(r);
  }

  // Case 5: the following code does produce div zero
  int a = 0;
  int b = 4 / maybe_zero(i);
  return 0;
}
