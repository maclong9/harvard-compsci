#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char s[20];
	printf("s: ");
	scanf("%s", s);

	char *t = malloc(strlen(s + 1));
	for(int i = 0, n = strlen(s); i <= n; i++) {
		t[i] = s[i];
	}

	if(strlen(t) > 0) {
		t[0] = toupper(t[0]);
	}

	printf("%s\n", s);
	printf("%s\n", t);
}

