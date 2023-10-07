#include "main.h"
/**
 * main - check code
 * @ac: ac
 * @av: av
 * Return: 0
 */
int main(int ac, char **av)
{
	int status = 0, i = 0;
	char *line = NULL, **cmd = NULL;
	(void) ac;
	(void) av;

	while (1)
	{
		i = 0;
		line = line_read();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		cmd = tokenizer(line);
		if (!cmd)
			continue;
		while (cmd[i])
		{
			printf("%s\n", cmd[i]);
			i++;
		}
		free_list(cmd);
		free(line);
	}
}
