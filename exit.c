#include "shell.h"


char *_strncpy(char *dest, char *src, int i)
{
	int n;
	char *s = dest;
	int m = 0;

	while (src[m] != '\0' && m < m - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < i)
	{
		n = m;
		while (n < i)
		{
			dest[n] = '\0';
			n++;
		}
	}
	return (s);
}

char *_strncat(char *dest, char *src, int i)
{
	int m = 0;
        int n = 0;
	char *s = dest;

	while (dest[m] != '\0')
		m++;
	while (src[n] != '\0' && n < i)
	{
		dest[m] = src[n];
		m++;
		n++;
	}
	if (n < i)
		dest[m] = '\0';
	return (s);
}

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
