/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:56:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 12:58:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	exec_philo(t_table *table)
{
	// t_pthread	manager;
	// t_pthread	philo;
	// char		*number;
	// char		*sem_name;

	// number = ft_itoa(table->id);
	// sem_name = ft_strjoin("/sem/", number);
	// free(number);
	// sem_unlink(sem_name);
	// printf("%s name\n", sem_name);
	// table->philos[table->id - 1].sem = sem_open(sem_name, O_CREAT, 0644, 1);
	// free(sem_name);
	if (table->id % 2 == 1)
		usleep(500);
	// pthread_create(&manager, 0, manage_philo, table);
	// pthread_create(&philo, 0, act_philo, table);
	// pthread_join(manager, 0);
	// pthread_join(philo, 0);
	act_philo(table);
	exit(0);
}
