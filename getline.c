#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

char *custom_getline() {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0;
    static ssize_t bytes_read = 0;

    
    if (buffer_index == 0 || buffer_index == (size_t)bytes_read)
    {
        bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
   
        if (bytes_read <= 0)
	{
            return NULL;
        }
        buffer_index = 0;
    }

    size_t ln_length = 0;

    while (buffer_index < (size_t)bytes_read && buffer[buffer_index] != '\n')
    {
        buffer_index++;
        ln_length++;
    }

    char *ln = malloc(ln_length + 1);

    if (ln == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    
    size_t i;

    for (i = 0; i < ln_length; i++)
    {
        ln[i] = buffer[buffer_index - ln_length + i];
    }

    ln[ln_length] = '\0';

    if (buffer_index < (size_t)bytes_read)
    {
        buffer_index++;
    }
    return ln;
}

int main()
{
    char *ln;

    while ((ln = custom_getline()) != NULL)
    {
        printf("You entered: %s\n", ln);
        free(ln);
    }

    return 0;
}
