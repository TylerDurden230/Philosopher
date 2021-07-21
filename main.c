/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:11:13 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/21 18:11:15 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->left_fork_id]));
	ft_print(data, philo, 0);
	if (philo->data->nb_philo == 1)
	{
		smart_sleep(philo->data->ttd, philo->data);
		ft_check(philo->data, philo);
		pthread_mutex_unlock(&(data->fork[philo->left_fork_id]));
		return ;
	}
	pthread_mutex_lock(&(data->fork[philo->right_fork_id]));
	ft_print(data, philo, 1);
	pthread_mutex_lock(&(data->meal_check));
	ft_print(data, philo, 2);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&(data->meal_check));
	smart_sleep(data->tte, data);
	(philo->eaten_meals)++;
	pthread_mutex_unlock(&(data->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork_id]));
}

void	*thread(void *void_philosopher)
{
	int			i;
	t_philo		*philo;
	t_data		*data;

	i = 0;
	philo = (t_philo *)void_philosopher;
	data = philo->data;
	if (philo->id % 2)
		usleep(1500);
	while (!(data->is_dead))
	{
		ft_eat(philo);
		if (data->all_ate || data->is_dead)
			break ;
		ft_print(data, philo, 3);
		smart_sleep(data->tts, data);
		ft_print(data, philo, 4);
		i++;
	}
	return (NULL);
}

void	ft_finish(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->fork[i]));
	pthread_mutex_destroy(&(data->print));
}

int	ft_start(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	data->start_time = ft_get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, thread, &(philo[i])))
			return (1);
		philo[i].last_meal_time = ft_get_time();
		i++;
	}
	ft_check(data, data->philo);
	ft_finish(data, philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		err;

	err = 0;
	if (ac < 5 || ac > 6)
		write(1, "Error: Wrong number of arguments\n", 33);
	err = ft_init(&data, av);
	if (err)
		return (ft_error(err));
	if (ft_start(&data))
		write(1, "Error: Something gone wrong\n", 28);
	return (0);
}
