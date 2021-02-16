/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:34:29 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/05 21:13:31 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_n(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		s;
	int		len;
	char	*arr;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		s = 1;
	}
	len = count_n(n);
	if (!(arr = malloc(len + 1 + s)))
		return (NULL);
	if (s)
		arr[0] = '-';
	arr[len + s] = '\0';
	while (len)
	{
		arr[len - (s ? 0 : 1)] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (arr);
}
