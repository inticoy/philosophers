/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:02:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 12:41:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	*manage_philo(void *arg)
{
	t_table	*table;
	t_time	last_eat;

	table = (t_table *)arg;
	while (ft_true)
	{
		usleep(100);
		sem_wait(table->philos[table->id - 1].sem);
		// printf("sem : %p\n", (table->philos[table->id - 1].sem));
		last_eat = table->philos[table->id - 1].time_last_eat;
		sem_post(table->philos[table->id - 1].sem);
		if (get_time() - last_eat > table->manners.time_die)
		{
			print_in_order(table, table->id, DEAD);
			exit(1);
		}
	}
}
