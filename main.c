#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * @arg_count: argument count
 * @arg_val: argument values
 * Return: 0 on success, 1 otherwise
 */

int main(int arg_count, char **arg_val)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (arg_count == 2)
	{
		fd = open(arg_val[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(arg_val[0]);
				_eputs(": 0: Can't open ");
				_eputs(arg_val[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, arg_val);
	return (EXIT_SUCCESS);
}
