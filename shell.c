#include "shell.h"

/**
 * create_shell - allocate memory for the simple shell and set inotal values
 * @shell: double pointer back to the simple shell
 * @envp: environmental variables passed directly from main
 *
 * Return: Whether or not the shell was sucessfully created.
 */
void create_shell(terminal_shell **shell, char **envp)
{
	*shell = malloc(sizeof(terminal_shell));
	if (shell == NULL)
		return;

	((*shell)->lenght) = 0;
	((*shell)->exit_status) = 0;
	((*shell)->isActive) = TRUE;
	(*shell)->environment = envp;
	(*shell)->path_variable = split_string(getenv("PATH"), ":");
	(*shell)->cmd_path = NULL;
	(*shell)->builtin = NULL;
}

/**
 * parse_line - parses an individual line taken from a script or the REPL
 * @shell: double pointer back to the simple shell
 * @new_line: the new line to be parsed
 *
 * Description: WILL REQUIRE SIGNIFICANT OVERHALL TO SUPPORT PIPES!!!
*/
void parse_line(terminal_shell *shell, char *new_line)
{
	shell->cmd_arguments = split_string(new_line, " ");

	shell->builtin = get_builtin(shell->cmd_arguments[0]);

	shell->cmd_path = find_command_path(shell);

	if (shell->builtin != NULL)
		shell->builtin(shell);
	else if (shell->cmd_path != NULL)
		create_fresh_process(shell);
	else
		throw_error(shell, 2);

	free_array(shell->cmd_arguments);
	free(shell->cmd_path);
}
/**
 * free_shell - deallocates memory for the interpreter and its properties
 * @shell: double pointer back to the simple shell
 */
void free_shell(terminal_shell *shell)
{
	free_array(shell->path_variable);

	free(shell);
}

/**
 * free_array - deallocates memory allocated through split_string function
 * @an_array: the array that needs to be deallocated.
*/
void free_array(char **an_array)
{
	int i;

	for (i = 0; an_array[i]; i++)
		free(an_array[i]);

	free(an_array);
}

/**
 * get_builtin - runs through and tries to find built-in commands
 * @command: the command we're looking for as a string
 *
 * Return: funciton pointer to back to command to execute
*/
void (*get_builtin(char *command))(terminal_shell *)
{
	int i;
	InbuiltCommand builtins[] = {
		{"exit", breakout_repl},
		{"quit", breakout_repl},
		{"env", print_environ},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (strcmp(command, builtins[i].name) == 0)
			return (builtins[i].exec);
	}
	return (NULL);
}
