#include "../include/minishell.h"


void	ft_echo(char* str)
{
	ft_putstr_fd(str, 1);
}

void	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	ft_putendl_fd(pwd, 1);
}

void	ft_cd(char *path)
{
	chdir(path);
}

void	ft_env()
{
	exit(0);
}

int find_envy_value(char *env)
{
	int i;
	char **tmp;
	char **test;

	i = 0;
	while (g_envp[i])
	{
		test = ft_split(env, '=');
		tmp = ft_split(g_envp[i], '=');
		if (ft_strncmp(tmp[0], test[0], 100) == 0)
		{
			free(g_envp[i]);
			g_envp[i] = ft_strdup(env);
			free_command(tmp);
			free_command(test);
			return (1);
		}
		free_command(tmp);
		free_command(test);
		i++;
	}
	return (0);
}

void print_envy()
{
	int i;
	int j;
	char **test;

	i = -1;
	while (g_envp[++i])
	{
		j = -1;
		test = ft_split(g_envp[i], '=');
		ft_putstr_fd("declare -x ",1);
		while (test[++j])
		{
			ft_putstr_fd(test[j],1);
			if (test[1] != NULL)
			{
				ft_putstr_fd("=\"",1);
				ft_putstr_fd(test[1],1);
				ft_putstr_fd("\"",1);
				j++;
			}
		}
		ft_putstr_fd("\n", 1);
		free_command(test);
	}
}

void	ft_export(char *env)
{
	int i;
	char **new_envv;
	int len;

	i = 0;
	len = get_double_pointer_len(g_envp);
	if (env == NULL)
		print_envy();
	else if(find_envy_value(env))
		return;
	else
	{
		new_envv = (char **)malloc(sizeof(char *) * (len + 2));
		new_envv[len + 1] = NULL;
		while (g_envp[i] != NULL)
		{
			new_envv[i] = ft_strdup(g_envp[i]);
			i++;
		}
		new_envv[i] = ft_strdup(env);
		g_envp = new_envv;
	}
}

void	ft_unset(char *env)
{
	exit(0);
}

void	ft_exit(void)
{
	exit(0);
}
