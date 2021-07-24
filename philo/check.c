/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:10:52 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/24 11:25:25 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int error)
{
	if (error == 1)
		write(2, "one or more invalid arguments\n", 30);
	if (error == 2)
		write(2, "Error during mutex initialization\n", 34);
	return (1);
}

int	ft_single_arg_check(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (-1);
	while (str[i] && str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_single_arg_check(av[i]) == 1)
			i++;
		else
			return (-1);
	}
	return (1);
}

void	ft_death_check(t_data *d, t_philo *p)
{
	int	i;
	int	j;

	while (!(d->all_ate))
	{
		i = 0;
		j = 0;
		while (i < d->nb_philo && !(d->is_dead))
		{
			pthread_mutex_lock(&(d->meal_check));
			if (time_diff(p[i].last_meal_time, ft_get_time()) > d->ttd)
			{
				ft_print(d, &p[i], DIE);
				d->is_dead = 1;
				while (j++ < d->nb_philo)
				{
					pthread_mutex_unlock(&(d->fork[p->left_fork_id]));
					pthread_mutex_unlock(&(d->fork[p->right_fork_id]));
				}
			}
			pthread_mutex_unlock(&(d->meal_check));
			i++;
		}
	}
}
