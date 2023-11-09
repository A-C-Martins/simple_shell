#include "shell.h"

/**
 * prompt_1 - prompt to shell
 */

void prompt_1()
{
	char c;

	c = '$';
	putchar(c);
	putchar(32);
}

/**
 * putsIn - takes in userinput
 * Return user input
 */

char *putsIn()
{
	char *buffer;
	size_t k = 1;
	ssize_t container;
	char newLine[] = {'\n', '\0'};

	buffer = malloc(sizeof(char) * 200);

	container = (getline(&buffer, &k, stdin));
	if (container == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[0] == '\n' && buffer[1] == '\n')
	{
	}
	else
	{
		buffer = strtok(buffer, newLine);
		if ((is_null(buffer)))
		{
			buffer[0] = '\n';
			buffer[1] = '\0';
		}
	}
	return (buffer);
}

int is_null(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != 32)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * main - entry pointer for program
 * @argc: number of arguments passed to program.
 * @argv: what arguments there were, if any.
 * @envp: complete list of enviornmental variables.
 *
 * Return: EXIT_SUCCESS (0) or EXIT_FAILURE (1)
 */
int main(
	__attribute__ ((unused)) int argc,
	__attribute__ ((unused)) char *argv[],
	char **envp
)
{
	terminal_shell *shell = NULL;
	int exit_status = 0;
	int is_interactive = isatty(STDIN_FILENO);

	create_shell(&shell, envp);

	if (is_interactive)
		start_repl(shell);
	else
		scan_script(shell);

	free_shell(shell);

	return (exit_status);
}
