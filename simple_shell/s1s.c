#include "simple_shell.h"


char *convert(unsigned int num, int base)
{
	static const char rep[] = "0123456789ABCDEF";
	static char buffer[11];
	char *ptr;

	ptr = &buffer[10];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}


void signal_hand(int signum __attribute__((unused)))
{
	puts("\n");
	write(STDERR_FILENO, "$ ", 2);
	fflush(stdout);
}

