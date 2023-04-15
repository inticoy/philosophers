/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 15:38:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

static void	activate_philo(t_table *table)
{
	int	i;

	i = 1;
	table->time_start = get_time();
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = THINK;
		table->philos[i].time_last_eat = table->time_start;
		pthread_mutex_unlock(&table->philos[i].mutex);
		print_in_order(table, i + 1, THINK);
		i += 2;
	}
	msleep(1);
	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = THINK;
		table->philos[i].time_last_eat = table->time_start;
		pthread_mutex_unlock(&table->philos[i].mutex);
		print_in_order(table, i + 1, THINK);
		i += 2;
	}
}

static int	monitor_philo(t_table *table)
{
	int		i;
	t_bool	fulfilled;

	fulfilled = ft_false;
	while (!fulfilled)
	{
		usleep(200);
		i = 0;
		fulfilled = ft_true;
		while (i < table->manners.num_philos)
		{
			pthread_mutex_lock(&table->philos[i].mutex);
			if ((get_time() - table->philos[i].time_last_eat) \
				> table->manners.time_die)
			{
				pthread_mutex_unlock(&table->philos[i].mutex);
				return (i + 1);
			}
			if (!table->manners.has_num_eat || \
				table->philos[i].eat_count < table->manners.num_eat)
				fulfilled = ft_false;
			pthread_mutex_unlock(&table->philos[i++].mutex);
		}
	}
	return (0);
}

static void	kill_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
		pthread_mutex_lock(&table->philos[i++].mutex);
	i = 0;
	while (i < table->manners.num_philos)
	{
		table->philos[i].status = DEAD;
		pthread_mutex_unlock(&table->philos[i++].mutex);
	}
}

void	*act_admin(void *arg)
{
	t_table	*table;
	int		i_dead;

	table = (t_table *)arg;
	activate_philo(table);
	i_dead = monitor_philo(table);
	kill_philo(table);
	if (i_dead > 0)
		print_in_order(table, i_dead, DEAD);
	return (FT_NULL);
}
