#include "main.h"
/**
 * line_read - check code
 * Return: char
 */
char *line_read(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &length, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
