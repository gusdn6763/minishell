/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42.seoul>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:42:52 by hyolim            #+#    #+#             */
/*   Updated: 2021/02/16 22:42:54 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_param(t_data *param)
{
	free(param->str);
	free_matrix(param->envp);
	free_matrix(param->export);
	free_matrix(param->argv);
	free_matrix(param->cmds);
	free(param);
}

void		exit_command(t_data *param)
{
	int i;

	if (param->argc > 2)
	{
		ft_putstrs_fd("exit\n", "bash: exit: too many arguments\n", 0, 2);
		param->ret = 1;
	}
	else
	{
		i = 0;
		while (param->argc > 1 && ft_isdigit(param->argv[1][i]))
		{
			i++;
		}
		if (param->argc > 1 && param->argv[1][i])
		{
			ft_putstrs_fd("exit\nbash: exit: ",
				param->argv[1], ": numeric argument required\n", 2);
			param->ret = 2;
		}
		i = (param->argc > 1 && param->ret != 2)
			? ft_atoi(param->argv[1]) : param->ret;
		free_param(param);
		exit(i);
	}
}