#include "main.h"
/**
 * main - check code
 * @ac: ac
 * @av: av
 * @env: environment
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int status = 0;
	char *line = NULL, **cmd = NULL;
	pid_t fork_return;
	(void) ac;
	(void) av;

	while (1)
	{
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
		fork_return = fork();
		if (fork_return == 0)
		{
			if (execve(cmd[0], cmd, env) == -1)
			{
				perror(cmd[0]);
				free_list(cmd);
				free(line);
				exit(99);
			}
		}
		else
		{
			waitpid(fork_return, &status, 0);
		}
		free_list(cmd);
		free(line);
	}
}
