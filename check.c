#include "philo.h"

int	ft_error(int error)
{
	if (error == 1)
		write(2, "one or more invalid arguments\n", 30);
	if (error == 2)
		write(2, "Error during mutex initialization\n", 34);
	return (1);
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
				ft_print(d, i, "died");
				d->is_dead = 1;
			}
			pthread_mutex_unlock(&(d->meal_check));
			usleep(100);
		}
		if (d->is_dead)
			break ;
		i = 0;
		if (d->nb_meals != -1)
		{
			while (i < d->nb_philo && p[i].eaten_meals == d->nb_meals)
				i++;
		}
		if (i == d->nb_philo)
			d->all_ate = 1;
	}
}

