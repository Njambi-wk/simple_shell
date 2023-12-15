#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
 {
        printf("Simple_Shell > ");

        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
	{
            printf("Exit shell:\n");
            break;
        }
	else 
	{   
            system(command);
        }
    }
    return 0;
}
