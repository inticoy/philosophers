/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 17:41:22 by gyoon            ###   ########.fr       */
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
		usleep(50);
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
			usleep(100);
			pthread_mutex_lock(&table->philos[i].mutex);
			if ((get_time() - table->philos[i].time_last_eat) \
				> table->manners.time_die)
				is_dead = ft_true;
			pthread_mutex_unlock(&table->philos[i].mutex);
			if (is_dead)
			{
				set_is_dining(table, ft_false);
				print_in_order(table, i + 1, DEAD);
				break ;
			}
			i++;
		}
	}
}

void	*act_admin(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	table->time_start = get_time();
	activate_philo(table);
	monitor_philo(table);
	return (FT_NULL);
}
