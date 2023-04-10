/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 16:02:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>

# ifndef FT_NULL
#  define FT_NULL 0
# endif

typedef unsigned long long	t_size;

typedef struct timeval		t_timeval;
typedef long long			t_time;
typedef int					t_id;

typedef pthread_t			t_pthread;
typedef pthread_mutex_t		t_mutex;

enum e_file_descriptor
{
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2
};

typedef enum e_philosopher_status
{
	READY = -1,
	DEAD = 0,
	EAT = 1,
	THINK = 2,
	SLEEP = 3,
	GRAB = 4
}	t_status;

typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1,
}	t_bool;

typedef struct s_fork
{
	t_mutex	mutex;

	t_id	owner;
}	t_fork;

typedef struct s_philo
{
	t_mutex		mutex;

	t_table		*table;

	t_id		id;
	t_status	status;
	int			eat_count;
	t_time		time_last_eat;
	t_fork		*left;
	t_fork		*right;
}	t_philo;

typedef struct s_manner
{
	t_time	time_die;
	t_time	time_eat;
	t_time	time_sleep;
	int		num_eat;
	int		num_philos;
}	t_manner;

typedef struct s_table
{
	t_mutex		mutex_print;
	t_mutex		mutex_dining;

	t_bool		is_dining;
	t_time		time_start;
	t_manner	manners;
	t_pthread	*threads;
	t_philo		*philos;
	t_fork		*forks;
}	t_table;

//		admin
void	*act_admin(void *arg);

//		error
void	raise_error(char *msg);

//		fork
t_bool	set_forks(t_table *table);

//		philo
void	*act_philo(void *arg);
t_bool	eat_philo(t_philo *philo);
t_bool	grab_philo(t_philo *philo);
t_bool	is_dead_philo(t_philo *philo);
t_bool	set_philos(t_table *table);
t_bool	sleep_philo(t_philo *philo);
t_bool	think_philo(t_philo *philo);

//		table
t_bool	set_table_manners(t_table *table, int argc, char **argv);

//		thread
void	set_threads(t_table *table);
void	create_threads(t_table *table);
void	await_threads(t_table *table);
void	detach_threads(t_table *table);

//		time
t_time	get_time(void);

//		utils
void	print_in_order(t_mutex *mutex, t_time start, t_id id, t_status status);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
t_size	ft_strlen(const char *s);
int		msleep(unsigned int microseconds);

#endif