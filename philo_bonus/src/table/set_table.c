/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:56:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/20 21:02:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	set_table(t_table *table)
{
	const int	num_philos = table->manners.num_philos;

	sem_unlink("/sem/print");
	table->sem_print = sem_open("/sem/print", O_CREAT, 0644, 1);
	table->time_start = get_time();
	sem_unlink("/sem/forks");
	table->forks = sem_open("/sem/forks", O_CREAT, 0644, num_philos);
	table->philos = (t_pid *)malloc(num_philos * sizeof(t_pid));
	table->philo.id = 0;
	table->philo.eat_count = 0;
	table->philo.time_last_eat = table->time_start;
}
