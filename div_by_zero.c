#include <stdio.h>

int maybe_zero(int i) {
  return i > 0 ? i : 0;
}

void div_by_zero() {
  int i = 0;
  scanf("%d", &i);
  // Divide By Zero
  int b = 4 / maybe_zero(i);
}
