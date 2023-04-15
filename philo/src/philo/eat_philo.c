/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/15 17:28:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

t_bool	eat_philo(t_philo *philo)
{
	if (is_dead_philo(philo))
		return (ft_false);
	pthread_mutex_lock(&philo->mutex);
	philo->status = EAT;
	philo->time_last_eat = get_time();
	philo->eat_count++;
	print_in_order(philo->table, philo->id, EAT);
	pthread_mutex_unlock(&philo->mutex);
	msleep(philo->table->manners.time_eat);
	drop_fork(philo, LEFT);
	drop_fork(philo, RIGHT);
	return (ft_true);
}
