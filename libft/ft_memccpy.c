/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:31:37 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 17:04:15 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *t_v, const void *f_v, int c, size_t size)
{
	size_t			i;
	unsigned char	c_tmp;
	unsigned char	*to_value_tmp;
	unsigned char	*from_value_tmp;

	i = -1;
	c_tmp = (unsigned char)c;
	to_value_tmp = (unsigned char*)t_v;
	from_value_tmp = (unsigned char*)f_v;
	while (++i < size)
	{
		to_value_tmp[i] = from_value_tmp[i];
		if (c_tmp == from_value_tmp[i])
			return (&(to_value_tmp[i + 1]));
	}
	return (0);
}
