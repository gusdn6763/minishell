/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <gusdn6763@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:57:16 by hyejang           #+#    #+#             */
/*   Updated: 2020/04/06 15:42:53 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *to_find, int find)
{
	int		i;
	char	*to_find_tmp;
	char	find_tmp;

	to_find_tmp = (char *)to_find;
	find_tmp = (char)find;
	i = -1;
	if (find_tmp == '\0')
		return (&(to_find_tmp[ft_strlen(to_find)]));
	while (to_find_tmp[++i] != '\0')
		if (to_find_tmp[i] == find_tmp)
			return ((&(to_find_tmp[i])));
	return (0);
}
