#include "../include/minishell.h"


char **make_exe_path(void)
{
	char **split_env;
	char **path;

	int i;
	i = 0;

	while (g_envp[i] != NULL)
	{
		split_env = ft_split(g_envp[i], '=');

		if( 0 == ft_strncmp(split_env[0], "PATH", 100))
		{
			path = ft_split(split_env[1], ':');
		}
		i++;
	}
	return (path);
}

int run_exe(char **argu)
{
	char **exe_path;
	exe_path = make_exe_path();
	//함수 성공 여부 반환
	int ret = 0;
	int i;
	pid_t pid;
	int status;

	if (  (pid = fork()) < 0  )
		return (-1);
	else if (pid == 0)
	{
		char *path;
		i = 0;
		while (exe_path[i] != NULL)
		{
			path = ft_strjoin(ft_strjoin(exe_path[i], "/"), argu[0]);
			if (execve(path, argu, g_envp) != -1)
			{
				ret = 1 ;
				break;
			}
			i++;
		}
	}
	else
		waitpid(pid, &status, 0);

	return (ret);
}


int	run_ft_exe(char** argu)
{
	if (ft_strncmp(argu[0], "ehco", 100) == 0)
		ft_echo(argu[1]);
	else if (ft_strncmp(argu[0], "cd", 100) == 0)
		ft_cd(argu[1]);
	else if (ft_strncmp(argu[0], "pwd", 100) == 0)
		ft_pwd();
	else if (ft_strncmp(argu[0], "export", 100) == 0)
		ft_export(argu[1]);
	else if (ft_strncmp(argu[0], "unset", 100) == 0)
		ft_unset(argu[1]);
	else if (ft_strncmp(argu[0], "env", 100) == 0)
		ft_env();
	else if (ft_strncmp(argu[0], "exit", 100) == 0)
		ft_exit();
	else
		return (0);
	return (1);
}

void run_command(char **argu)
{
	if (run_ft_exe(argu))
		NULL;
	else if (run_exe(argu))
		NULL;
	dup2(fd_stdout,1);
}
