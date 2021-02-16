#include "../include/minishell.h"

int init_envp(char **envp)
{
	int len;
	int i;

	len = 0;
	while (envp[len] != NULL)
		len++;

	//g_envp free 필요
	g_envp = (char **)malloc(sizeof(char *) * (len + 1));
	g_envp[len] = NULL;

	i = 0;
	while (i < len)
	{
		//ft_strdup free 필요.
		g_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	// 맨마지막에 g_envp 통채로 free하자.
	return (len);
}

void display_prompt(void)
{
	ft_putstr_fd("bash-HS$ ",1);
}

char* receive_cmd(void)
{
	char read_input[1024];
	int readbyte;
	readbyte = read(1,read_input,200);
	read_input[readbyte - 1] = '\0';
	if (read_input[0] == '\0')
	{
		return NULL;
	}
	if (!readbyte)
	{
		ft_putstr_fd("\n",1);
		exit(1);
	}
	return ft_strdup(read_input);
}

int		main(int argc, char **argv, char **envp)
{

	int envp_len;
	envp_len = init_envp(envp);

	fd_stdout = dup(1);
	fd_stdin = dup(0);

	signal(SIGINT, signal_handler);
	char *read_input;
	while (1)
	{
		display_prompt();
		read_input = receive_cmd();
		divid_commands(read_input);
	}
	close(fd_stdout);
	close(fd_stdin);

	return (0);
}
