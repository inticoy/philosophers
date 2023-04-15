/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 14:27:17 by gyoon            ###   ########.fr       */
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

static int	detect_dead_philo(t_table *table)
{
	int		i;
	int		i_dead;

	i_dead = 0;
	while (i_dead <= 0)
	{
		usleep(200);
		i = 0;
		while (i < table->manners.num_philos)
		{
			pthread_mutex_lock(&table->philos[i].mutex);
			if ((get_time() - table->philos[i].time_last_eat) \
				> table->manners.time_die)
			{
				i_dead = i + 1;
				pthread_mutex_unlock(&table->philos[i].mutex);
				break ;
			}
			pthread_mutex_unlock(&table->philos[i].mutex);
			i++;
		}
	}
	return (i_dead);
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
	i_dead = detect_dead_philo(table);
	kill_philo(table);
	print_in_order(table, i_dead, DEAD);
	return (FT_NULL);
}
