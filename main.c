#include "minishell.h"

void check_value(char** str)
{
    int i = 0;
    while (str[i] != NULL)
    {
        printf("(%s) ", str[i]);
        i++;
    }
}

int find_spec(char* str, char tmp, int j)
{
    int i;

    i = 0;

    j++;
    while (str[j] != tmp)
    {
        if (str[j] == '\0')
            return (999);
        j++;
        i++;
    }
    return (i);
}

int get_string_size(char* str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((str[i] != ' ' || str[i] == ';') && str[i] != '\0')
    {
        if (str[i] == '\'' || str[i] == '\"')
            if (i > 0)
            {
                if (str[i - 1] != '\\')
                {
                    j = find_spec(str, str[i], i) + j + 1;
                    i = find_spec(str, str[i], i) + i + 1;
                }
            }
            else
            {
                j = find_spec(str, str[i], i) + j + 1;
                i = find_spec(str, str[i], i) + i + 1;
            }
        i++;
        j++;
    }
    return (j);
}

int space_count(char* str)
{
    int i;

    i = 0;
    while (str[i] == ' ' && str[i] != '\0')
        i++;
    return (i);
}

char* find_special(char* str, char spec)
{
    int i;
    int count;
    char* tmp;

    i = 0;
    count = 0;
    tmp = (char*)malloc(ft_strlen(str) + 1);
    while (str[i])
    {
        if (str[i] == '\\')
        {
            if (str[i + 1] == '\'' || str[i + 1] == '\"' || str[i + 1] == '$')
                tmp[count++] = str[i++ + 1];
        }
        else if (str[i] != spec)
            tmp[count++] = str[i];
        i++;
    }
    tmp[count] = '\0';
    free(str);
    return (tmp);
}

char* get_env_value_to_command(char* str)
{
    int i;
    int j;
    char** tmp;

    i = find_spec(str, '$', -1);
    j = -1;
    if (find_spec(str, '\'', -1) < find_spec(str, '\"', -1))
        return (str);
    while (g_envv[++j] != NULL)
    {
        tmp = ft_split(g_envv[j], '=');
        if (0 == ft_strncmp(tmp[0], &str[i + 1], find_spec(&str[i], ' ', 0)))
        {
            free(str);
            return (tmp[1]);
        }
    }
    free(str);
    return (ft_strdup(""));
}

char** make_command(char* str, int size)
{
    int i;
    int k;
    char** tmp;

    i = 0;
    k = size;
    tmp = (char**)malloc(sizeof(char*) * size + 1);
    while (k)
    {
        i += space_count(&str[i]);
        tmp[size - k] = ft_substr(str, i, get_string_size(&str[i]));
        if (find_spec(tmp[size - k], '$', -1) != 999)
            tmp[size - k] = get_env_value_to_command(tmp[size - k]);
        if (find_spec(tmp[size - k], '\'', -1) > find_spec(tmp[size - k], '\"', -1))
            tmp[size - k] = find_special(tmp[size - k], '\"');
        else if (find_spec(tmp[size - k], '\'', -1) < find_spec(tmp[size - k], '\"', -1))
            tmp[size - k] = find_special(tmp[size - k], '\'');
        i += get_string_size(&str[i]);
        k--;
    }
    return (tmp);
}

char** divid_command(char* str)
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    size = 0;
    while (str[i])
    {
        i += space_count(&str[i]);
        j = get_string_size(&str[i]);
        size++;
        i += j;
        i += space_count(&str[i]);
    }
    return (make_command(str, size));
}

//value=
char* re_make_location(char* str)
{
    int i;
    int j;
    char* tmp;

    if (!str)
        return(NULL);
    i = ft_strlen(str);
    j = find_spec(str, '=', -1);
    tmp = (char*)malloc(i + 3);
    while (j != -1)
        tmp[j--] = str[j];
    j = find_spec(str, '=', -1);
    tmp[j + 1] = '\"';
    tmp[i + 1] = '\"';
    tmp[i + 2] = '\0';
    while (i - j - 1)
        tmp[i--] = str[i - 1];
    free(str);
    return (tmp);
}

void divid_commands(char* str)
{
    int i;
    char** divided_command;
    char** current_command;

    i = 0;
    if (!str)
        return;
    divided_command = ft_split(str, ';');
    while (divided_command[i])
    {
        current_command = divid_command(divided_command[i]);
        if (!(ft_strncmp(current_command[0], "env", 3)) || !(ft_strncmp(current_command[0], "export", 3)))
            current_command[1] = re_make_location(current_command[1]);
        check_value(current_command);
        i++;
        printf("\n");
    }
}

char** get_envy_value(char** envy)
{
    char** envy_value;
    int i;

    i = 0;
    while (envy[i])
        i++;
    if (!(envy_value = (char**)malloc(sizeof(char*) * i + 1)))
        return (NULL);
    i = -1;
    while (envy[++i])
        envy_value[i] = ft_strdup(envy[i]);
    return (envy_value);
}

//1. $환경변수 
//2. env, export 추가  
int main(int argc, char* argv[], char** envy)
{
    char** tmp;
    char* input;
    char* command = "echo > \' \"$HOME \" \' \" \'$HOME \' \"  \" \'$-n \' \" \\\"abc\" c \"\"c\"abd \" abc\' \" value  ; cd value ;pwd ; export ; unset value ; env value=/root ; exit";
    g_envv = get_envy_value(envy);      //envy_value 변수에 환경변수 값을 대입
    divid_commands(command);                 //현재 ; 를 기준으로 코드를 나눔
}
