/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:05:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 23:49:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	grab_philo(t_table *table)
{
	sem_wait(table->forks);
	print_in_order(table, table->philo.id, GRAB);
	// print_in_order(table, *table->forks, THINK);
	sem_wait(table->forks);
	print_in_order(table, table->philo.id, GRAB);
}

static void	eat_philo(t_table *table)
{
	print_in_order(table, table->philo.id, EAT);
	msleep(table->manners.time_eat);
	sem_post(table->forks);
	sem_post(table->forks);
}

static void	sleep_philo(t_table *table)
{
	print_in_order(table, table->philo.id, SLEEP);
	msleep(table->manners.time_sleep);
}

static void	think_philo(t_table *table)
{
	print_in_order(table, table->philo.id, THINK);
}

void	act_philo(t_table *table)
{
	while (ft_true)
	{
		grab_philo(table);
		eat_philo(table);
		// if (table->philo.eat_count == table->manners.num_eat)
		// 	return ;
		sleep_philo(table);
		think_philo(table);
	}
}
