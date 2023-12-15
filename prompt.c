#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	size_t n = 10;
	char *buffer;

	buffer = malloc(sizeof(char) * 10);
	printf("$ ");
	getline(&buffer, &n, stdin);
	printf("write name: %s", buffer);
	printf("buffer size: %ld\n", n);

	free(buffer);
	return (0);
}
