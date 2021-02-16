#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h> //malloc
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h> //open
# include <sys/types.h>
# include <sys/stat.h>
# include "../libs/libft/libft.h"
#include <sys/wait.h>


char **g_envp;
int fd_stdout;
int fd_stdin;

void	ft_pwd(void);
void	ft_echo(char* str);
void	ft_cd(char *path);
void	ft_env();
void	ft_export(char *env);
void	ft_unset(char *env);
void	ft_exit(void);
void	display_prompt(void);
void	proc_signal_handler(int signo);
void	signal_handler(int signo);

char **make_exe_path(void);
int run_exe(char **argu);
int	run_ft_exe(char** argu);
void run_command(char** argu);
void	free_command(char** str);

//split.c
int get_double_pointer_len(char ** arg);
void split_semicolon(char * input);
void split_pipe(char **input);
void split_OUTredirection(char **input, int count, int num);
void split_INredirection(char **input, int count, int num);
char **split_space(char * input);
void	divid_commands(char* str);
void	print_envy();
#endif
