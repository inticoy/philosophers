/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:56:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

void	exec_philo(t_table *table)
{
	t_pthread	manager;
	int			errno;

	table->philo.id++;
	if (table->philo.id % 2 == 1)
		usleep(200);
	errno = pthread_create(&manager, NULL, manage_philo, table);
	if (errno)
		exit(1);
	act_philo(table);
	exit(0);
}
