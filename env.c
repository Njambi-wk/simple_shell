#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void print_environment() 
{
    extern char **environ;
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {        
        printf("$$ ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';
        
        if (strcmp(command, "exit") == 0)
	{
            printf("Exit shell.\n");
            break;
        }
	else if (strcmp(command, "env") == 0)
	{
          
            print_environment();
        }
	else
	{
           
            printf("Command not recognized: %s\n", command);
        }
    }
    return 0;
}
