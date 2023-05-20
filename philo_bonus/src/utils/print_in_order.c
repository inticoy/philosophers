/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:19:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 23:43:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	print_in_order(t_table *table, t_id id, t_status status)
{
	sem_wait(table->sem_print);
	if (status == GRAB)
	{
		printf("%lld %d has taken a fork\n", get_time() - table->time_start, id);
		printf("%lld %d has taken a fork\n", get_time() - table->time_start, id);
	}
	else if (status == EAT)
		printf("%lld %d is eating\n", get_time() - table->time_start, id);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", get_time() - table->time_start, id);
	else if (status == THINK)
		printf("%lld %d is thinking\n", get_time() - table->time_start, id);
	else if (status == DEAD)
		printf("%lld %d died\n", get_time() - table->time_start, id);
	sem_post(table->sem_print);
}
