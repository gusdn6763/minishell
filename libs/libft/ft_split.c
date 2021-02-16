/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejang <hyejang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:03:34 by hyolim            #+#    #+#             */
/*   Updated: 2021/02/15 02:21:08 by hyejang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		split_size(char *str, char c)
{
	int i;
	int onoff;

	i = 0;
	onoff = 0;
	while (*str)
	{
		if (!(*str == c) && onoff == 0)
		{
			onoff = 1;
			i++;
		}
		else if ((*str == c) && onoff == 1)
			onoff = 0;
		str++;
	}
	return (i);
}

static int		word_len(char *str, char c)
{
	int i;

	i = 0;
	while (*str == c)
		str++;
	while (!(str[i] == c) && str[i] != 0)
		i++;
	return (i);
}

static void		ft_free(char **split_array, int malloc_cnt)
{
	int i;

	i = 0;
	while (i <= malloc_cnt)
	{
		free(split_array[i]);
		split_array[i++] = NULL;
	}
	free(split_array);
	split_array = NULL;
}

static char		**make_malloc(char *str, char c)
{
	char	**split_array;
	int		malloc_cnt;
	int		i;
	int		malloc_len;

	malloc_cnt = split_size(str, c);
	if (!(split_array = (char **)malloc(sizeof(char *) * (malloc_cnt + 1))))
		return (NULL);
	split_array[malloc_cnt] = 0;
	i = -1;
	while (++i < malloc_cnt)
	{
		malloc_len = word_len(str, c);
		if (!(split_array[i] = (char *)malloc(sizeof(char) * (malloc_len + 1))))
		{
			ft_free(split_array, malloc_cnt);
			return (0);
		}
		split_array[i][malloc_len] = 0;
		while (*str == c)
			str++;
		while (!(*str == c) && *str != 0)
			str++;
	}
	return (split_array);
}

char			**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**split_array;
	int		malloc_cnt;

	if (!str)
		return (NULL);
	if (!(split_array = make_malloc((char *)str, c)))
		return (NULL);
	i = 0;
	malloc_cnt = split_size((char *)str, c);
	while (i < malloc_cnt)
	{
		j = 0;
		while ((*str == c))
			str++;
		while (!(*str == c) && *str != 0)
			split_array[i][j++] = *str++;
		i++;
	}
	return (split_array);
}
