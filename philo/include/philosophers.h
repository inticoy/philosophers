/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/06 14:59:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

# ifndef FT_NULL
#  define FT_NULL 0
# endif

typedef unsigned long long	t_size;
typedef int					t_id;
typedef long long			t_time;

enum e_file_descriptor
{
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2
};

typedef enum e_philosopher_status
{
	DEAD = 0,
	EAT = 1,
	THINK = 2,
	SLEEP = 3
}	t_status;

typedef enum e_bool
{
	ft_false = 0,
	ft_true = 1,
}	t_bool;

typedef struct s_manner
{
	t_time	time_die;
	t_time	time_eat;
	t_time	time_sleep;
	int		num_eat;
	int		num_philos;
}	t_manner;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	t_id			owner;
}	t_fork;

typedef struct s_philo
{
	pthread_mutex_t	mutex;
	t_status		status;
	t_id			id;
	int				num_eat;
	t_fork			*left;
	t_fork			*right;
	t_manner		*manners;
}	t_philo;

typedef struct s_table
{
	t_time		time_start;
	t_manner	manners;
	pthread_t	*threads;
	t_philo		*philos;
	t_fork		*forks;
}	t_table;

//		error
void	raise_error(char *msg);

//		fork
t_bool	set_forks(t_table *table);

//		philosopher
void	*act_philo(void *arg);
t_bool	set_philos(t_table *table);

//		table
t_bool	set_table_manners(t_table *table, int argc, char **argv);

//		thread
void	create_threads(t_table *table);
void	await_threads(t_table *table);
void	detach_threads(t_table *table);

//		utils
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
t_size	ft_strlen(const char *s);

#endif