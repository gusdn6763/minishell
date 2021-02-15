#include "../include/minishell.h"
#include <signal.h>

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

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		display_prompt();
	}
}


int		ft_strcmp(const char* s1, const char* s2)
{
	int i;
	int diff;

	i = 0;
	diff = 0;
	while (s2[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			break;
		}
		i++;
	}
	return (diff);
}

void	check_value(char** str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		printf("(%s) ", str[i]);
		i++;
	}
}

int		sc_get(char* str, char tmp, int j)
{
	int i;

	i = 0;
	j++;
	while (str[j] != tmp)
	{
		if (str[j] == '\0')
			return (999);
		j++;
		i++;
	}
	return (i);
}

int		get_string_size(char* str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((str[i] != ' ' || str[i] == ';') && str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			if (i > 0)
			{
				if (str[i - 1] != '\\')
				{
					j = sc_get(str, str[i], i) + j + 1;
					i = sc_get(str, str[i], i) + i + 1;
				}
			}
			else
			{
				j = sc_get(str, str[i], i) + j + 1;
				i = sc_get(str, str[i], i) + i + 1;
			}
		i++;
		j++;
	}
	return (j);
}

int		space_count(char* str)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	return (i);
}

char*	find_special(char* str, char spec)
{
	int		i;
	int		count;
	int		check;
	char* tmp;

	i = -1;
	count = 0;
	check = 0;
	tmp = (char*)malloc(ft_strlen(str) + 1);
	while (str[++i])
	{
		if (str[i] == '\\')
			tmp[count++] = str[i++ + 1];
		if (str[i] != spec || !check)
			tmp[count++] = str[i];
		if (str[i] == spec)
			check = 1;
	}
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char*	make_except_envy(char* str, int i)
{
	int		j;
	char* tmp;

	j = sc_get(str, ' ', i - 1);
	tmp = (char*)malloc(ft_strlen(str) + 1);
	ft_strlcpy(tmp, str, i + 1);
	ft_strlcpy(&tmp[i], &str[j + i], i + 1);
	free(str);
	return (tmp);
}

char*	make_envy_command(char* str, char* envy, int i)
{
	int		j;
	int		k;
	char* tmp;

	j = sc_get(str, ' ', i - 1);
	k = ft_strlen(envy);
	tmp = (char*)malloc(ft_strlen(str) + k + 1);
	ft_strlcpy(tmp, str, i + 1);
	ft_strlcpy(&tmp[i], envy, k + 1);
	ft_strlcpy(&tmp[i + k], &str[j + i], ft_strlen(str) - i - j + 1);
	return (tmp);
}

void	free_command(char** str)
{
	int i;

	i = 0;
	while (!str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char*	get_env_value_to_command(char* str)
{
	int		i;
	int		j;
	char* return_tmp;
	char** tmp;

	i = sc_get(str, '$', -1);
	j = -1;
	if (sc_get(str, '\'', -1) < sc_get(str, '\"', -1))
		return (str);
	while (g_envp[++j] != NULL)
	{
		tmp = ft_split(g_envp[j], '=');
		if (0 == ft_strncmp(tmp[0], &str[i + 1], sc_get(&str[i], ' ', 0)))
		{
			return_tmp = make_envy_command(str, tmp[1], i);
			free_command(tmp);
			return (return_tmp);
		}
		free_command(tmp);
	}
	return_tmp = make_except_envy(str, i);
	return (return_tmp);
}

char	check_spec(char* str, char* spec)
{
	int i;

	i = 0;
	if (!str)
		return (spec[0]);
	while (spec[i] != '\0')
	{
		if (str[0] == spec[i])
		{
			return (spec[i]);
		}
		i++;
	}
	return ('\0');
}

char*	find_bin(char* str)
{
	int		i;
	char* tmp;

	i = space_count(str);
	if (!(ft_strncmp(&str[i], "/bin/", 5)))
	{
		tmp = ft_strdup((&str[i + 5]));
		free(str);
		return (tmp);
	}
	return (str);
}

int		check_error(char** str)
{
	int		i;
	char	save;

	i = -1;
	while (str[++i] != NULL)
		if ((save = check_spec(str[i], "<>|")) && check_spec(str[i + 1], "<>|"))
		{
			ft_putstr_fd("bash: syntax error near unexpected token '", 1);
			if(str[i + 1] == NULL)
				ft_putstr_fd("newline", 1);
			else
				ft_putstr_fd(&save, 1);
			ft_putstr_fd("' \n", 1);
			free_command(str);
			return (1);
		}
	return (0);
}

int		check_redirection(char** str)
{
	int		i;
	char	save;

	i = -1;
	while (str[++i] != NULL)
		if (sc_get(str[i], '<', -1) != 999)
			if (open(str[i + 1], 1, 0777) == -1)
			{
				ft_putstr_fd("bash: (", 1);
				ft_putstr_fd(str[i + 1], 1);
				ft_putstr_fd("): No such file or directory\n", 1);
				free_command(str);
				return (1);
			}
	return (0);
}

char**	make_command(char* str, int j)
{
	int		i;
	int		k;
	char** tmp;

	i = 0;
	k = j + 1;
	tmp = (char**)malloc(sizeof(char*) * j + 1);
	while (--k)
	{
		i += space_count(&str[i]);
		tmp[j - k] = ft_substr(str, i, get_string_size(&str[i]));
		if (sc_get(tmp[j - k], '\'', -1) > sc_get(tmp[j - k], '\"', -1))
			tmp[j - k] = find_special(tmp[j - k], '\"');
		else if (sc_get(tmp[j - k], '\'', -1) < sc_get(tmp[j - k], '\"', -1))
			tmp[j - k] = find_special(tmp[j - k], '\'');
		if (sc_get(tmp[j - k], '$', -1) != 999)
			tmp[j - k] = get_env_value_to_command(tmp[j - k]);
		i += get_string_size(&str[i]);
	}
	tmp[0] = find_bin(tmp[0]);
	if (check_error(tmp) || check_redirection(tmp))
		return (NULL);
	return (tmp);
}

char**	divid_command(char* str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (str[i])
	{
		i += space_count(&str[i]);
		j = get_string_size(&str[i]);
		size++;
		i += j;
		i += space_count(&str[i]);
	}
	return (make_command(str, size));
}

char*	re_make_location(char* str)
{
	int		i;
	int		j;
	char* tmp;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (j = sc_get(str, '=', -1) == 999)
		return (str);
	tmp = (char*)malloc(i + 3);
	while (j != -1)
		tmp[j--] = str[j];
	j = sc_get(str, '=', -1);
	tmp[j + 1] = '\"';
	tmp[i + 1] = '\"';
	tmp[i + 2] = '\0';
	while (i - j - 1)
		tmp[i--] = str[i - 1];
	free(str);
	return (tmp);
}

char**	get_envy_value(char** envy)
{
	char** envy_value;
	int		i;

	i = 0;
	while (envy[i])
		i++;
	if (!(envy_value = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	i = -1;
	while (envy[++i])
		envy_value[i] = ft_strdup(envy[i]);
	return (envy_value);
}

int		get_spec_value(char** command, char* spec)
{
	int i;

	i = -1;
	while (command[++i] != NULL)
		if (!strcmp(command[i], spec))
			return (i);
	return (0);
}

int		get_double_pointer_len(char ** arg)
{
    int i = 0;
    while (arg[i] != NULL)
    {
        //printf("%s \n",arg[i]);
        i++;
    }
    return (i);
}

void	divid_commands(char* str)
{
	int		i;
	char**	divided_command;
	char**	c_command;

	i = -1;
	if (!str)
		return;
	divided_command = ft_split(str, ';');
	while (divided_command[++i])
	{
		if ((c_command = divid_command(divided_command[i])) == NULL)
			return;
		if (!(ft_strncmp(c_command[0], "env", 3)) || !(ft_strncmp(c_command[0], "export", 3)))
			c_command[1] = re_make_location(c_command[1]);
		split_pipe(c_command);
	}
}

void	split_pipe(char **input)
{
	int i;
	int splited_len;

	i = -1;
	splited_len = 0;
	while (input[++i] != NULL)
		if (ft_strncmp(input[i], "|", 1) == 0)
			splited_len++;
	if(!splited_len)
		split_OUTredirection(input, 999, 999);
	else
		split_OUTredirection(input, splited_len, splited_len);
}

void	split_OUTredirection(char **input, int count, int num)
{
	int i;
	int j;
	char *file_name;
	int fd;

	i = -1;
	j = 0;
	while (input[++i] != NULL)
		if((ft_strncmp(input[i], ">", 1) == 0) && count--)
		{
			if (j != 0)
				j = i;
			i++;
			file_name = split_space(input[i])[0];
			fd = open(file_name, O_RDWR | O_CREAT, 0744);
			if ((i + 1 == num))
				dup2(fd , 1);
			close(fd);
		}
	split_INredirection(input, j, j);
}

void	split_INredirection(char **input, int count, int num)
{
	int i;
	char *file_name;
	int fd;
	int j;

	i = -1;
	j = 0;
	while (input[++i] != NULL)
		if((ft_strncmp(input[i], "<", 1) == 0) && count--)
		{
			if (j != 0)
				j = i;
			file_name = split_space(input[i])[0];
			fd = open(file_name, O_RDONLY);
			if ((i + 1 == num))
				dup2(fd , 0);
			close(fd);
		}
	run_command(input);
}

char	**split_space(char *input)
{
	char **arr = ft_split(input, ' ');
	return (arr);
}
