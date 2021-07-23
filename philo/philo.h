/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:11:35 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/07/22 17:47:33 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define LEFT_FORK 0
# define RIGHT_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

# define RESET   "\033[0m"
# define BLACK   "\033[30m"					/* Black */
# define RED     "\033[31m"					/* Red */
# define GREEN   "\033[32m"					/* Green */
# define YELLOW  "\033[33m"					/* Yellow */
# define BLUE    "\033[34m"					/* Blue */
# define MAGENTA "\033[35m"					/* Magenta */
# define CYAN    "\033[36m"					/* Cyan */
# define WHITE   "\033[37m"					/* White */

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				eaten_meals;
	long long		last_meal_time;
	struct s_data	*data;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_meals;
	int				is_dead;
	int				all_ate;
	long long		start_time;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print;
	pthread_mutex_t	death_check;
	t_philo			philo[200];
}	t_data;

int			ft_error(int error);
int			ft_init(t_data *data, char **av);
void		ft_init_philo(t_data *data);
int			ft_init_mutex(t_data *data);
int			ft_atoi(const char *str);
int			ft_error(int error);
void		ft_check(t_data *d, t_philo *p);
long long	ft_get_time(void);
void		smart_sleep(long long time, t_data *data);
long long	time_diff(long long past, long long pres);
void		ft_print(t_data *data, t_philo *philo, int i);

#endif
