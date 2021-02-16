/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:43:09 by hyejang           #+#    #+#             */
/*   Updated: 2020/07/01 12:52:20 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	delete_size;
	char	*tmp;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	delete_size = ft_strlen(&s1[i]);
	while (delete_size && ft_strchr(set, s1[delete_size + i]))
		delete_size--;
	tmp = ft_substr(&s1[i], 0, delete_size + 1);
	return (tmp);
}
