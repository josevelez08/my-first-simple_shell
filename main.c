#include "shell.h"
/**
*main - principal function
*Return: 0 on succes.
*/
int main(void)
{
	shell_t *structure;
while (1)
{
	signal(SIGINT, signal_handler);
	if (isatty(STDIN_FILENO))
	prompt();
	if (errno == 1)
	{
		exit(1);
	}
	structure = input();
	structure = tokens(structure);
	if (structure->token[0][0] != '/')
	{
		structure = div_path(structure);
		structure = find(structure);
		if (structure->command_to_ex != NULL)
		{
			while (structure->command_to_ex[0][structure->i] != '\0')
			{
				structure->str[structure->i] = structure->command_to_ex[0][structure->i];
				structure->i++;
			}
		structure->str[structure->i] = '\0';
		free(structure->token[0]);
		structure->token[0] = strdup(structure->str);
		}
	}
	execute(structure);
}
return (0);
}
