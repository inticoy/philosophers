/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:02:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

void	*manage_philo(void *arg)
{
	t_table	*table;
	t_time	now;
	t_time	last;

	table = (t_table *)arg;
	while (ft_true)
	{
		usleep(200);
		sem_wait(table->times[table->philo.id - 1]);
		now = get_time();
		last = (table->philo.time_last_eat.tv_sec * 1000) \
				+ (table->philo.time_last_eat.tv_usec / 1000);
		if (now - last > table->manners.time_die)
		{
			print_in_order(table, table->philo.id, DEAD);
			exit(1);
		}
		sem_post(table->times[table->philo.id - 1]);
	}
}
