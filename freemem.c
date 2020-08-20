#include "shell.h"
/**
*mem_free - frees memory
*@struc: pointer to struct
*Return: 0 on success
*/
int mem_free(shell_t *struc)
{
	int pos = 0;

	for (; pos < struc->counter; pos++)
	{
		free(struc->token[pos]);
	}
	free(struc->token);
	pos = 0;
	for (; pos < struc->counterpath; pos++)
	{
		free(struc->path[pos]);
	}
	free(struc->str);
	free(struc->path);
	free(struc->getline);
	free(struc);
	return (0);
}
