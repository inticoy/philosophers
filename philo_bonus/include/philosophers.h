/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 11:55:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>

// include temp
# include <unistd.h>
# include <stdio.h>
// include temp


# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

typedef pthread_t			t_pthread;
typedef pid_t				t_pid;
typedef sem_t				t_sem;

typedef unsigned long long	t_size;
typedef struct timeval		t_timeval;
typedef long long			t_time;
typedef int					t_id;

typedef struct s_table		t_table;

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

typedef struct s_philo
{
	t_sem	*sem;

	t_pid	pid;
	t_id	id;
	int		eat_count;
	t_time	time_last_eat;
}	t_philo;

typedef struct s_manner
{
	t_time	time_die;
	t_time	time_eat;
	t_time	time_sleep;
	int		num_philos;
	t_bool	has_num_eat;
	int		num_eat;
}	t_manner;

typedef struct s_table
{
	t_sem		*sem_print;

	t_time		time_start;
	t_manner	manners;
	t_sem		*forks;
	t_philo		*philos;
	t_id		id;
}	t_table;

//		dinner
void	exec_admin(t_table *table);
void	*act_philo(void *table);
void	exec_philo(t_table *table);
void	*manage_philo(void *arg);
t_bool	have_dinner(t_table *table);

//		error
void	raise_error(char *msg);

//		table
void	del_table(t_table *table);
t_bool	set_table_manners(t_table *table, int argc, char **argv);
void	set_table(t_table *table);

//		time
t_time	get_time(void);

//		utils
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
t_size	ft_strlen(const char *s);
int		msleep(unsigned int microseconds);
void	print_in_order(t_table *table, t_id id, t_status status);

#endif