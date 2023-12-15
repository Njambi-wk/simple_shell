#include <stdio.h>
#include <string.h>

int main() {
    char command[100]; 
    while (1) 
{
        printf("$ ");
        fflush(stdout); 

        if (fgets(command, sizeof(command), stdin) == NULL) 
	{		
            printf("\nExiting the program. Goodbye!\n");
            break;
        }

        
        command[strcspn(command, "\n")] = '\0';

        printf("Entered command: %s\n", command);
    }
    return 0;
}
