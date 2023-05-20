/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:02:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/20 22:22:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	*manage_philo(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (ft_true)
	{
		usleep(100);
		if (get_time() - table->philo.time_last_eat > table->manners.time_die)
		{
			print_in_order(table, table->philo.id, DEAD);
			exit(1);
		}
	}
}
