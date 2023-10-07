#include "main.h"

/**
 * free_list - this function to free
 * lists of strings
 *
 * @list: list to be freed
 */

void free_list(char **list)
{
	int i = 0;

	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}
