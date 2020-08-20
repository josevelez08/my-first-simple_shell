#include "shell.h"
/**
*execute - executes program
*@struc: pointer to structura
*Return: 1 on success
*/
int execute(shell_t *struc)
{
	int status;

	if (struc->token[0] == NULL)
	{
		return (1);
	}
	status = process(struc);
	if (struc->command_to_ex != NULL)
	{
		free(struc->command_to_ex[0]);
		free(struc->command_to_ex);
	}
	if (status == 0)
		mem_free(struc);
	if (status == -1)
		helpfree(struc);
	return (1);
}
