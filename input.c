#include "shell.h"
/**
*input - reads stdin and put chars into input
*Return: pointer to struct
*/
shell_t *input(void)
{
	int pos = 0;
	char *input = malloc(sizeof(char) * 1024);
	shell_t *struc = malloc(sizeof(shell_t));
	char *str = malloc(sizeof(char) * 100);
	char charr;
	int i = 0;

	struc->i = i;
	struc->str = str;
	if (input == NULL)
	{
		fprintf(stderr, "hsh: error almacenamiento\n");
		free(input);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		charr = _getchar();
		if (charr == EOF)
		{
			free(input);
			free(str);
			free(struc);
			exit(EXIT_FAILURE);
		}
		else if (charr == '\n')
		{
			input[pos] = '\0';
			struc->getline = input;
			return (struc);
		}
		else
			input[pos] = charr;
		pos++;
	}
}
