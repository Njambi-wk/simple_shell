#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	char *cmd = NULL, *cmd_cpy = NULL;
	size_t n = 0;
	int i = 0;


	if (getline(&cmd, &n, stdin) == -1)
	{
		perror("getline");
		return (-1);
	}

	cmd_cpy = strdup(cmd);

	while (cmd[i])
	{
		if (cmd[i] == '\n')
			printf("\\n -- %ld characters", strlen(cmd));
		else
			printf("%c", cmd[i]);
		i++;
	}
	free(cmd);
	free(cmd_cpy);

	return (0);
}
