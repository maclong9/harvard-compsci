#include "../include/cs50.h"
#include <stdio.h>

void draw(int n) {
  // Print pyramid of height n - 1
  draw(n - 1);

  // Print one more row
  for (int i = 0; i < n; i++) {
    printf("#");
  }
  printf("\n");
}

int main(void) {
  int height = get_int("Height: ");
  draw(height);
}
