/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:53:06 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/05 19:25:45 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		iswhite(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	long i;
	long s;
	long r;

	i = 0;
	s = 1;
	r = 0;
	while (iswhite(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10 + (str[i++] - '0');
		if (r > 2147483647 && s > 0)
			return (-1);
		if (r > 2147483648 && s < 0)
			return (0);
	}
	return (r * s);
}
