/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <hyolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 02:43:16 by hyolim            #+#    #+#             */
/*   Updated: 2020/05/07 00:36:28 by hyolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		can_trim(char c, char const *set)
{
	size_t		num;

	num = -1;
	while (set[++num])
		if (set[num] == c)
			return (1);
	return (0);
}

static	size_t		count_char(char const *s1, char const *set)
{
	size_t		num;
	size_t		len;

	num = 0;
	len = ft_strlen(s1);
	while (can_trim(s1[len - num - 1], set))
		num++;
	return (len - num);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		num;
	size_t		len;
	char		*str;

	num = 0;
	len = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (can_trim(s1[num], set))
		num++;
	if (num == (size_t)ft_strlen(s1))
		return (ft_strdup(""));
	len = count_char(s1 + num, set) + 1;
	if (!(str = malloc(len)))
		return (NULL);
	ft_strlcpy(str, s1 + num, len);
	return (str);
}
