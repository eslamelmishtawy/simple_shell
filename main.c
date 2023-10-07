#include "main.h"
/*
 * main - check code
 * @ac: ac
 * @av: av
 * Return: 0
 */
int main(int ac, char **av)
{
	int status = 0;
	char *line = NULL;
	(void) ac;
	(void) av;

	while(1)
	{
		line = line_read();
		if (line == NULL)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		free(line);
	}
}
