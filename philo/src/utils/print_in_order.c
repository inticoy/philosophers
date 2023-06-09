/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:01:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:09:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	print_in_order(t_table *table, t_id id, t_status status)
{
	pthread_mutex_lock(&table->mutex_print);
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
	pthread_mutex_unlock(&table->mutex_print);
}
