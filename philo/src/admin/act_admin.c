/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:16:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 12:13:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

static void	activate_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->manners.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].mutex);
		table->philos[i].status = THINK;
		pthread_mutex_unlock(&table->philos[i].mutex);
		i++;
	}
}

static void	monitor_philo(t_table *table)
{
	
}

void	*act_admin(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;

	table->time_start = get_time();
	activate_philo(table);
	monitor_philo(table);
	return (table);
}
