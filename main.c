#include "minishell.h"

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

char* find_special(char* str, char spec)
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

char* make_except_envy(char* str, int i)
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

char* make_envy_command(char* str, char* envy, int i)
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

char* get_env_value_to_command(char* str)
{
	int		i;
	int		j;
	char* return_tmp;
	char** tmp;

	i = sc_get(str, '$', -1);
	j = -1;
	if (sc_get(str, '\'', -1) < sc_get(str, '\"', -1))
		return (str);
	while (g_envv[++j] != NULL)
	{
		tmp = ft_split(g_envv[j], '=');
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
	while (spec[i] != '\0')
	{
		if (str[0] == spec[i])
			return (spec[i]);
		i++;
	}
	return ('\0');
}

char* find_bin(char* str)
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
	while (str[++i + 1] != NULL)
	{
		if ((save = check_spec(str[i], "<>|")) && check_spec(str[i + 1], "<>|"))
		{
			printf("bash: syntax error near unexpected token '%c' \n", save);
			free_command(str);
			return (1);
		}
		if (sc_get(str[i], '<', -1) != 999)
			if (open(str[i + 1], O_RDWR, 0777) == -1)
			{
				printf("bash: (%s): No such file or directory\n", str[i + 1]);
				free_command(str);
				return (1);
			}
	}
	return (0);
}

char** make_command(char* str, int j)
{
	int		i;
	int		k;
	char** tmp;

	i = 0;
	k = j;
	tmp = (char**)malloc(sizeof(char*) * j + 1);
	while (k)
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
		k--;
	}
	tmp[0] = find_bin(tmp[0]);
	if (check_error(tmp))
		return (NULL);
	return (tmp);
}

char** divid_command(char* str)
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

char* re_make_location(char* str)
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

void	divid_commands(char* str)
{
	int		i;
	char** divided_command;
	char** c_command;

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
		check_value(c_command);	//디버깅용
		printf("\n");	//디거깅용
	}
}

char** get_envy_value(char** envy)
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

int		main(int argc, char* argv[], char** envy)
{
	char* command = "echo  abc\" abc\"   \'/bin/ls\' /bin/ls \">\" \' \"$HOME \" \' \" \'$HOME     \' \"  \" \'$-n \'a\" \\\"abc\" c \"\"c\"abd \" abc\' \" value  ;      /bin/ls; cd value ;pwd ; export ; unset value ; env value=/root ; exit";
	g_envv = get_envy_value(envy);
	divid_commands(command);
}
