/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/11 15:39:45 by gyoon            ###   ########.fr       */
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
		i++;
		i++;
	}
	usleep(2000);
	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = THINK;
		table->philos[i].time_last_eat = table->time_start;
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
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
		usleep(200);
		i = 0;
		while (i < table->manners.num_philos)
		{
			pthread_mutex_lock(&table->philos[i].mutex);
			if ((get_time() - table->philos[i].time_last_eat) \
				> table->manners.time_die)
			{
				is_dead = ft_true;
				print_in_order(table, i + 1, DEAD);
				pthread_mutex_unlock(&table->philos[i].mutex);
				break ;
			}
			pthread_mutex_unlock(&table->philos[i].mutex);
			i++;
		}
	}
	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = DEAD;
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
	}
}

void	*act_admin(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	activate_philo(table);
	monitor_philo(table);
	return (FT_NULL);
}
