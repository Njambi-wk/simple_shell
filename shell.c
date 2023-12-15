#include "shell.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void display_promt(void)
{
	printf("$$ ");
	fflush(stdout);
}

void read_command(char *command, size_t size)
{
	 if (fgets(command, size, stdin) == NULL)
{
        printf("\nExit. Goodbye!\n");
        exit(0);
    }

    command[strcspn(command, "\n")] = '\0';
    }

void execute_command(const char *command)
{
	printf("Execute command: %s\n", command);
}
