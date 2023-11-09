#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct terminal - information representing current state of the shell
 * @lenght: current line number of script
 * @exit_status: exit failure or success
 * @isActive: True (1) or if repl loop still open
 * @path_variable: path variable inherited from environment as string array
 * @environment: the enviornmental variables.
 * @builtin: function pointer to a builtin command (if any)
 * @cmd_path: path to executable file to invoke (if any)
 * @cmd_arguments: arguments parsed from last line of input
 */

typedef struct terminal
{
	int lenght;
	int exit_status;
	int isActive;
	char **path_variable;
	char **environment;
	char *cmd_path;
	char **cmd_arguments;
	void (*builtin)(struct terminal *);
} terminal_shell;

/**
 * struct InbuiltCommand - Information to build table of built in commands
 * @name: name of the command
 * @exec: function pointer to function which executes command
 */

typedef struct InbuiltCommand
{
	char *name;
	void (*exec)(terminal_shell *self);
} InbuiltCommand;

#define TRUE 1
#define FALSE 0

#define PATH_MAX_SIZE 4096

void throw_error(terminal_shell *shell, int errorNum);

void create_fresh_process(terminal_shell *shell);
char *create_test_path(char *dir_path, char *cmd);
char *find_command_path(terminal_shell *self);

void print_environ(terminal_shell *self);
void breakout_repl(terminal_shell *self);
void (*get_builtin(char *command))(terminal_shell *);

void create_shell(terminal_shell **shell, char **envp);
void parse_line(terminal_shell *shell, char *new_line);
void free_shell(terminal_shell *shell);
void free_array(char **an_array);

void start_repl(terminal_shell *shell);
void scan_script(terminal_shell *shell);

void prompt_1();
int is_null(char *str);
char *putsIn();
int num_of_spaces(char *string, char *delimiter);
char **split_string(char *string_to_split, char *delimiter);

#endif
