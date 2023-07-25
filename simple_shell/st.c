#include "simple_shell.h"


char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; ++i)
		s[i] = b;
	return (s);
}


char *_strcat(char *dest, char *src)
{
	int i = strlen(dest);
	int j = 0;

	while (src[j])
		dest[i++] = src[j++];
	dest[i] = src[j];
	return (dest);
}


int _strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}


int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}


int printerr(char *str)
{
	size_t i = strlen(str);

	write(STDERR_FILENO, str, i);
	return (i);
}

