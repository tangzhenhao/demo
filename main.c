#include "lib.h"

int main(int argc, char **args) {
  // Case 1: here is a simple case of NPD
  struct Node *p;
  p = create(0);
  destroy(&p);
  // NPD
  int y = p->x;

  // Case 2: the following code does produce NPD
  struct Node *q;
  int c, killed = 0;
  scanf("%d", &c);
  q = create(1);
  if (c > 0) {
    destroy(&q);
    killed = 1;
  }
  // NPD
  int z = killed ? q->x : 0;

  // Case 2': the following code does not produce NPD
  killed = 0;
  scanf("%d", &c);
  q = create(1);
  if (c > 0) {
    destroy(&q);
    killed = 1;
  }
  // no NPD
  int z = killed ? 0 : q->x;

  // Case 3: the following code does produce double free
  struct Node *r;
  r = create(1);
  int i = 0;
  scanf("%d", &i);
  if (i > 10) {
    free(r);
  }
  if (i <= 11) {
    free(r);
  }

  // Case 3': the following code does not produce double free
  r = create(1);
  i = 0;
  scanf("%d", &i);
  if (i > 10) {
    free(r);
  }
  if (i <= 10) {
    free(r);
  }

  // Case 4: the following code does produce div zero
  i = 0;
  scanf("%d", &i);
  int b = 4 / maybe_zero(i);
  return 0;
  
  // Case 5: the following code does not produce NPD
  int x;
  scanf("%d", &x);
  int *p = NULL;
  if (x >= 0) {
     p = malloc(sizeof(int));
  }
  return f(p, x);
}
