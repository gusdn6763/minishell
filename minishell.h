# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int     ft_strlen(char* str);
char* ft_strdup(char* str);
char** ft_split(char const* s, char c);
char* ft_substr(char* s, int start, int len);
int		ft_strcmp(const char* s1, const char* s2);
int     find_spec(char* str, char tmp, int j);
int     get_string_size(char* str);
int		ft_strlcpy(char* dest, char* src, int size);
char* ft_strnstr(char* value, char* t_v, int len);
char* find_special(char* str, char tmp);
int		ft_strncmp(char* s1, char* s2, int n);
int get_string_size(char* str);

char** g_envv;