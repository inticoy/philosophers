/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:56:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 23:53:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_table(t_table *table)
{
	sem_unlink("/sem/print");
	table->sem_print = sem_open("/sem/print", O_CREAT, 0644, 1);
	table->time_start = get_time();
	sem_unlink("/sem/forks");
	table->forks = sem_open("/sem/forks", O_CREAT, 0644, table->manners.num_philos);
	table->philo.id = 0;
	table->philo.eat_count = 0;
	table->philo.time_last_eat = table->time_start;
}
