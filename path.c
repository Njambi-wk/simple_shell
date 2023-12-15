#include "shell.h"
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_PATH_LENGTH 100
void display_prompt(void)
{
    printf(":) ");
    fflush(stdout);
}

void read_command(char *command, size_t size)
{
    if (fgets(command, size, stdin) == NULL)
    {
        printf("\nExit the shell. bye!\n");
        exit(0);
    }

    command[strcspn(command, "\n")] = '\0';
}

void execute_command(char *command, char *path[])
 {
    char full_path[MAX_PATH_LENGTH];
    int i;

    for (i = 0; path[i] != NULL; i++)
    {
	     size_t path_len = strlen(path[i]);
	     char last_char = path[i][path_len - 1];
	     
	if (last_char == '/')
	{
	snprintf(full_path, sizeof(full_path), "%s%s", path[i], command);
	}
	else
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path[i], command);
	}
	printf("Execute: %s\n", full_path);

        if (access(full_path, F_OK) == 0)
	{
            pid_t pid = fork();

            if (pid == -1)
	    {
                perror("fork");
            }
	    else if (pid == 0)
	    {

                execlp(full_path, command, (char *)NULL);

                perror("exec");
                exit(EXIT_FAILURE);
            }
	    else
	    {
                wait(NULL);
                return;
            }
        }
    }


    printf("%s: command not found\n", command);
}

int main(void)
{
    char command[MAX_INPUT_LENGTH];
    char *path[] = {getenv("PATH"), NULL};

    while (1)
    {
        display_prompt();
        read_command(command, sizeof(command));
        execute_command(command, path);
    }

    return 0;
}
