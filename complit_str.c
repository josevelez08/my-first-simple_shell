#include "shell.h"
/**
 * str_complet - append command to direction
 * @stringpath: path
 * @command: command
 * Return: the command appended
 */
char **str_complet(char *stringpath, char *command)
{
	char **path_com = malloc(sizeof(char *) * 1);
	char *comp_str = malloc(sizeof(char) * 100);
	int i = 0, j = 0, k = 0;

	while (stringpath[i] != '\0')
	{
		comp_str[j] = stringpath[i];
		i++;
		j++;
	}
	comp_str[j] = '/';
	j++;
	while (command[k] != '\0')
	{
		comp_str[j] = command[k];
		k++;
		j++;
	}
	comp_str[j] = '\0';
	path_com[0] = _strdup(comp_str);
	free(comp_str);
	return (path_com);
}
