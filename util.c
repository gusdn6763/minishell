#include "minishell.h"

int		ft_strncmp(char* s1, char* s2, int n)
{
	int				i;
	unsigned char* s1_c;
	unsigned char* s2_c;

	i = 0;
	s1_c = (unsigned char*)s1;
	s2_c = (unsigned char*)s2;
	while (s1_c[i] != '\0' && s2_c[i] != '\0' && i < n)
	{
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
		i++;
	}
	if (s1_c[i] != s2_c[i] && i != n)
		return (s1_c[i] - s2_c[i]);
	return (0);
}

int		ft_strlcpy(char* dest, char* src, int size)
{
	int	i;
	int	j;
	char* src_tmp;

	i = ft_strlen(src);
	j = -1;
	if (!dest || !size)
		return (0);
	src_tmp = (char*)src;
	while (src_tmp[++j] != '\0' && j < (size - 1))
	{
		dest[j] = src_tmp[j];
	}
	dest[j] = '\0';
	return (i);
}

char* ft_strnstr(char* value, char* t_v, int len)
{
	int	i;
	int	j;
	char* val_tmp;
	char* to_find_tmp;

	val_tmp = (char*)t_v;
	to_find_tmp = (char*)value;
	i = -1;
	if (val_tmp[i + 1] == '\0')
		return ((char*)value);
	while (to_find_tmp[++i] != '\0' && i < len)
	{
		j = 0;
		while (to_find_tmp[i + j] != '\0' && to_find_tmp[i + j] == val_tmp[j] && i + j < len)
		{
			if (val_tmp[j + 1] == '\0')
				return (&to_find_tmp[i]);
			++j;
		}
	}
	return (0);
}

// abc" c """ -> abc c | " abc' " ->  abc'
char* ft_substr(char* str, int start, int len)
{
	char* tmp;
	int		size;

	if (str == 0 || !(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= (size = ft_strlen(str)))
		tmp[0] = '\0';
	else
		ft_strlcpy(tmp, str + start, len + 1);
	return (tmp);
}

int		ft_strcmp(const char* s1, const char* s2)
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
			break;
		}
		i++;
	}
	return (diff);
}

char* ft_strdup(char* src)
{
	char* tmp;
	int		i;
	int		j;

	i = ft_strlen(src);
	if (!(tmp = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	j = -1;
	while (src[++j] != '\0')
		tmp[j] = src[j];
	tmp[j] = '\0';
	return (tmp);
}

int     ft_strlen(char* str)
{
	int	i;
	char* str_tmp;

	i = 0;
	str_tmp = (char*)str;
	while (str_tmp[i] != '\0')
		i++;
	return (i);
}

static int		numchar(char const* s2, char c, int i)
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

static char** div_word(char** test, char const* s, char c, int count)
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
		if (!(test[i] = (char*)malloc(sizeof(char) * numchar(s, c, j) + 1)))
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

static int		get_count(char const* s, char c)
{
	int i;
	int div_count;

	i = -1;
	div_count = 0;
	if (s[0] == '\0' || !s)
		return (1);
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

char** ft_split(char const* s, char c)
{
	int		div_count;
	char** tmp;

	if (s == NULL)
		return (NULL);
	div_count = get_count(s, c);
	if (!(tmp = (char**)malloc(sizeof(char*) * div_count + 1)))
		return (NULL);
	return (div_word(tmp, s, c, div_count));
}