#include "shell.h"
/**
 * helpfree - an altern mallocnt for nos working commands
 * @struc: struct with data
 * Return: int for erasing status
 */
int helpfree(shell_t *struc)
{
	int c = 0;

	for (; c < struc->counter; c++)
	{
		free(struc->token[c]);
	}
	free(struc->token);
	c = 0;
	for (; c < struc->counterpath; c++)
	{
		free(struc->path[c]);
	}
	free(struc->str);
	free(struc->path);
	free(struc->getline);
	free(struc);
	exit(1);
}
