/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:11:26 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/21 18:11:28 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}

long long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_data *data)
{
	long long	i;

	i = ft_get_time();
	while (!(data->is_dead))
	{
		if (time_diff(i, ft_get_time()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_print(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&(data->print));
	if (!(data->is_dead))
	{
		printf("%lli ", ft_get_time() - data->start_time);
		printf("Philosopher %i ", philo->id);
		if (i == 0)
			printf("has taken the left fork %d\n", philo->left_fork_id);
		else if (i == 1)
			printf("has taken the right fork %d\n", philo->right_fork_id);
		else if (i == 2)
		{
			printf(YELLOW "is eating\n" RESET);
			
		}
		else if (i == 3)
			printf(CYAN "is sleeping\n" RESET);
		else if (i == 4)
			printf("is thinking\n");
		else if (i == 5)
			printf(RED "is dead\n" RESET);
	}
	pthread_mutex_unlock(&(data->print));
	return ;
}
