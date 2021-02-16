/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:38:36 by hyejang           #+#    #+#             */
/*   Updated: 2021/02/16 23:15:15 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		count;
	char	*tmp;

	tmp = (char *)str;
	result = 0;
	i = 0;
	count = 1;
	while (tmp[i] != '\0' && (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\r'
			|| tmp[i] == '\n' || tmp[i] == '\v' || tmp[i] == '\f'))
		i++;
	if (tmp[i] == '+' || tmp[i] == '-')
		if (tmp[i++] == '-')
			count = -1;
	while (tmp[++i - 1] != '\0' && tmp[i - 1] >= '0' && tmp[i - 1] <= '9')
		result = result * 10 + tmp[i - 1] - '0';
	return (result * count);
}
