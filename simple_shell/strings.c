#include "simple_shell.h"


char *_strtok(char *buffer, const char *delim)
{
	static char *sp;
	char *p;
	int letter = 0;
	int i = 0;
	int stop = 0;

	if (buffer)
		sp = buffer;
	p = sp;
	while (sp && *sp)
	{
		while (delim[i])
		{
			if (*sp == delim[i] && letter == 0)
			{
				++p;
				++sp;
				i = 0;
				continue;
			}
			if (*sp == delim[i] && letter == 1)
			{
				*sp++ = '\0';
				stop = 1;
				i = 0;
				break;
			}
			++i;
		}
		if (stop)
			break;
		letter = 1;
		i = 0;
		++sp;
	}
	if (!p || *p == '\0')
		return (NULL);
	return (p);
}



int _putchar(int c)
{
	static int i;
	static char buf[BUFSIZ];

	if (c == F_FLUSH || i >= BUFSIZ)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != F_FLUSH)
		buf[i++] = c;
	return (1);
}


int _strlen(char *str)
{
	int i = 0;

	while (*(str + i))
		++i;
	return (i);
}


char **tokarr(char *buffer)
{
	char *token;
	char **arr;
	char *pure = buffer;
	unsigned int i = 0, count = 0, word = 0, t = 0;

	while (pure && pure[i])
	{
		if (!word && pure[i] != ' ')
		{
			word = 1;
			++count;
		}
		else if (word && pure[i] == ' ')
			word = 0;
		i++;
	}
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	token = _strtok(buffer, " \t\n");
	while (token)
	{
		arr[t] = token;
		t++;
		token = _strtok(NULL, " \t\n");
	}
	arr[t] = NULL;
	return (arr);
}


int _eputs(char *str)
{
	size_t i = _strlen(str);

	write(1, str, i);
	return (i);
}

