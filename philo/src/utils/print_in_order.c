/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:01:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 22:49:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_in_order(t_table *table, t_time now, t_id id, t_status status)
{
	pthread_mutex_lock(&table->mutex_print);
	if (status == GRAB)
		printf("%lld %d has taken a fork\n", now - table->time_start, id);
	else if (status == EAT)
		printf("%lld %d is eating\n", now - table->time_start, id);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", now - table->time_start, id);
	else if (status == THINK)
		printf("%lld %d is thinking\n", now - table->time_start, id);
	else if (status == DEAD)
		printf("%lld %d died\n", now - table->time_start, id);
	pthread_mutex_unlock(&table->mutex_print);
}
