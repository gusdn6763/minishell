#include "minishell.h"

void check_value(char **str)
{
    int i = 0;
    int j = 0;
    while(str[i])
    {
        printf("(%s)\n", str[i]);
        i++;
    }
}

int get_string_size(char *str, int i)
{
    int j;

    j = 0;
    while ((str[i] != ' ' || str[i] == ';') && str[i] != '\0')
    {
        i++;
        j++;
    }
    return (j);
}

int space_count(char *str)
{
    int i;

    i = 0;
    while(str[i] == ' ' && str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int check_option(char *str)
{
    int i;
    char *tmp;

    i = 0;
    tmp = ft_substr(str, 0, 3);
    if (!ft_strcmp(tmp, "-n "))
        return (1);
    return (0);
}


char **make_command(char *command, char *all, int i, int size)
{
    int j;
    char **tmp;

    j = 0;
    if (!(ft_strcmp(command, "echo")) || !(ft_strcmp(command, "cd")) || !(ft_strcmp(command, "unset")) || !(ft_strcmp(command, "env")))
    {
        size++;
        j = get_string_size(all, i);
    }
    tmp = (char **)malloc(sizeof(char *) * size + 1);
    tmp[0] = command;
    tmp[1] = ft_substr(all, i, j);
    printf("size = (%d)  command :(%s) value :(%s)",size, tmp[0], tmp[1]); 
    if(size == 3)
    {
        i += space_count(&all[i + j]);
        j = get_string_size(all, i + 2);
        tmp[2] = ft_substr(all, i + 2, j);
        printf(" option = (%s)", tmp[2]);
    }
    printf("\n");
    return (tmp);
}

char **divid_command(char *str)
{
    int i;
    int j;
    int size;
    char *command;

    i = space_count(str);
    j = get_string_size(str, i);
    printf("i = (%d)  j = (%d) ",i, j);     //주석
    size = 1;
    command = ft_substr(str, i, j);
    i += space_count(&str[i + j]);
    if (!ft_strcmp(command, "echo"))
        size += check_option(&str[i + j]);
    return (make_command(command, str, i + j, size));
}

void divid_commands(char *str)
{
    int i;
    char **divided_command;
    char **current_command;

    i = 0;
    if (!str)
        return ;
    divided_command = ft_split(str, ';');
    //check_value(divid_command);
    while(divided_command[i])
    {
        current_command = divid_command(divided_command[i++]);
    }
}

char  **get_envy_value(char **envy)
{
    char **envy_value;
    int i;

    i = 0;

    while(envy[i])
        i++;
    if (!(envy_value = (char **)malloc(sizeof(char *) * i + 1)))
        return (NULL);
    i = -1;
    while(envy[++i])
        envy_value[i] = ft_strdup(envy[i]);
    return (envy_value);
}

int main(int argc, char *argv[], char **envy)
{
    char **envy_value;
    char *input;
    char *command = "   echo -n       (value)    ;  cd value ; pwd ; export ; unset (value) ; env (value) ; exit";

    envy_value = get_envy_value(envy);      //envy_value 변수에 환경변수 값을 대입
    //check_value(envy_value);
    divid_commands(command);                 //현재 ; 를 기준으로 코드를 나눔
}