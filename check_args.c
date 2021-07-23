#include <stdio.h>
#include <stdlib.h>

int ft_single_arg_check(const char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != 0)
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
            i++;
        if(str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    return (1);
}

int ft_check_args(int ac, char **av)
{
    int flag;
    int i;

    i = 1;
    while (i < ac)
    {
        if(ft_single_arg_check(av[i]) == 1)
            i++;
        else
        {
            flag = 1;
            break ;
        }
    }
    if (flag == 1)
        return (-1);
    else
        return (1);
}

int main (int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        printf("Error: Invalid number of args\n");
        return (-1);
    }
    if (ft_check_args(ac, av) == 1)
    {
        printf("Eseguo il programma\n");
        return(0);
    }
    else
    {
        printf("One or more invalid Arguments\n");
        return (-1);
    }
}