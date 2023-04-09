/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 15:11:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

static void	activate_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = THINK;
		table->philos[i].time_last_eat = table->time_start;
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
	}
}

static void	monitor_philo(t_table *table)
{
	t_bool	is_dead;
	int		i;

	is_dead = ft_false;
	while (!is_dead)
	{
		usleep(100);
		i = 0;
		while (i < table->manners.num_philos)
		{
			pthread_mutex_lock(&table->philos[i].mutex);
			if (get_time() - table->philos[i].time_last_eat \
				> table->manners.time_die)
			{
				print_in_order(&table->mutex_print, table->time_start, i + 1, DEAD);
				is_dead = ft_true;
			}
			i++;
		}
		if (!is_dead)
		{
			i = 0;
			while (i < table->manners.num_philos)
			{
				pthread_mutex_unlock(&table->philos[i].mutex);
				i++;
			}
		}
	}
	i = 0;
	while (i < table->manners.num_philos)
	{
		table->philos[i].status = DEAD;
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
	}
}

void	*act_admin(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;

	table->time_start = get_time();
	activate_philo(table);
	monitor_philo(table);
	return (table);
}
