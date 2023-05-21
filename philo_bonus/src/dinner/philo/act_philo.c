/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:05:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 13:04:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	grab_philo(t_table *table);
static void	eat_philo(t_table *table);
static void	sleep_philo(t_table *table);
static void	think_philo(t_table *table);
void		*act_philo(void *arg);

#include <stdlib.h>

static void	new_sleep(t_table *table, unsigned int microseconds)
{
	t_time	start;
	int		i;

	start = get_time();
	i = 0;
	while (i < 1000)
	{
		if (get_time() - start >= microseconds)
			break ;
		if (get_time() - table->philos[table->id].time_last_eat > table->manners.time_die)
			exit(1);
		usleep(microseconds);
		i++;
	}
}

void	*act_philo(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (ft_true)
	{
		grab_philo(table);
		eat_philo(table);
		if (table->manners.has_num_eat && \
			table->philos[table->id - 1].eat_count >= table->manners.num_eat)
			break ;
		sleep_philo(table);
		think_philo(table);
	}
	return (0);
}

static void	grab_philo(t_table *table)
{
	sem_wait(table->forks);
	sem_wait(table->forks);
	print_in_order(table, table->id, GRAB);
}

static void	eat_philo(t_table *table)
{
	print_in_order(table, table->id, EAT);
	table->philos[table->id - 1].eat_count++;
	sem_wait(table->philos[table->id - 1].sem);
	table->philos[table->id - 1].time_last_eat = get_time();
	sem_post(table->philos[table->id - 1].sem);
	new_sleep(table, table->manners.time_eat);
	sem_post(table->forks);
	sem_post(table->forks);
}

static void	sleep_philo(t_table *table)
{
	print_in_order(table, table->id, SLEEP);
	new_sleep(table, table->manners.time_sleep);
}

static void	think_philo(t_table *table)
{
	print_in_order(table, table->id, THINK);
}
