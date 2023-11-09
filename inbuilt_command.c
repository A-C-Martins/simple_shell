#include "shell.h"

/**
 * breakout_repl - quit interactive mode
 * @shell: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void breakout_repl(terminal_shell *shell)
{
	(shell->isActive) = FALSE;
}

/**
 * print_environ - print list of environmental variables.
 * @shell: double pointer back to shell interpreter
 * Description: PLACEHOLDER
 */
void print_environ(terminal_shell *shell)
{
	int i = 0;

	do {
		printf("%s\n", shell->environment[i++]);
	} while (shell->environment[i]);
}

