/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:39:23 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/10 14:17:24 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(long long n)
{
	long long	n_tmp;
	int			size;

	n_tmp = n;
	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n_tmp *= -1;
		size++;
	}
	while (n_tmp)
		n_tmp = ++size ? n_tmp / 10 : n_tmp / 10;
	return (size);
}

char		*ft_itoa(long long n)
{
	int		m_size;
	long	n_tmp;
	char	*tmp;

	m_size = check_size(n);
	n_tmp = n;
	if (!(tmp = (char *)malloc(sizeof(char) * m_size + 1)))
		return (0);
	if (n_tmp == 0)
		tmp[0] = '0';
	if (n_tmp < 0)
	{
		n_tmp *= -1;
		tmp[0] = '-';
	}
	tmp[m_size] = '\0';
	while (n_tmp)
	{
		tmp[--m_size] = n_tmp % 10 + 48;
		n_tmp /= 10;
	}
	return (tmp);
}
