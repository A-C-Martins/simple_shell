#include "shell.h"

/**
 * start_repl - Open a READ-EVALUATE-PRINT-LOOP with the interpreter.
 * @shell: Double pointer back to the interpreter.
 *
 * Return: void (for now).
 */
void start_repl(terminal_shell *shell)
{
	char *line = NULL;

	while (shell->isActive == TRUE)
	{
		prompt_1();
		line = putsIn();
		parse_line(shell, line);
		free(line);
		fflush(NULL);
	}
}

/**
 * scan_script - Read a script piped in from stdin.
 * @shell: Double pointer back to the interpreter.
 *
 * Return: void.
 */
void scan_script(terminal_shell *shell)
{
	char *current_line = NULL;

	do {
		current_line = putsIn();

		if (current_line != NULL)
			parse_line(shell, current_line);
		else
			shell->isActive = FALSE;

		free(current_line);
		fflush(NULL);

	} while (shell->isActive == TRUE);
}

























