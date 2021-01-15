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
  // no NPD
  z = killed ? 0 : q->x;

  // Case 3: the following code does produce double free
  struct Node *r;
  r = create(1);
  int i = 0;
  scanf("%d", &i);
  if (i > 10) {
    free(r);
  }
  dangerous_free(&r);

  // Case 4: the following code does produce div zero
  i = 0;
  scanf("%d", &i);
  int b = 4 / maybe_zero(i);
  
  // Case 5: the following code does not produce NPD
  int x;
  scanf("%d", &x);
  p = NULL;
  if (x >= 0) {
     p = create(1);
  }
  
  if (x >= 0) {
    return p->x; 
  } else {
    return 0; 
  }
}
