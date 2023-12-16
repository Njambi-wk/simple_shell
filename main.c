#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int arg_count, char **arg_val)
{
    info_t information_array[] = { INFO_INIT };
    int file_descriptor = 2;

    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor));

    if (arg_count == 2)
    {
        file_descriptor = open(arg_val[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _puts(arg_val[0]);
                _puts(": 0: Can't open ");
                _puts(arg_val[1]);
                _putchar('\n');
                _putchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        information_array[0].readfd = file_descriptor;
    }
    populate_env_list(information_array);
    read_history(information_array);
    hsh(information_array, arg_val);
    return (EXIT_SUCCESS);
}
