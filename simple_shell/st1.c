#include "simple_shell.h"





char *comments(char *str)
{
	size_t i;
	char *s = NULL;

	i = 0;
	s = str;
	while (str && str[i])
	{
		if (str[0] == '#' || (str[i] == '#' && str[i - 1] == ' '))
		{
			*s = '\0';
		}
		s++;
		i++;
	}
	return (str);
}



char *_strchr(char *s, char c)
{
	while (*s && *s != c)
	{
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

