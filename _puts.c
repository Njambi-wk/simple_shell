#include <unistd.h>
#include <stdio.h>

/**
 *  * _putchar - writes the character c to stdout
 *   * @c: The character to print
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 *       */
void _puts(const char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}
int _putchar(char ch)
{
	putchar(ch);
	return (0);
}
