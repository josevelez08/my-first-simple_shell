#include "shell.h"
/**
 * div_path - gets the path
 * @data: struct with data
 * Return: teh path
 */
shell_t *div_path(shell_t *structure)
{
	char *string_p = NULL, *path_tok = NULL, *str_p_cpy = NULL;
	int pcont = 0;
	char **toks_path = malloc(sizeof(char *) * 30);
		string_p = getenv("PATH");
		str_p_cpy = strdup(string_p);
		path_tok = strtok(str_p_cpy, ":");
		for (; path_tok != NULL; path_tok = strtok(NULL, ":"))
		{
			toks_path[pcont] = _strdup(path_tok);
			pcont++;
		}
		toks_path[pcont] = path_tok;
		structure->counterpath = pcont;
		structure->path = toks_path;
		free(str_p_cpy);
		return (structure);
}
