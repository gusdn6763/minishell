/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:52:14 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 17:04:02 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *t_v, const void *f_v, size_t size)
{
	unsigned char		*to_value_tmp;
	unsigned char		*f_v_tmp;

	to_value_tmp = (unsigned char*)t_v;
	f_v_tmp = (unsigned char*)f_v;
	if (f_v < t_v)
		while (size--)
			to_value_tmp[size] = f_v_tmp[size];
	else
		ft_memcpy(to_value_tmp, f_v_tmp, size);
	return (t_v);
}
