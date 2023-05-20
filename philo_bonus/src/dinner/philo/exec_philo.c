/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:56:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 23:55:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	exec_philo(t_table *table)
{
	// t_pthread	manager;
	// int			errno;

	table->philo.id++;
	if (table->philo.id % 2 == 1)
		msleep(1);
	// errno = pthread_create(&manager, NULL, manage_philo, table);
	// if (errno)
	// 	exit(1);
	act_philo(table);
	exit(0);
}
