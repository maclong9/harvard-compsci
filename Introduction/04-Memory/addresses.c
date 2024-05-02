#include <stdio.h>

int main(void) {
	int n = 50;
	int *p = &n;

	// Prints the address of n which is stored in p
	printf("%p\n", p);

	// Go to memory address and print value
	printf("%i\n", *p);
}
