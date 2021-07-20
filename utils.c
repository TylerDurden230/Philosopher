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

void	ft_print(t_data *data, int id, char *string)
{
	pthread_mutex_lock(&(data->print));
	if (!(data->is_dead))
	{
		printf("%lli ", ft_get_time() - data->start_time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->print));
	return ;
}
