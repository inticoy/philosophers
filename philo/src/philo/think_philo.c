/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:27:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/09 14:48:27 by gyoon            ###   ########.fr       */
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
	pthread_mutex_unlock(&philo->mutex);
	print_in_order(philo->mutex_print, *philo->time_start, philo->id, THINK);
	usleep(100);
	return (ft_true);
}
