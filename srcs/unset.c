/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42.seoul>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:43:21 by hyolim            #+#    #+#             */
/*   Updated: 2021/02/16 22:43:22 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**erase_env(char **envp, int i)
{
	int		j;
	int		len;
	char	**cpy;

	len = 0;
	while (envp[len])
		len++;
	if (!(cpy = (char **)ft_calloc(sizeof(char *), len)))
		return (NULL);
	j = -1;
	while (++j < i)
		cpy[j] = ft_strdup(envp[j]);
	i++;
	while (envp[i])
		cpy[j++] = ft_strdup(envp[i++]);
	free_matrix(envp);
	return (cpy);
}

char		**unset_command(t_data *param, int j)
{
	int		i;
	int		len;
	char	*env;
	char	**cpy;

	if (param->argc < 2)
		return (param->envp);
	len = strlen(param->argv[j]);
	env = ft_strjoin(param->argv[j], "=");
	i = 0;
	while (param->envp[i] && ft_memcmp(env, param->envp[i], len + 1))
		i++;
	if (param->envp[i])
		cpy = erase_env(param->envp, i);
	else
		cpy = param->envp;
	free(env);
	return (cpy);
}
