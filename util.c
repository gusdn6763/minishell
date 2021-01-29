#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	char	*ret;
	char	*cpy_ret;

	if (!s || !(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= ft_strlen(s))
		ret[0] = '\0';
	else
	{
		ptr = (char*)s + start;
		cpy_ret = ret;
		while (*ptr != '\0' && len-- > 0)
			*cpy_ret++ = *ptr++;
		*cpy_ret = '\0';
	}
	return (ret);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int diff;

	i = 0;
	diff = 0;
	while (s2[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (diff);
}

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strlen(src);
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	j = -1;
	while (src[++j] != '\0')
		tmp[j] = src[j];
	tmp[j] = '\0';
	return (tmp);
}

int     ft_strlen(char *str)
{
	int	i;
	char	*str_tmp;

	i = 0;
	str_tmp = (char *)str;
	while (str_tmp[i] != '\0')
		i++;
	return (i);
}

static int		numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**div_word(char **test, char const *s, char c, int count)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	while (++i != count)
	{
		k = -1;
		while (s[j] == c)
			j++;
		if (!(test[i] = (char *)malloc(sizeof(char) * numchar(s, c, j) + 1)))
		{
			while (--i > -1)
				free(test[i + 1]);
			free(test);
			return (0);
		}
		while (s[j] != '\0' && s[j] != c)
			test[i][++k] = s[j++];
		test[i][++k] = '\0';
	}
	test[i] = NULL;
	return (test);
}

static int		get_count(char const *s, char c)
{
	int i;
	int div_count;

	i = -1;
	div_count = 0;
	if (s[0] == '\0' || !s)
		return (0);
	if (s[0] != c)
		div_count++;
	while (s[++i] != '\0')
		if (s[i] == c && s[i + 1] != '\0')
		{
			if (s[i + 1] == c)
				while (s[i + 1] == c)
				{
					if (s[i + 1] == '\0')
						div_count--;
					i++;
				}
			div_count++;
		}
	if (s[i - 1] == c)
		div_count--;
	return (div_count);
}

char			**ft_split(char const *s, char c)
{
	int		div_count;
	char	**tmp;

	if (s == NULL)
		return (NULL);
	div_count = get_count(s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * div_count + 1)))
		return (NULL);
	return (div_word(tmp, s, c, div_count));
}