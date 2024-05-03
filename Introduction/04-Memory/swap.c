#include <stdio.h>

void old_swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
  int x = 1;
  int y = 2;
  printf("x is %i, y is %i\n", x, y);
  swap(&x, &y);
  printf("x is %i, y is %i", x, y);
}
