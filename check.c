/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:10:52 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/21 18:10:56 by fd-agnes         ###   ########.fr       */
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

void	ft_check_support(t_data *d, t_philo *p, int i)
{
	if (d->nb_meals != -1)
	{
		while (i < d->nb_philo && p[i].eaten_meals == d->nb_meals)
			i++;
	}
	if (i == d->nb_philo)
		d->all_ate = 1;
}

void	ft_check(t_data *d, t_philo *p)
{
	int	i;

	while (!(d->all_ate))
	{
		i = -1;
		while (++i < d->nb_philo && !(d->is_dead))
		{
			pthread_mutex_lock(&(d->meal_check));
			if (time_diff(p[i].last_meal_time, ft_get_time()) > d->ttd)
			{
				ft_print(d, &p[i], 5);
				d->is_dead = 1;
			}
			pthread_mutex_unlock(&(d->meal_check));
			usleep(100);
		}
		if (d->is_dead)
			break ;
		i = 0;
		ft_check_support(d, p, i);
	}
}
