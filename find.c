#include "shell.h"
/**
 * find - search for a file in a directory
 * @date: struct with data
 * Return: teh path
 */
shell_t *find(shell_t *date)
{
	DIR *dp;
	struct dirent *dirp;
	int i = 0;

	while (date->path[i] != NULL)
	{
		dp = opendir(date->path[i]);
		if (dp == NULL)
		{
			printf("can't open %s", date->path[i]);
			exit(1);
		}
		while ((dirp = readdir(dp)) != NULL)
		{
			if (!_strcmp(dirp->d_name, date->token[0]))
			{
				closedir(dp);
				date->command_to_ex = str_complet(date->path[i], date->token[0]);
				return (date);
			}
		}
	closedir(dp);
	i++;
	}
	date->command_to_ex = NULL;
	return (date);
}
