#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t myparent_pid;

    myparent_pid = getppid();
    printf("%u\n", myparent_pid);
    return (0);
}
