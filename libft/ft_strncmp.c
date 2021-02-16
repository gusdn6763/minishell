/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:25:13 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 16:57:22 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			i;
	unsigned char	*str1_tmp;
	unsigned char	*str2_tmp;

	i = 0;
	str1_tmp = (unsigned char*)str1;
	str2_tmp = (unsigned char*)str2;
	if (num == 0)
		return (0);
	while (str1_tmp[i] == str2_tmp[i] && str1_tmp[i] != '\0' &&
		str2_tmp[i] != '\0' && i < num - 1)
		i++;
	return (str1_tmp[i] - str2_tmp[i]);
}
