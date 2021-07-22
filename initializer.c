/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:11:02 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/22 16:25:28 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	return (0);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
		data->philo[i].eaten_meals = 0;
		data->philo[i].last_meal_time = 0;
	}
}

int	ft_init(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	data->is_dead = 0;
	data->all_ate = 0;
	if (data->nb_philo < 1 || data->nb_philo > 200 || data->ttd < 0 || \
		 data->tte < 0 || data->tts < 0 )
		return (1);
	if (av[5])
	{
		data->nb_meals = ft_atoi(av[5]);
		if (data->nb_meals <= 0)
			return (1);
	}
	else
		data->nb_meals = -1;
	if (ft_init_mutex(data))
		return (2);
	ft_init_philo(data);
	return (0);
}
