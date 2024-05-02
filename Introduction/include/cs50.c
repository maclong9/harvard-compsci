#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(char *text) {
  int value;
  printf("%s: ", text);
  scanf("%i", &value);

  while (value < 0) {
    printf("%s: ", text);
    scanf("%i", &value);
  }

  return value;
}

void request_char(char *text, char *value) {
  printf("%s", text);
  scanf("%c", value);
}

char get_char(char *text) {
  char value;

  request_char(text, &value);

  while (strlen(&value) != 1) {
    request_char(text, &value);
  }

  return value;
}

void request_string(char *text, char *value) {
  printf("%s", text);
  scanf("%s", value);
}

char *get_string(char *text) {
	char *value = malloc(51 * sizeof(char));

	if (value == NULL) {
		fprintf(stderr, "Memory Allocation Failed.");
		exit(1);
	}

	do {
		printf("%s", text);
		fgets(value, 51, stdin);
		if (value[strlen(value) - 1] == '\n') {
			value[strlen(value) - 1] = '\0';
		}
	} while (strlen(value) == 0);

	return value;
}
