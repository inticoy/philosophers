/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:27:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/10 22:49:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

t_bool	think_philo(t_philo *philo)
{
	if (is_dead_philo(philo))
		return (ft_false);
	pthread_mutex_lock(&philo->mutex);
	philo->status = THINK;
	print_in_order(philo->table, get_time(), philo->id, THINK);
	pthread_mutex_unlock(&philo->mutex);
	usleep(100);
	return (ft_true);
}
